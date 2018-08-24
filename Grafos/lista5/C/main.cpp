#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define INFINITE 999999999.9999
#define NIL -1
#define ZERO 0.0000

using namespace std;

typedef struct subset
{
    int parent;
    int rank;
} Subset;

typedef pair<double, double> Vertex;

typedef pair<int, pair<int, double> > Edge; // <origVertex, <destVertex, distance> >

struct Order
{
	bool operator()(Edge const& a, Edge const& b) const
	{
	    return a.second.second <= b.second.second;
	}
};

set<Edge, Order> edgeList; // edgeList will keep all edges of the graph
vector<Vertex > vertexSet;
vector<Subset> Set;
double minDistance = ZERO;

double calcDist(Vertex& v1, Vertex& v2)
{
    // sqrt((x1-x2)^2 + (y1-y2)^2)
    return sqrt( pow((v1.first - v2.first), 2) + pow((v1.second - v2.second), 2) );
}

void initEdge(int orig, int dest, double distance)
{
    edgeList.insert(make_pair(orig, make_pair(dest, distance)));
    edgeList.insert(make_pair(dest, make_pair(orig, distance)));
}

void init(int N) {
    Set.resize(N + 1);
    for(int i = 1; i <= N; i++) {
        Set[i].parent = i;
        Set[i].rank = 0;

        for (int j = 1; j <= N; j++) {
            if (i != j) {
                initEdge(i, j, calcDist(vertexSet[i], vertexSet[j]));
            }
        }
    }
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
	int origVertex, destVertex;
    double distance;
	Edge currentEdge;
    minDistance = ZERO;

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
			minDistance = distance > minDistance ? distance : minDistance;
		}
	}
}

int main()
{
	int cities;
    double x, y;

	while ((cin >> cities) && cities) {

        vertexSet.resize(cities + 1);

		for(int i = 1; i <= cities; i++){
			cin >> x >> y;
            vertexSet[i] = make_pair(x, y);
		}

        init(cities);
		kruskal();

        if (cities == 1) {
            minDistance = ZERO;
        }

        cout << fixed << setprecision(4);
        std::cout << minDistance << std::endl;
        std::cout << std::endl;

		minDistance = ZERO;
		vertexSet.clear();
		Set.clear();
		edgeList = {};
	}

	return 0;
}
