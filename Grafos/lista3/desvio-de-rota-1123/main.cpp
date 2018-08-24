#include <iostream>
#include <algorithm>

#define INFINITE 9999
#define MAX_CITIES 251

int Graph[MAX_CITIES][MAX_CITIES];
int cities = 0, roads = 0, routeLength = 0, carFixedAt = 0;

bool checkOrig (int orig, int dest)
{
    return ((orig >= routeLength && dest < routeLength)
        || ((orig < routeLength && dest < routeLength) && (orig + 1 == dest))
    );
}

bool checkDest (int orig, int dest)
{
    return ((orig < routeLength && dest >= routeLength)
        || (orig < routeLength && dest < routeLength) && (orig == dest + 1)
    );
}

bool checkBoth (int orig, int dest)
{
    return orig >= routeLength && dest >= routeLength;
}

int dijkstra(int orig, int dest, int cities)
{
    int current, distance[cities];
    bool visited[cities];

    for (int i = 0; i < cities; i++) {
        distance[i] = INFINITE;
        visited[i] = false;
    }
    distance[orig] = 0;

    while (1) {
        int leastDistance = INFINITE;

        for (int adjacent = 0; adjacent < cities; adjacent++) {
            if (distance[adjacent] < leastDistance && !visited[adjacent]) {
                leastDistance = distance[adjacent];
                current = adjacent;
            }
        }

        if ((current == dest) || (leastDistance == INFINITE)) {break;}

        visited[current] = true;
        for (int adjacent = 0; adjacent < cities; adjacent++) {
            /* Relaxing */
            int dist = distance[current] + Graph[current][adjacent];
            if (dist < distance[adjacent]) {
                distance[adjacent] = dist;
            }
        }

    }

    return distance[dest];
}

int main()
{
    while ((std::cin >> cities >> roads >> routeLength >> carFixedAt), cities) {

        for (int i = 0; i < cities; i++) {
            for (int j = 0; j < cities; j++) {
                Graph[i][j] = INFINITE;
            }
        }

        for (int i = 0; i < roads; i++) {
            int orig = 0, dest = 0, cost = 0;
            std::cin >> orig >> dest >> cost;
            if (checkOrig(orig, dest)) {
                Graph[orig][dest] = cost;
            }

            if (checkDest(orig, dest)) {
                Graph[dest][orig] = cost;
            }

            if (checkBoth(orig, dest)) {
                Graph[orig][dest] = Graph[dest][orig] = cost;
            }
        }
        std::cout << dijkstra(carFixedAt, routeLength - 1, cities) << std::endl;
    }

    return 0;
}
