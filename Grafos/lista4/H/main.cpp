#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <string>

#define MAX_TASKS 50001
#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color {white, gray, black} Color;

map<string, vector<string> > Graph;
map<string, vector<string> >::iterator graphIter;
map<string, int> finishTime, beginTime;
map<string, Color> color;
list<string> List;

int globalTime = 0;

bool dfsVisit (string current, int friends) {
    string adjacent;
    bool result = true;

    beginTime[current] = globalTime++;
    color[current] = gray;

    for (int i = 0; i < Graph[current].size(); i++) {
        adjacent = Graph[current][i];
        if (color[adjacent] == white) {
            result = dfsVisit(adjacent, friends);
        } else if (color[adjacent] == gray) {
            result = false;
        }
    }

    if (result) {
        color[current] = black;
        List.push_front(current);
        finishTime[current] = globalTime++;
        return true;
    }

    return false;
}

void dfs (int friends) {

    for (graphIter = Graph.begin(); graphIter != Graph.end(); graphIter++) {
        color[graphIter->first] = white;
        finishTime[graphIter->first] = 0;
    }

    for (graphIter = Graph.begin(); graphIter != Graph.end(); graphIter++) {
        if (color[graphIter->first] == white) {
            if (!dfsVisit(graphIter->first, friends)) {
                std::cout << "impossivel" << std::endl;
                return;
            }
        }
    }

    for (auto element : List) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {

    string name, orig;
    int friends, adjacents, tests = 1;

    while ((cin >> friends) && friends) {

        for (int i = 0; i < friends; i++) {
            cin >> name;
            Graph[name];
        }


        for (int i = 0; i < friends; i++) {
            cin >> name >> adjacents;
            for (int j = 0; j < adjacents; j++) {
                cin >> orig;
                Graph[orig].push_back(name);
            }
        }

        std::cout << "Teste " << tests++ << std::endl;
        dfs(friends);
        std::cout << std::endl;

        Graph.clear();
        color.clear();
        finishTime.clear();
        List.clear();
    }

	return 0;
}
