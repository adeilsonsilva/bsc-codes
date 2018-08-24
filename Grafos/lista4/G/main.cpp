#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <utility>

#define MAX_TASKS 50001
#define INFINITE 999999
#define NIL -1

using namespace std;

typedef enum Color {white, gray, black} Color;

vector<vector<int> > Graph;
vector<int> prioritie;
map<int, int> finishTime, beginTime;
map<int, Color> color;

int globalTime = 0;

struct comparison {
    bool operator() (const int& lhs, const int& rhs) const {
        // if (rhs > lhs) {
        //     return prioritie[rhs] > prioritie[lhs];
        // }
        // return true;
        return lhs < rhs || prioritie[rhs] < prioritie[lhs];
        //ver sobre emplace_hint
    }
};

set<int, comparison> List;
// bool comparison (int a, int b) {
//     return a < b;
// }

bool dfsVisit (int current, int tasks) {
    int adjacent;
    list<int>::iterator listIter;
    bool result = true;

    beginTime[current] = globalTime++;
    color[current] = gray;

    // std::cout << "current: " << current << std::endl;

    for (int i = 0; i < Graph[current].size(); i++) {
        adjacent = Graph[current][i];
        if (color[adjacent] == white) {
            // std::cout << "visitando: " << adjacent << std::endl;
            result = dfsVisit(adjacent, tasks);
        } else if (color[adjacent] == gray) {
            // std::cout << "ciclo! " << current << " " << adjacent << std::endl;
            result = false;
        } else if (color[adjacent] == black) {
            // std::cout << "inserindo: " << current << std::endl;
            // List.insert(current);
            // return false;
            // if (List.find(current) != List.end()) {
            //     /* code */
            //     List.erase (List.find(current));
            // }
        }
    }

    if (result) {
        color[current] = black;
        // listIter = std::find (List.begin(), List.end(), current);
        // if (listIter == List.end()) {
            // List.push_front(current);
        // }
        List.insert(current);
        finishTime[current] = globalTime++;
        std::cout << "finalizando: " << current << std::endl;
        return true;
    }

    return false;
}

void dfs (int tasks, int dependencies) {

    for (int i = 0; i < tasks; i++) {
        color[i] = white;
        finishTime[i] = 0;
    }

    for (int i = 0; i < tasks; i++) {
        if (color[i] == white) {
            if (!dfsVisit(i, tasks)) {
                std::cout << "*" << std::endl;
                return;
            }
        }
    }

    for (auto element : List) {
        std::cout << element << " prioritie: " << prioritie[element] << std::endl;
        // std::cout << element << " begin: " << beginTime[element] << " finish: " << finishTime[element] << std::endl;
        // std::cout << element << std::endl;
    }
}

int main() {

    int tasks, dependencies, orig, dest;

    cin >> tasks >> dependencies;

    Graph.reserve(tasks);
    prioritie.reserve(tasks);
    std::fill(prioritie.begin(), prioritie.end(), 0);

    for (int i = 0; i < dependencies; i++) {
        cin >> orig >> dest;
        Graph[orig].push_back(dest);
        prioritie[orig]++;
        // Graph[dest].push_back(orig);
    }
    dfs(tasks, dependencies);
	return 0;
}
