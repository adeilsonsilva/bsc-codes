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

typedef enum Color {white, gray, black} Color;

map<int, vector<int> > Graph, GraphT;
map<int, vector<int> >::iterator graphIter;

bool Visited[105][205];

bool bfs (int start, int end, int days, int cities) {
	int current, adjacent;
	queue<pair<int, int> > Queue;

    for (int i = 1; i <= cities; i++) {
        for (int j = 0; j <= days; j++) {
            Visited[i][j] = 0;
        }
    }

    Visited[start][0] = 1;
	Queue.push(make_pair(start, 0));

	while (!Queue.empty()) {
		current = Queue.front().first;
        int distance = Queue.front().second;
		Queue.pop();

        if (current == end && distance == days) {
            return true;
        }

        for (int i = 0; i < Graph[current].size(); i++) {
			adjacent = Graph[current][i];
            int nextDistance = distance + 1;
            if ((nextDistance <= days) && !Visited[adjacent][nextDistance]) {
				Visited[adjacent][nextDistance] = 1;
                Queue.push(make_pair(adjacent, nextDistance));
			}
		}
	}

    return false;
}

int main() {
	int cities, roads, orig, dest, start, end, days;

	while ((cin >> cities >> roads) && cities) {
        Graph.clear();

        for (int i = 1; i <= roads; i++) {
            cin >> orig >> dest;
            Graph[orig].push_back(dest);
            Graph[dest].push_back(orig);
        }
        cin >> start >> end >> days;

        if (bfs(start, end, days, cities)) {
            std::cout << "Yes, Teobaldo can travel." << std::endl;
        } else {
            std::cout << "No, Teobaldo can not travel." << std::endl;
        }
    }

	return 0;
}
