#include <iostream>
#include <algorithm>

#define INFINITE 999999999
#define MAX_CITIES 102

int Graph[MAX_CITIES][MAX_CITIES][MAX_CITIES];

int main(int argc, char const *argv[]) {
    int cities = 0, roads = 0, test = 1;

    while ((std::cin >> cities >> roads) && cities) {
        /* set matrix infinite and 0 on major diagonal */
        for (int k = 0; k <= cities; k++) {
            for (int i = 0; i <= cities; i++) {
                for (int j = 0; j <= cities; j++) {
                    Graph[i][j][k] = (i == j) ? 0 : INFINITE;
                }
            }
        }

        for (int i = 0; i < roads; i++) {
            int orig = 0, dest = 0, cost = 0;

            std::cin >> orig >> dest >> cost;
            Graph[orig - 1][dest - 1][0] = std::min(Graph[orig - 1][dest - 1][0], cost);
        }

        std::cout << "Instancia " << test++ << std::endl;

        /* Floyd-Warshall */
        for (int k = 1; k <= cities; k++) {
            for (int i = 0; i < cities; i++) {
                for (int j = 0; j < cities; j++) {
                    Graph[i][j][k] = std::min(Graph[i][j][k-1], Graph[i][k-1][k-1] + Graph[k-1][j][k-1]);
                }
            }
        }

        int queries = 0;
        std::cin >> queries;
        for (int i = 0; i < queries; i++) {
            int orig = 0, dest = 0, maxCities = 0;

            std::cin >> orig >> dest >> maxCities;

            if (Graph[orig-1][dest-1][maxCities] == INFINITE) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << Graph[orig - 1][dest - 1][maxCities] << std::endl;
            }
        }

    }


    return 0;
}
