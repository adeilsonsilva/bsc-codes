#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

#define INFINITE 999999
#define NIL -1

using namespace std;

typedef struct subset
{
    int parent;
    int rank;
} Subset;

typedef pair<int, pair<int, int> > Edge; // <origVertex, <destVertex, distance> >

struct Order
{
	bool operator()(Edge const& a, Edge const& b) const
	{
	    return a.second.second <= b.second.second;
	}
};

list<Edge> edgeList; // edgeList will keep all edges of the graph
map<int, Subset> Set;
int sumOfDistances = 0, sumOfAllDistances = 0;

void initEdge(int orig, int dest, int distance)
{
	/* Undirected graph */
	Set[orig].parent = orig;
	Set[dest].parent = dest;
	Set[orig].rank = Set[dest].rank = 0;

	edgeList.push_back(make_pair(orig, make_pair(dest, distance)));
	edgeList.push_back(make_pair(dest, make_pair(orig, distance)));

	sumOfAllDistances += distance;
}

int findRoot(int vertex)
{
    if (Set[vertex].parent != vertex) {
        Set[vertex].parent = findRoot(Set[vertex].parent);
    }

    return Set[vertex].parent;
}

void Union(int origVertex, int destVertex)
{
    int origVertexRoot = findRoot(origVertex);
    int destVertexRoot = findRoot(destVertex);

    if (Set[origVertexRoot].rank < Set[destVertexRoot].rank) {
        Set[origVertexRoot].parent = destVertexRoot;
    } else if (Set[origVertexRoot].rank > Set[destVertexRoot].rank) {
        Set[destVertexRoot].parent = origVertexRoot;
    } else {
        Set[destVertexRoot].parent = origVertexRoot;
        Set[origVertexRoot].rank++;
    }

}

void kruskal()
{
	int origVertex, destVertex, distance;
	Edge currentEdge;

	edgeList.sort(Order());

	while (!edgeList.empty()) {
		currentEdge = edgeList.front();
		edgeList.pop_front();

		origVertex = currentEdge.first;
		destVertex = currentEdge.second.first;
		distance = currentEdge.second.second;

		int origVertexRoot = findRoot(origVertex);
        int destVertexRoot = findRoot(destVertex);

		if (origVertexRoot != destVertexRoot) {
			Union(origVertex, destVertex);
			sumOfDistances += distance;
		}
	}
}

int main()
{
	int cities, roads, orig, dest, distance;

	while ((cin >> cities >> roads) && (cities != 0 && roads != 0)) {
		for(int i = 0; i < roads; i++){
			cin >> orig >> dest >> distance;
			initEdge(orig, dest, distance);
		}

		kruskal();

		std::cout << sumOfAllDistances - sumOfDistances << std::endl;

		sumOfDistances = sumOfAllDistances = 0;
		Set.clear();
		edgeList = {};
	}

	return 0;
}
