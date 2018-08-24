#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <string>

#define MAX_TASKS 50001
#define INFINITE 999999
#define NIL "0000"

using namespace std;

typedef enum Color {white, gray, black} Color;

map<string, vector<string> > Graph;
map<string, vector<string> >::iterator graphIter, tmpGraphIter;
map<string, int> finishTime, beginTime;
map<string, Color> color;
map<string, string> ancestor;
set<string> List;

int globalTime = 0;

void dfsVisit (string current) {
    string adjacent;
    bool result = true;

    beginTime[current] = globalTime++;
    color[current] = gray;
    List.insert(current);

    for (int i = 0; i < Graph[current].size(); i++) {
        adjacent = Graph[current][i];
        if (color[adjacent] == white) {
            List.insert(adjacent);
            ancestor[adjacent] = current;
            dfsVisit(adjacent);
        }
    }

    color[current] = black;
    finishTime[current] = globalTime++;
}

void dfs () {

    for (graphIter = Graph.begin(); graphIter != Graph.end(); graphIter++) {
        color[graphIter->first] = white;
        finishTime[graphIter->first] = 0;
        ancestor[graphIter->first] = NIL;
    }

    int gr = 0, tl = 0, s = 0, p = 0;
    for (graphIter = Graph.begin(); graphIter != Graph.end(); graphIter++) {
        if (color[graphIter->first] == white) {
            List.clear();
            dfsVisit(graphIter->first);
            p = List.size();
        }
        gr = std::max(gr, p);
    }
    std::cout << gr << std::endl;
}

int main() {

    string orig, dest;
    int creatures, relationships;

    while ((cin >> creatures >> relationships) && creatures) {

        for (int i = 0; i < creatures; i++) {
            cin >> orig;
            Graph[orig];
        }

        for (int i = 0; i < relationships; i++) {
            cin >> dest >> orig;
            Graph[orig].push_back(dest);
            Graph[dest].push_back(orig);
        }

        dfs();

        Graph.clear();
        color.clear();
        finishTime.clear();
        ancestor.clear();
    }

	return 0;
}
