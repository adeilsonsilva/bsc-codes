#include <iostream>
#include <algorithm>
#include <climits>

#define INFINITE 999999999

int main()
{
    int intersections = 0, streets = 0, instance = 1;
    while ((std::cin >> intersections >> streets), intersections) {
        int D[intersections + 1][intersections + 1];

        /* set matrix infinite and 0 on major diagonal */
        for (int i = 0; i <= intersections; i++) {
            for (int j = 0; j <= intersections; j++) {
                D[i][j] = (i == j) ? 0 : INFINITE;
            }
        }

        int orig = 0, dest = 0, altitude = 0;
        for (int i = 0; i < streets; i++) {
            std::cin >> orig >> dest >> altitude;
            D[orig][dest] = D[dest][orig] = altitude;
        }

        /* Floyd-Warshall */
        for (int k = 1; k <= intersections; k++) {
            for (int i = 1; i <= intersections; i++) {
                for (int j = 1; j <= intersections; j++) {
                    if(i != j && D[i][j] > std::max(D[i][k], D[k][j])) {
                        D[i][j] = std::max(D[i][k], D[k][j]);
                    }
                }
            }
        }

        std::cout << "Instancia " << instance++ << std::endl;

        int pairs = 0;
        std::cin >> pairs;
        for (int i = 0; i < pairs; i++) {
            std::cin >> orig >> dest;
            std::cout << D[orig][dest] << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
