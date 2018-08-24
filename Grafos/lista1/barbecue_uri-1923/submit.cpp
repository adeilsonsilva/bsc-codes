#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

#define MAX_RELATIONS 4950
#define INFINITE 999999

using namespace std;

typedef enum Color{white, gray, black} Color;

map<string, vector<string> > graph;
map<string, vector<string> >::iterator iter;
map<string, int> dist;
map<string, string> ancestor;
map<string, Color> color;
vector<string> invited;

int spots, roads, roadsMissingCounter;

void initVertex(string orig, string dest)
{
	graph[orig].push_back(dest);
	graph[dest].push_back(orig);
	color[orig] = color[dest] = white;
	dist[orig] = dist[dest] = INFINITE;
	ancestor[orig] = ancestor[dest] = -1;
}

void bfs(string current, int maxDegree)
{	
	string adjacent;
	queue<string> Queue;

	color[current] = gray;
	dist[current] = 0;
	ancestor[current] = -1;
	Queue.push(current);
	while(!Queue.empty())
	{
		current = Queue.front();
		Queue.pop();

		if(dist[current] <= maxDegree && !(std::find(invited.begin(), invited.end(), current) != invited.end()) && (current != "Rerisson")){
			invited.push_back(current);
		}
		
		for(int i = 0; i < graph[current].size(); i++) 
		{
			adjacent = graph[current][i];
			if (color[adjacent] == white){
				color[adjacent] = gray;
				dist[adjacent] = dist[current] + 1;
				ancestor[adjacent] = current;
				Queue.push(adjacent);
			}
		}
		color[current] = black;
	}
}

int main()
{
	int relations, maxDegree, orig, dest;
	string nameOrig, nameDest;

	cin >> relations >> maxDegree;

	for(int i = 1; i <= relations; i++){
		cin >> nameOrig >> nameDest;
		initVertex(nameOrig, nameDest);
	}

	bfs("Rerisson", maxDegree);

	std::sort(invited.begin(), invited.end());
	int size = invited.size();
	cout << size << endl;
	for(int i = 0; i < size; i++){
		cout << invited[i] << endl;
	}

	return 0;
}