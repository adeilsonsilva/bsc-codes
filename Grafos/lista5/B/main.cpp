#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
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

set<Edge, Order> edgeList; // edgeList will keep all edges of the graph
set<pair<int, int> > resultSet;
vector<Subset> Set;
int sumOfDistances = 0;

void init(int N) {
    Set.resize(N + 1);
    for(int i = 1; i <= N; i++) {
        Set[i].parent = i;
        Set[i].rank = 0;
    }
}

void initEdge(int orig, int dest, int distance)
{
	edgeList.insert(make_pair(orig, make_pair(dest, distance)));
	edgeList.insert(make_pair(dest, make_pair(orig, distance)));
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

    if(Set[origVertexRoot].rank < Set[destVertexRoot].rank) swap(origVertexRoot, destVertexRoot);

    Set[destVertexRoot].parent = origVertex;
    Set[origVertex].rank += Set[destVertexRoot].rank;
}

void kruskal()
{
	int origVertex, destVertex, distance;
	Edge currentEdge;

	while (!edgeList.empty()) {
        currentEdge = *edgeList.begin();
        edgeList.erase(edgeList.begin());

		origVertex = currentEdge.first;
		destVertex = currentEdge.second.first;
		distance = currentEdge.second.second;

		int origVertexRoot = findRoot(origVertex);
        int destVertexRoot = findRoot(destVertex);

		if (origVertexRoot != destVertexRoot) {
			Union(origVertex, destVertex);
			// sumOfDistances += distance;
            if(origVertex > destVertex){ swap(origVertex, destVertex);}
            resultSet.insert(make_pair(origVertex, destVertex));
		}
	}
}

int main()
{
	int cities, roads, orig, dest, distance, test = 0;

	while ((cin >> cities >> roads) && cities) {

		for(int i = 0; i < roads; i++){
			cin >> orig >> dest >> distance;
			initEdge(orig, dest, distance);
		}

        init(cities);
		kruskal();

        std::cout << "Teste " << ++test << std::endl;
        for (auto element : resultSet) {
            std::cout << element.first << " " << element.second << std::endl;
        }
        std::cout << std::endl;

		sumOfDistances = 0;
		Set.clear();
		edgeList = {};
		resultSet = {};
	}

	return 0;
}
