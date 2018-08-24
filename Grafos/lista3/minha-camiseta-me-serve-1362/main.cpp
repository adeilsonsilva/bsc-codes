#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

#define SHIRT_SIZES 6
#define XXL "XXL"
#define XL "XL"
#define L "L"
#define M "M"
#define S "S"
#define XS "XS"

typedef std::vector<int> Vector;
typedef std::vector<Vector> Graph;

Vector visited, matchedB;

int shirts = 0, volunteers = 0;

int getSizeNumber (std::string size)
{
    if (size == XXL) {
        return 0;
    } else if (size == XL) {
        return 1;
    } else if (size == L) {
        return 2;
    } else if (size == M) {
        return 3;
    } else if (size == S) {
        return 4;
    } else if (size == XS) {
        return 5;
    }
}

bool dfs (long int current, Graph& graph)
{
    if (current <= volunteers) {
        for (int adjacent = 0; adjacent < graph[current].size(); adjacent++) {
            if (graph[current][adjacent] && !visited[adjacent]) {
                visited[adjacent] = 1;
                if (matchedB[adjacent] < 0 || dfs(matchedB[adjacent], graph)) {
                    matchedB[adjacent] = current;
                    return true;
                }
            }
        }
    }
    return false;
}

int fordFulkerson (Graph& graph)
{
    int result = 0;

    visited.resize(volunteers + 1, 0);
    matchedB.resize(volunteers + 1, -1);
    std::fill(matchedB.begin(), matchedB.end(), -1);

    for (int current = 0; current < graph.size(); current++) {
        std::fill(visited.begin(), visited.end(), 0);
        if (dfs(current, graph)) {
            result += shirts / SHIRT_SIZES;
        }
    }
    return result;
}


int main(int argc, char const *argv[]) {
    int tests = 0;

    std::cin >> tests;

    for (int i = 0; i < tests; i++) {
        std::cin >> shirts >> volunteers;

        Graph graph (volunteers + 1, Vector(SHIRT_SIZES, 0));
        for (int j = 0; j < volunteers; j++) {
            std::string sizeOne, sizeTwo;
            std::cin >> sizeOne >> sizeTwo;

            graph[j][getSizeNumber(sizeOne)] = shirts / SHIRT_SIZES;
            graph[j][getSizeNumber(sizeTwo)] = shirts / SHIRT_SIZES;
        }

        int result = fordFulkerson(graph);

        if (result >= (volunteers / shirts) - (shirts / SHIRT_SIZES)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
