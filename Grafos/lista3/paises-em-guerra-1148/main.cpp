#include <iostream>
#include <algorithm>

#define INFINITE 999999999
#define MAX_CITIES 501

int D[MAX_CITIES][MAX_CITIES];

int dijkstra(int orig, int dest, int cities)
{
    int current, distance[cities + 1];
    bool visited[cities + 1];

    for (int i = 0; i <= cities; i++) {
        distance[i] = INFINITE;
        visited[i] = false;
    }
    distance[orig] = 0;

    while (1) {
        int leastDistance = INFINITE;

        for (int adjacent = 1; adjacent <= cities; adjacent++) {
            if (distance[adjacent] < leastDistance && !visited[adjacent]) {
                leastDistance = distance[adjacent];
                current = adjacent;
            }
        }

        if ((current == dest) || (leastDistance == INFINITE)) {break;}

        visited[current] = true;
        for (int adjacent = 1; adjacent <= cities; adjacent++) {
            /* Relaxing */
            int dist = distance[current] + D[current][adjacent];
            if (dist < distance[adjacent]) {
                distance[adjacent] = dist;
            }
        }

    }

    return distance[dest];
}

int main(int argc, char const *argv[]) {
    int cities = 0, deals = 0;

    while ((std::cin >> cities >> deals), cities) {
        /* set matrix infinite and 0 on major diagonal */
        for (int i = 0; i <= cities; i++) {
            for (int j = 0; j <= cities; j++) {
                D[i][j] = (i == j) ? 0 : INFINITE;
            }
        }

        int orig = 0, dest = 0, hours = 0;
        for (int i = 0; i < deals; i++) {
            std::cin >> orig >> dest >> hours;
            if (D[dest][orig] != INFINITE) {
                D[dest][orig] = D[orig][dest] = 0;
            } else {
                D[orig][dest] = hours;
            }
        }

        int queries = 0;
        std::cin >> queries;
        for (int i = 0; i < queries; i++) {
            std::cin >> orig >> dest;
            int distance = dijkstra(orig, dest, cities);
            if (distance < INFINITE) {
                std::cout << distance << std::endl;
            } else {
                std::cout << "Nao e possivel entregar a carta" << std::endl;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
