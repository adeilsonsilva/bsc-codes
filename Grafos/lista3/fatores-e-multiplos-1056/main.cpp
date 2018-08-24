#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

#define MAX_SET 101

typedef std::vector<long int> Vector;
typedef std::vector<Vector> Graph;

Vector visited, setA, setB, matchedA, matchedB;

int N = 0, M = 0;

bool isMultiple (long int a, long int b)
{
    return (a % b == 0);
}

void buildGraph (Graph& graph)
{
    int n = 0, m = 0;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (setA[n] == 0) {
                if (setB[m] == 0) {
                    graph[n][m] = 1;
                }
            } else {
                if (isMultiple(setB[m], setA[n])) {
                    graph[n][m] = 1;
                }
            }
        }
    }
}

bool dfs (long int current, Graph& graph)
{
    for (int adjacent = 0; adjacent < graph[current].size(); adjacent++) {
        if (graph[current][adjacent] && !visited[adjacent]) {
            visited[adjacent] = 1;
            if (matchedB[adjacent] < 0 || dfs(matchedB[adjacent], graph)) {
                matchedA[current] = adjacent;
                matchedB[adjacent] = current;
                return true;
            }
        }
    }
    return false;
}

int fordFulkerson (Graph& graph)
{
    int result = 0;

    matchedA.resize(N, -1);
    matchedB.resize(M, -1);
    std::fill(matchedA.begin(), matchedA.end(), -1);
    std::fill(matchedB.begin(), matchedB.end(), -1);

    for (int current = 0; current < N; current++) {
        visited.resize(M, 0);
        std::fill(visited.begin(), visited.end(), 0);
        if (dfs(current, graph)) {
            result++;
        }
    }
    return result;
}

int main ()
{
    int tests = 0, cases = 1;

    std::cin >> tests;
    for (int i = 0; i < tests; i++) {

        std::cin >> N;
        setA.resize(N, 0);
        for (int i = 0; i < N; i++) {
            int number;
            std::cin >> setA[i];
        }

        std::cin >> M;
        setB.resize(M, 0);
        for (int i = 0; i < M; i++) {
            int number;
            std::cin >> setB[i];
        }

        Graph graph (N, Vector(M));
        buildGraph(graph);

        int result = fordFulkerson(graph);

        std::cout << "Case " << cases++ << ": " << result << std::endl;

        std::fill(setA.begin(), setA.end(), 0);
        std::fill(setB.begin(), setB.end(), 0);
    }

    return 0;
}
