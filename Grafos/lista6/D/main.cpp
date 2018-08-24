#include <iostream>
#include <algorithm>

#define INFINITE 999999999
#define MAX_CITIES 101

int Graph[MAX_CITIES][MAX_CITIES];

int main(int argc, char const *argv[]) {
    int cities = 0, roads = 0;

    std::cin >> cities >> roads;

    /* set matrix infinite and 0 on major diagonal */
    for (int i = 0; i <= cities; i++) {
        for (int j = 0; j <= cities; j++) {
            Graph[i][j] = (i == j) ? 0 : INFINITE;
        }
    }

    for (int i = 0; i < roads; i++) {
        int orig = 0, dest = 0, cost = 0;

        std::cin >> orig >> dest >> cost;
        Graph[orig][dest] = Graph[dest][orig] = cost;
    }

    /* Floyd-Warshall */
    for (int k = 0; k <= cities; k++) {
        for (int i = 0; i <= cities; i++) {
            for (int j = 0; j <= cities; j++) {
                Graph[i][j] = std::min(Graph[i][j], Graph[i][k] + Graph[k][j]);
            }
        }
    }

    int MAX = INFINITE;
    for (int i = 0; i < cities; i++) {
        int rowMAX = 0;
        for (int j = 0; j < cities; j++) {
            // std::cout << Graph[i][j] << " ";
            if (Graph[i][j] != INFINITE && Graph[i][j] > rowMAX) {
                rowMAX = Graph[i][j];
            }
        }
        // std::cout << "rowMax: " << rowMAX << " ";
        // std::cout << std::endl;
        MAX = rowMAX < MAX ? rowMAX : MAX;
    }

    std::cout << MAX << std::endl;

    return 0;
}
