#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color{white, gray, black} Color;

map<int, vector<int> > Graph, GraphT;
map<int, vector<int> >::iterator graphIter;
map<int, Color> color;
map<int, int> ancestor;
vector< pair<int, int> > discoveryTime, finishTime;

int Time = 0, SCC = 0;

void initVertex (map<int, vector<int> > & graph, int orig, int dest, int P) {
	graph[orig].push_back(dest);
	graph[dest];
    if (P == 2) {
        graph[dest].push_back(orig);
    }
    color[orig] = color[dest] = white;
}

bool comparison (pair<int, int>& left, pair<int, int>& right) {
    return left.second >= right.second;
}

void sortTime () {

    std::sort(finishTime.begin(), finishTime.end(), comparison);

}

void dfsVisit (map<int, vector<int> > & graph, int current) {
    int adjacent;

    discoveryTime.push_back(make_pair(current, ++Time));
    color[current] = gray;

    for (int i = 0; i < graph[current].size(); i++) {
        adjacent = graph[current][i];
        if (color[adjacent] == white) {
            ancestor[adjacent] = current;
            dfsVisit(graph, adjacent);
        }
    }
    color[current] = black;
    finishTime.push_back(make_pair(current, ++Time));
}

void dfsGTVisit (map<int, vector<int> > & graph, int current) {
    int adjacent;

    discoveryTime.push_back(make_pair(current, ++Time));
    color[current] = gray;

    for (int i = 0; i < graph[current].size(); i++) {
        adjacent = graph[current][i];
        if (color[adjacent] == white) {
            ancestor[adjacent] = current;
            dfsGTVisit(graph, adjacent);
        }
    }
    color[current] = black;
}

void dfsGT (map<int, vector<int> > & graph) {

    for (graphIter = graph.begin() ; graphIter != graph.end(); graphIter++) {
        color[graphIter->first] = white;
        ancestor[graphIter->first] = NIL;
    }

    for (auto& vertexPair : finishTime) {
        // std::cout << "nova arvore em: " << vertexPair.first << " time: " << vertexPair.second << std::endl;
        if (color[vertexPair.first] == white) {
            SCC++;
            dfsGTVisit(graph, graphIter->first);
        }
    }
}

void dfs (map<int, vector<int> > & graph) {

    for (graphIter = graph.begin() ; graphIter != graph.end(); graphIter++) {
        color[graphIter->first] = white;
        ancestor[graphIter->first] = NIL;
    }

    for (graphIter = graph.begin() ; graphIter != graph.end(); graphIter++) {
        if (color[graphIter->first] == white) {
            dfsVisit(graph, graphIter->first);
        }
    }
}

int main() {
	int stations, lines, orig, dest, P;

	while ((cin >> stations >> lines) && stations) {

        Time = SCC = 0;
        ancestor.clear();
        discoveryTime.clear();
        finishTime.clear();
        color.clear();
        Graph.clear();
        GraphT.clear();

        for (int i = 1; i <= lines; i++) {
            cin >> orig >> dest >> P;
            initVertex(Graph, orig, dest, P);
            initVertex(GraphT, dest, orig, P);
        }

        dfs(Graph);
        sortTime();
        dfsGT(GraphT);

        if (SCC > 1) {
            std::cout << "0" << std::endl;
        } else {
            std::cout << "1" << std::endl;
        }
    }

	return 0;
}
