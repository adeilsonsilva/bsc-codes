#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color{white, gray, black} Color;

vector< vector<int> > Graph, GraphT;
vector< vector<int> >::iterator graphIter;
vector<int> dist;
set<int> List;

void bfs (int start, int maxToll)
{
	int adjacent;
	queue<int> Queue;
    vector<Color> color;

    color.resize(Graph.size(), white);

    dist[start] = 0;
	Queue.push(start);

	while (!Queue.empty()) {
		int current = Queue.front();
		Queue.pop();

		for (int i = 0; i < Graph[current].size(); i++) {
			adjacent = Graph[current][i];
			if (color[adjacent] == white) {
				color[adjacent] = gray;
                dist[adjacent] = dist[current] + 1;
				Queue.push(adjacent);

                if (dist[adjacent] <= maxToll && adjacent != start) {
                    List.insert(adjacent);
                }
			}
		}
        color[current] = black;
	}

    for (auto& element : List) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
	int cities, roads, start, maxToll, test = 0, orig, dest;

	while ((cin >> cities >> roads >> start >> maxToll) && cities) {
        Graph.clear();
        dist.clear();
        List.clear();
        Graph.resize(cities + 1);
        dist.resize(cities + 1);

        for (int i = 0; i < roads; i++) {
            cin >> orig >> dest;
            Graph[orig].push_back(dest);
            Graph[dest].push_back(orig);
        }

        std::cout << "Teste " << ++test << std::endl;
        bfs(start, maxToll);
        std::cout << std::endl;
    }

	return 0;
}
