#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

#define MAX_TASKS 50001
#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color {white, gray, black} Color;
typedef vector< vector<int> > Graph;

Graph G;
Graph::iterator graphIter, tmpGraphIter;
map<int, int> finishTime, beginTime, leastAncestorTime;
map<int, Color> color;
map<int, int> ancestor;

int globalTime = 0;

set<int> Answer;

void dfsVisit (int current) {
    int adjacent, children = 0;

    leastAncestorTime[current] = beginTime[current] = globalTime++;
    color[current] = gray;

    for (int i = 0; i < G[current].size(); i++) {
        adjacent = G[current][i];
        if (color[adjacent] == white) {
            children++;
            ancestor[adjacent] = current;
            dfsVisit(adjacent);
            leastAncestorTime[current] = std::min(leastAncestorTime[current], leastAncestorTime[adjacent]);

            if (ancestor[current] == NIL && children > 1) {
                Answer.insert(current);
            }

            if (ancestor[current] != NIL && leastAncestorTime[adjacent] >= beginTime[current]) {
                Answer.insert(current);
            }
        } else if (adjacent != ancestor[current]) {
            leastAncestorTime[current] = std::min(leastAncestorTime[current], beginTime[adjacent]);
        }
    }

    color[current] = black;
    finishTime[current] = globalTime++;
}

void dfs () {

    for (int i = 0; i < G.size(); i++) {
        color[i] = white;
        beginTime[i] = 0;
        finishTime[i] = 0;
        leastAncestorTime[i] = 0;
        ancestor[i] = NIL;
    }

    for (int i = 0; i < G.size(); i++) {
        if (color[i] == white) {
            dfsVisit(i);
        }
    }
}

int main() {

    int orig, dest, computers, links, test = 0;

    while ((cin >> computers >> links) && computers) {
        globalTime = 0;
        G.clear();
        color.clear();
        finishTime.clear();
        ancestor.clear();
        Answer.clear();
        G.resize(computers);

        for (int i = 0; i < links; i++) {
            cin >> orig >> dest;
            orig--; dest--; //Os computadores são identificados por números de 1 a N.
            G[orig].push_back(dest);
            G[dest].push_back(orig);
        }

        dfs();

        std::cout << "Teste " << ++test << std::endl;
        if (Answer.size() > 0 ) {
            for (auto& edge : Answer) {
                std::cout << edge+1 << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "nenhum" << std::endl;
        }
        std::cout << std::endl;
    }

	return 0;
}
