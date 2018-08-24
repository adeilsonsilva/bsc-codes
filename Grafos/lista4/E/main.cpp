#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color{white, gray, black} Color;

vector< vector<int> > Graph, GraphT;
vector< vector<int> >::iterator graphIter;
vector<int> dist;

int bfs (int start)
{
	int adjacent, maxDistance = 0;
	priority_queue<pair<int, int> > Queue;

    std::fill(dist.begin(), dist.end(), INFINITE);

    dist[start] = 0;
	Queue.push(make_pair(start, 0));

	while (!Queue.empty()) {
		int current = Queue.top().first;
		Queue.pop();

		for (int i = 0; i < Graph[current].size(); i++) {
			adjacent = Graph[current][i];
            maxDistance = dist[current] + 1;
            if (dist[adjacent] >= maxDistance) {
                dist[adjacent] = maxDistance;
                Queue.push(make_pair(adjacent, maxDistance));
			}
		}
	}

    int max = 0;
    for (int i = 0; i < Graph.size(); i++) {
        if (dist[i] > max) {
            max = dist[i];
        }
    }

    return max;
}

int main() {
	int villages, roads, test = 0, orig, dest;

	while ((cin >> villages) && villages) {
        Graph.clear();
        dist.clear();
        Graph.resize(villages);
        dist.resize(villages);

        for (int i = 0; i < villages - 1; i++) {
            cin >> orig >> dest;
            orig--; dest--; // As vilas são numeradas de 1 a N
            Graph[orig].push_back(dest);
            Graph[dest].push_back(orig);
        }

        int village, post = INFINITE;
        for (int i = 0; i < villages; i++) {
            int answer = bfs(i);
            if (post > answer) {
                post = answer;
                village = i+1;
            }
        }

        std::cout << "Teste " << ++test << std::endl;
        std::cout << village << std::endl;
        std::cout << std::endl;
    }

	return 0;
}
