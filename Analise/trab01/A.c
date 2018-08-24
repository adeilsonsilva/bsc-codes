#include <stdio.h>
#include <stdbool.h>

/* Functions declaration */
void buildMaxHeap(int (*sortArray)[], int size);
void arrangeHeap(int (*sortArray)[], int a, int n);
void quickSort(int (*sortArray)[], int a, int b);
bool binarySearch(int (*searchArray)[], int number, int begin, int end);

int main(int argc, char *argv[])
{
	int i = 0, N = 0, M = 0;

	/* Data input */
	scanf("%d", &N);
	int Queue[N];
	for(i = 0; i < N; i++){
		scanf("%d", &Queue[i]);
	}

	scanf("%d", &M);
	int Left[M];
	for(i = 0; i < M; i++){
		scanf("%d", &Left[i]);
	}

	/* Processing */
	/* Sort the array of 'people' that left the queue */
	quickSort(&Left, 0, M - 1);


	/* Data output */
	for (i = 0; i < N; i++){
		/* Binary search the sorted array of people that 'left' -> reduces the complexity */
		if (!binarySearch(&Left, Queue[i], 0, M - 1)){
			printf("%d ", Queue[i]);
		}
	}
	printf("\n");
}

int particiona(int (*sortArray)[], int a, int b) {
	int v, l, r, y;

	v = (*sortArray)[a];
	l = a;
	r = b;

	while(l < r){
		while((*sortArray)[l] <= v && l <= b){
			l++;
		}
		while((*sortArray)[r] > v && r >= a){
			r--;
		}
		if (l < r){
			y = (*sortArray)[l];
			(*sortArray)[l] = (*sortArray)[r];
			(*sortArray)[r] = y;
		}
	}

	(*sortArray)[a] = (*sortArray)[r];
	(*sortArray)[r] = v;

	return r;
}

void quickSort(int (*sortArray)[], int a, int b) {
	int p;

	if (a < b){
		p = particiona(sortArray, a, b);
		quickSort(sortArray, a, p-1);
		quickSort(sortArray, p+1, b);
	}
}

bool binarySearch(int (*searchArray)[], int number, int begin, int end)
{
	int mid;
	if(end < begin){
		return false;
	}else{
		mid = begin + ((end - begin) / 2);
		if ((*searchArray)[mid] > number){
			return binarySearch(searchArray, number, begin, mid - 1);
		}else if ((*searchArray)[mid] < number){
			return binarySearch(searchArray, number, mid + 1, end);
		}else{
			return true;
		}
	}
}