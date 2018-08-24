#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color{white, gray, black} Color;

map<int, vector<int> > graph;
map<int, vector<int> >::iterator graphIter;
map<int, Color> color;
map<int, int> dist, begin, end;
map<int, int> ancestor;
vector<int> visited;

vector<int> vertexSet;
map<int, int> onStack, leastAncestorTime, discoveryTime;

stack<int> Stack;

int Time = 0, scc = 0;

void initVertex(int orig, int dest) {
	graph[orig].push_back(dest);
    graph[dest];
	// graph[dest].push_back(orig);
	// color[orig] = color[dest] = white;
	// dist[orig] = dist[dest] = INFINITE;
	// ancestor[orig] = ancestor[dest] = NIL;
    discoveryTime[orig] = discoveryTime[dest] = NIL;
	leastAncestorTime[orig] = leastAncestorTime[dest] = NIL;
	onStack[orig] = onStack[dest] = 0;
}

// void bfs (int current) {
// 	int adjacent;
// 	queue<int> Queue;
//
// 	color[current] = gray;
// 	dist[current] = 0;
// 	ancestor[current] = -1;
// 	Queue.push(current);
//
// 	while (!Queue.empty()) {
// 		current = Queue.front();
// 		Queue.pop();
//
// 		for (int i = 0; i < graph[current].size(); i++) {
// 			adjacent = graph[current][i];
// 			if (color[adjacent] == white) {
// 				color[adjacent] = gray;
// 				dist[adjacent] = dist[current] + 1;
// 				ancestor[adjacent] = current;
// 				Queue.push(adjacent);
// 			}
// 		}
//         color[current] = black;
//         visited.push_back(current);
// 	}
//
//     if (visited.size() == graph.size()) {
//         std::cout << "normal" << graph.size() << std::endl;
//     } else {
//         std::cout << "falha " << graph.size() << " " << visited.size() << std::endl;
//     }
// }

// void dfs(map<int, vector<int> >& Graph) {
//
//     for (graphIter = graph.begin() ; graphIter != graph.end(); graphIter++) {
//         color[graphIter->first] = white;
//         ancestor[graphIter->first] = NIL;
//     }
//
//     for (graphIter = graph.begin() ; graphIter != graph.end(); graphIter++) {
//         if (color[graphIter->first] == white) {
//             dfsVisit(graphIter->first);
//         }
//     }
// }
//
// void dfsVisit (int current) {
//     begin[current] = ++Time;
//     color[current] = gray;
//
//     for (int i = 0; i < graph[current].size(); i++) {
//         adjacent = graph[current][i];
//         if (color[adjacent] == white) {
//             ancestor[adjacent] = current;
//             dfsVisit(adjacent);
//         }
//     }
//     color[current] = black;
//     end[current] = ++Time;
// }

void tarjan (int current) {
	static int Time = 0;

	discoveryTime[current] = leastAncestorTime[current] = ++Time;
    Stack.push(current);
    onStack[current] = 1;

    // cout << "Visiting: " << current << endl;

    vector<int>::iterator adjIter;

    for (adjIter = graph[current].begin(); adjIter != graph[current].end(); adjIter++) {
        int adjacent = *adjIter;
        // std::cout << "/* message */" << adjacent << std::endl;
        if (discoveryTime[adjacent] == NIL) {
            tarjan(adjacent);
            leastAncestorTime[current]  = min(leastAncestorTime[current], leastAncestorTime[adjacent]);
        } else if (onStack[adjacent]) {
            leastAncestorTime[current]  = min(leastAncestorTime[current], discoveryTime[adjacent]);
        }
    }

    // cout << "End of visit: " << current << endl;

    int vertex = 0;
    if (leastAncestorTime[current] == discoveryTime[current]) {
        // std::cout << "head found: " << current << std::endl;
        scc++;
        while (Stack.top() != current) {
            vertex = Stack.top();
            vertexSet.push_back(vertex);
            onStack[vertex] = 0;
            Stack.pop();
            // std::cout << vertex << "violent" << std::endl;
        }
        vertex = Stack.top();
        vertexSet.push_back(vertex);
        onStack[vertex] = 0;
        Stack.pop();
        // std::cout << vertex << "pornography" << std::endl;
    }

}

int main() {
	int stations, lines, orig, dest, test = 1;

	while ((cin >> stations >> lines) && stations) {
        for (int i = 1; i <= lines; i++) {
            cin >> orig >> dest;
            initVertex(orig, dest);
            // std::cout << "orig: " << orig << " dest: " << dest << std::endl;
        }

        std::cout << "Teste " << test++ << std::endl;

        // dfs();

        // std::cout << graph.size() << std::endl;
        for (graphIter = graph.begin() ; graphIter != graph.end(); graphIter++) {
            if (discoveryTime[graphIter->first] == NIL) {
                // std::cout << "inicia tarjan em " << graphIter->first << std::endl;
                tarjan(graphIter->first);
                if ((scc - 1) == 1) {
                    std::cout << "normal" << std::endl;
                } else {
                    std::cout << "falha" << std::endl;
                }
                // std::cout << vertexSet.size() << std::endl;
                vertexSet.clear();
                onStack.clear();
    			leastAncestorTime.clear();
    			discoveryTime.clear();
                scc = 0;
            }
        }

        ancestor.clear();
        visited.clear();
        color.clear();
        graph.clear();
        // dist.clear();
    }

	return 0;
}
