#include <stdio.h>
#include <algorithm>

#define MAXN 100

struct Car {
  int number, time;
};

bool comparison (const Car& a, const Car& b){
    return a.time < b.time;
}

Car Cars[MAXN];

int main(int argc, char *argv[])
{
	int i = 0, j = 0, N = 0, M = 0, t = 0;

	/* Data input and processing */
	scanf(" %d %d", &N, &M);
	for(i = 0; i < N; i++){
		Cars[i].number = i + 1;
		Cars[i].time = 0;
		for(j = 0; j < M; j++){
			scanf(" %d", &t);
			Cars[i].time += t;
		}
	}

	/* Sort Times */
	std::sort(Cars, Cars+N, comparison);

	/* Data output */

	/* Print sorted array */
	for (i = 0; i < 3; i++){
		printf("%d\n", Cars[i].number);
	}
}