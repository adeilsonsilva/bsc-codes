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

vector< vector<int> > Graph, GraphT;
vector< vector<int> >::iterator graphIter;

bool bfs (int current) {
	int adjacent;
	queue<int> Queue;
    vector<Color> color;

    color.resize(Graph.size(), white);

	Queue.push(current);

	while (!Queue.empty()) {
		current = Queue.front();
		Queue.pop();

		for (int i = 0; i < Graph[current].size(); i++) {
			adjacent = Graph[current][i];
			if (color[adjacent] == white) {
				color[adjacent] = gray;
				Queue.push(adjacent);
			}
		}
        color[current] = black;
	}

    for (int i = 0; i < color.size(); i++) {
        if (color[i] == white) {
            return false;
        }
    }
    return true;
}

int main() {
	int intersections, streets, orig, dest, P;

	while ((cin >> intersections >> streets) && intersections) {
        Graph.clear();
        Graph.resize(intersections);

        for (int i = 1; i <= streets; i++) {
            cin >> orig >> dest >> P;
            orig--; dest--;
            Graph[orig].push_back(dest);
            Graph[dest];
            if (P == 2) {
                Graph[dest].push_back(orig);
            }
        }

        bool isConnected = true;
        for (int i = 0; i < intersections; i++) {
            isConnected = bfs(i);
            if (!isConnected) {
                std::cout << "0" << std::endl;
                break;
            }
        }

        if (isConnected) {
            std::cout << "1" << std::endl;
        }
    }

	return 0;
}
