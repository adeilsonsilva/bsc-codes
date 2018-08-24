#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define MAX_NUMBER 30
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int sortArray[] = {8, 4, 888, 2, 45, 6732, 9, 13, 67, 6, 90, 21, 1, 554, 0};
int originalArray[] = {8, 4, 888, 2, 45, 6732, 9, 13, 67, 6, 90, 21, 1, 554, 0};
int i, j, v;

/* Time Stuff */
time_t start, stop, startSort, stopSort;
clock_t ticks;
long count;

void testTime() {
	// Do stuff
	int i=0;

	while(i<MAX_NUMBER)
	{
		//printf("Work work %d\n", i);
		i++;
		ticks = clock();
	}
}

/* Returns an integer in the range [0, n).
 *
 * Uses rand(), and so is affected-by/affects the same seed.
 */
int randint(int n) {
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    // Chop off all of the values that would cause skew...
    long end = RAND_MAX / n; // truncate skew
    if(end < 0L){
    	printf("Erro no rand!\n");
     	exit(1);
	}
    end *= n;

    // ... and ignore results from rand() that fall above that limit.
    // (Worst case the loop condition should succeed 50% of the time,
    // so we can expect to bail out of this loop pretty quickly.)
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
}

void copyArray() {
	for (i = 0; i < NELEMS(sortArray); i++){
		sortArray[i] = originalArray[i];
	}
}

void seedArrays(){
	int i;

	for (i = 0; i < NELEMS(sortArray); i++){
		originalArray[i] = randint(MAX_NUMBER);
	}

	copyArray();
}

void printSortArray() {
	for (i = 0; i < NELEMS(sortArray); i++){
		printf("| %d ", sortArray[i]);
	}
	printf("|\n");
}

#include "algorithms.h"
