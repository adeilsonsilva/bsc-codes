#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

#define MAX_TASKS 50001
#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color {white, gray, black} Color;
typedef vector< vector<int> > Graph;

Graph G;
Graph::iterator graphIter, tmpGraphIter;
map<int, int> finishTime, beginTime, leastAncestorTime;
map<int, Color> color;
map<int, int> ancestor;

int globalTime = 0;

struct comparison {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.first < rhs.first;
    }
};

// set<pair<int, int>, comparison > Answer;
vector<pair<int, int> > Answer;


void dfsVisit (int current) {
    int adjacent;

    leastAncestorTime[current] = beginTime[current] = globalTime++;
    color[current] = gray;

    for (int i = 0; i < G[current].size(); i++) {
        adjacent = G[current][i];
        if (color[adjacent] == white) {
            ancestor[adjacent] = current;
            dfsVisit(adjacent);
            leastAncestorTime[current] = std::min(leastAncestorTime[current], leastAncestorTime[adjacent]);

            if (leastAncestorTime[adjacent] > beginTime[current]) {
                Answer.push_back(make_pair(std::min(current, adjacent), std::max(current, adjacent)));
            }
        } else if (adjacent != ancestor[current]) {
            leastAncestorTime[current] = std::min(leastAncestorTime[current], beginTime[adjacent]);
        }
    }

    color[current] = black;
    finishTime[current] = globalTime++;
}

void dfs () {

    for (int i = 0; i < G.size(); i++) {
        color[i] = white;
        beginTime[i] = 0;
        finishTime[i] = 0;
        leastAncestorTime[i] = 0;
        ancestor[i] = NIL;
    }

    for (int i = 0; i < G.size(); i++) {
        if (color[i] == white) {
            dfsVisit(i);
        }
    }
}

int main() {

    int orig, dest;
    int servers, serverNumber;
    string connections;

    while ((cin >> servers)) {
        globalTime = 0;
        G.clear();
        color.clear();
        finishTime.clear();
        ancestor.clear();
        Answer.clear();
        G.resize(servers+1);

        for (int i = 0; i < servers; i++) {
            cin >> serverNumber >> connections;
            connections.erase(0, 1);
            connections.erase(connections.size() - 1);
            int connectionsNumber = std::stoi(connections);
            for (int j = 0; j < connectionsNumber; j++) {
                cin >> dest;
                G[serverNumber].push_back(dest);
                G[dest].push_back(serverNumber);
            }
        }

        dfs();

        sort(Answer.begin(), Answer.end());
        std::cout << Answer.size() << " critical links" << std::endl;
        for (auto& edge : Answer) {
            std::cout << edge.first << " - " << edge.second << std::endl;
        }
        std::cout << std::endl;
    }

	return 0;
}
