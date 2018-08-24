#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <utility>

#define MAX_TASKS 50001
#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color {white, gray, black} Color;
typedef vector< vector<int> > Graph;

Graph G, GT;
Graph::iterator graphIter, tmpGraphIter;
vector<int> components;
map<int, int> finishTime, beginTime;
map<int, Color> color;
map<int, int> ancestor;

int globalTime = 0;

bool comparison (int lhs, int rhs) {
    return finishTime[rhs] < finishTime[lhs];
}

// struct comparison {
//     bool operator() (const int& lhs, const int& rhs) const {
//         return finishTime[rhs] < finishTime[lhs];
//     }
// };


// set<int, comparison> List;
list<int> List;

void dfsVisit (Graph& graph, int current) {
    int adjacent;

    beginTime[current] = globalTime++;
    color[current] = gray;
    // std::cout << "visitando: " << current << std::endl;

    for (int j = 0; j < graph[current].size(); j++) {
        adjacent = graph[current][j];
        if (color[adjacent] == white) {
            ancestor[adjacent] = current;
            dfsVisit(graph, adjacent);
        }
    }

    color[current] = black;
    finishTime[current] = globalTime++;
    List.push_front(current);
    // List.insert(current);
    // std::cout << "finalzado: " << current << std::endl;
}

void dfsVisitM (Graph& graph, int current, int index) {
    int adjacent;

    beginTime[current] = globalTime++;
    color[current] = gray;
    components[current] = index;

    for (int j = 0; j < graph[current].size(); j++) {
        adjacent = graph[current][j];
        if (color[adjacent] == white) {
            ancestor[adjacent] = current;
            dfsVisitM(graph, adjacent, index);
        }
    }

    color[current] = black;
    finishTime[current] = globalTime++;
    // List.insert(current);
}

void dfs (Graph& g, int pages) {

    for (int i = 0; i < pages; i++) {
        color[i] = white;
        beginTime[i] = 0;
        finishTime[i] = 0;
        ancestor[i] = NIL;
    }

    for (int i = 0; i < pages; i++) {
        if (color[i] == white) {
            dfsVisit(g, i);
        }
    }
}

void dfsM (Graph& g, int pages) {

    for (int i = 0; i < pages; i++) {
        color[i] = white;
        beginTime[i] = 0;
        finishTime[i] = 0;
        components[i] = INFINITE;
        ancestor[i] = NIL;
    }

    for (auto& element : List) {
        if (color[element] == white) {
            // std::cout << "********" << element << std::endl;
            dfsVisitM(g, element, element);
        }
    }
}

int main() {

    int orig, dest;
    int pages, links;

    while ((cin >> pages >> links) && pages) {
        G.clear();
        GT.clear();
        components.clear();
        G.resize(pages);
        GT.resize(pages);
        components.resize(pages);

        for (int i = 0; i < links; i++) {
            cin >> orig >> dest;
            G[orig].push_back(dest);
            GT[dest].push_back(orig);
        }

        dfs(G, pages);
        List.sort(comparison);
        dfsM(GT, pages);

        for (int i = 0; i < pages; i++) {
            std::cout << components[i] << std::endl;
        }
    }

	return 0;
}
