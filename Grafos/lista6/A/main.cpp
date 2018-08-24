#include <iostream>
#include <algorithm>
#include <vector>

#define INFINITE 999999999
#define MAX_CITIES 110

int Graph[MAX_CITIES][MAX_CITIES];
int cities = 0, roads = 0;

int dijkstra(int orig, int dest, int cities)
{
    int current, distance[cities + 1];
    bool visited[cities + 1];

    for (int i = 1; i <= cities; i++) {
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
            int dist = distance[current] + Graph[current][adjacent];
            if (dist < distance[adjacent]) {
                distance[adjacent] = dist;
            }
        }

    }

    return distance[dest] == INFINITE ?  -1 : distance[dest];
}

int main()
{
    while ((std::cin >> cities >> roads), cities) {

        for (int i = 0; i <= cities; i++) {
            for (int j = 0; j <= cities; j++) {
                Graph[i][j] = i == j ? 0 : INFINITE;
            }
        }

        for (int i = 0; i < roads; i++) {
            int orig = 0, dest = 0, cost = 0;
            std::cin >> orig >> dest >> cost;
            Graph[orig][dest] = cost;
        }

        int begin = 0, end = 0;
        std::cin >> begin >> end;
        std::cout << dijkstra(begin, end, cities) << std::endl;
    }

    return 0;
}
