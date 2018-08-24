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
map<int, vector<int> >::reverse_iterator reverseGraphIter;
map<int, Color> color;

void initVertex (map<int, vector<int> > & graph, int orig, int dest) {
	graph[orig].push_back(dest);
    graph[dest].push_back(orig);
    color[orig] = color[dest] = white;
}

void dfs (map<int, vector<int> > & graph, int current) {
    int adjacent;

    color[current] = gray;
    for (int i = 0; i < graph[current].size(); i++) {
        adjacent = graph[current][i];
        if (color[adjacent] == white) {
            dfs(graph, adjacent);
        }
    }
    color[current] = black;
}

bool connected (int stations) {
    for (int i = 1; i <= stations; i++) {
        if (color[i] == white) {
            return false;
        }
    }
    return true;
}

int main() {
	int stations, lines, orig, dest, test = 1;

	while ((cin >> stations >> lines) && stations) {

        color.clear();
        Graph.clear();

        for (int i = 1; i <= lines; i++) {
            cin >> orig >> dest;
            initVertex(Graph, orig, dest);
        }

        std::cout << "Teste " << test++ << std::endl;

        graphIter = Graph.begin();
        dfs(Graph, graphIter->first);

        if (connected(stations)) {
            std::cout << "normal" << std::endl;
        } else {
            std::cout << "falha" << std::endl;
        }
        std::cout << std::endl;
    }

	return 0;
}
