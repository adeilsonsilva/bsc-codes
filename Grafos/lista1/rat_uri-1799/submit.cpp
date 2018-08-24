#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

#define INFINITE 999999

using namespace std;


typedef enum Color{white, gray, black} Color;
typedef pair<string, int> Pair;

map<string, vector<string> > graph;
map<string, vector<string> >::iterator iter;
map<string, int> dist;
map<string, string> ancestor;
map<string, int> visited;
vector<string> path;

struct Order
{
    bool operator()(Pair const& a, Pair const& b) const
    {
        return a.second >= b.second;
    }
};

priority_queue<Pair, vector<Pair>, Order> Queue;

void initVertex(string orig, string dest)
{
	graph[orig].push_back(dest);
	graph[dest].push_back(orig);
	dist[orig] = dist[dest] = INFINITE;
	ancestor[orig] = ancestor[dest] = "NULL";
	Queue.push(make_pair(orig, dist[orig]));
	Queue.push(make_pair(dest, dist[dest]));
}

void reconstruct(string current)
{
	do
	{
		path.push_back(current);
		current = ancestor[current];
	}while(current != "NULL");
}

void dijkstra(string start, string goal)
{
	int distX = 0;
	int lower, length = 0;
	string lowerName;
	string adjacent, current;
	Pair test;

	dist[start] = 0;
	Queue.push(make_pair(start, dist[start]));
	while(!Queue.empty())
	{

		current = Queue.top().first;
		Queue.pop();

		if(current == goal){
			reconstruct(goal);
			break;
		}

		for(int i = 0; i < graph[current].size(); i++)
		{
			adjacent = graph[current][i];
			distX = dist[current] + 1;
			if (distX < dist[adjacent])
			{
				ancestor[adjacent] = current;
				dist[adjacent] = distX;
				Queue.push(make_pair(adjacent, dist[adjacent]));
			}
		}
	}
}

int main()
{
	int points, links, orig, dest;
	string nameOrig, nameDest;

	cin >> points >> links;

	for(int i = 1; i <= links; i++){
		cin >> nameOrig >> nameDest;
		initVertex(nameOrig, nameDest);
	}

	dijkstra("Entrada", "*");

	for (iter = graph.begin(); iter != graph.end(); iter++){
		dist[iter->first] = INFINITE;
		ancestor[iter->first] = "NULL";
		Queue.push(make_pair(iter->first, dist[iter->first]));
	}

	dijkstra("*", "Saida");

	cout << path.size() - 2 << endl;

	return 0;
}
