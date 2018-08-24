#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define INFINITE 999999999
#define MAX_CITIES 1010

typedef std::pair<int, int> edge;

std::vector<edge> Edges;

int Graph[MAX_CITIES][MAX_CITIES];
int cities = 0, roads = 0;

bool BellmanFord(int orig, int dest, int cities)
{
    int current = 0, distance[cities];
    bool visited[cities];

    for (int i = 0; i < cities; i++) {
        distance[i] = INFINITE;
        visited[i] = false;
    }
    distance[orig] = 0;

    for (int i = 0; i < cities; i++) {
        for (auto Edge : Edges) {
            int u = Edge.first;
            int v = Edge.second;
            if (distance[v] > distance[u] + Graph[u][v]) {
                distance[v] = distance[u] + Graph[u][v];
            }
        }

        for (auto Edge : Edges) {
            int u = Edge.first;
            int v = Edge.second;
            if (distance[v] > distance[u] + Graph[u][v]) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int cases = 0;
    std::cin >> cases;

    for (int k = 0; k < cases; k++) {

        std::cin >> cities >> roads;
        Edges.resize(roads);

        for (int i = 0; i < cities; i++) {
            for (int j = 0; j < cities; j++) {
                Graph[i][j] = i == j ? 0 : INFINITE;
            }
        }

        for (int i = 0; i < roads; i++) {
            int orig = 0, dest = 0, cost = 0;
            std::cin >> orig >> dest >> cost;
            Graph[orig][dest] = cost;
            Edges.push_back(std::make_pair(orig, dest));
        }

        if (!BellmanFord(0, cities - 1, cities)) {
            std::cout << "possible" << std::endl;
        } else {
            std::cout << "not possible" << std::endl;
        }

        Edges.clear();
    }

    return 0;
}
