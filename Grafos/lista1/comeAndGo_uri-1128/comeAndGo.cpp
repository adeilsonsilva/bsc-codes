#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color{white, gray, black} Color;

int globalTime = 0;
map<int, vector<int> > graph;
map<int, vector<int> >::iterator graphIter;
vector<int>::iterator adjIter;
vector<int> vertexSet;
map<int, int> onStack, leastAncestorTime, discoveryTime;

stack<int> Stack;

void initVertex(int orig, int dest)
{
	graph[orig].push_back(dest);
	discoveryTime[orig] = NIL;
	leastAncestorTime[orig] = NIL;
	onStack[orig] = 0;
}

void tarjan(int current)
{
	static int time = 0;

	discoveryTime[current] = leastAncestorTime[current] = ++time;
    Stack.push(current);
    onStack[current] = 1;

    cout << "Visiting: " << current << endl;

    for (adjIter = graph[current].begin(); adjIter != graph[current].end(); adjIter++) {
        int adjacent = *adjIter;

        if (discoveryTime[adjacent] == NIL) {
            tarjan(adjacent);
            leastAncestorTime[current]  = min(leastAncestorTime[current], leastAncestorTime[adjacent]);
        } else if (onStack[adjacent]) {
            leastAncestorTime[current]  = min(leastAncestorTime[current], discoveryTime[adjacent]);
        }
    }

    cout << "End of visit: " << current << endl;

    int vertex = 0;
    // if (leastAncestorTime[current] == discoveryTime[current]) {
    //     while (Stack.top() != current) {
    //         vertex = Stack.top();
    //         vertexSet.push_back(vertex);
    //         onStack[vertex] = 0;
    //         Stack.pop();
    //     }
    //     vertex = Stack.top();
    //     vertexSet.push_back(vertex);
    //     onStack[vertex] = 0;
    //     Stack.pop();
    // }

}

int main()
{
	int intersections, streets, orig, dest, edges;
	int nameOrig, nameDest;

	while ((cin >> intersections >> streets) && (intersections != 0 && streets != 0)) {
		for(int i = 0; i < streets; i++){
			cin >> nameOrig >> nameDest >> edges;
			initVertex(nameOrig, nameDest);
			if (edges == 2) {
				initVertex(nameDest, nameOrig);
			}
		}

	    for (graphIter = graph.begin() ; graphIter != graph.end(); graphIter++) {
			tarjan(graphIter->first);
			// cout << graphIter->first << endl;
			cout << vertexSet.size() << endl;
			vertexSet.clear();
			onStack.clear();
			leastAncestorTime.clear();
			discoveryTime.clear();
		}
	}

	return 0;
}
