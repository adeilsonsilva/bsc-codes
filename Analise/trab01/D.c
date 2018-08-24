#include <stdio.h>
#include <stdbool.h>

/* Functions declaration */
int part(int (*sortArray)[], int a, int b);
void quickSort(int (*sortArray)[], int a, int b);
bool binarySearch(int (*searchArray)[], int number, int begin, int end);

int main(int argc, char const *argv[])
{
	int N = 0, number = 0, i = 0;
	scanf("%d", &N);
	int prime[N];
	for (i = 0; i < N; i++)
	{
		scanf("%d", &number);
		prime[i] = number;
	}

	quickSort(&prime, 0, N - 1);

	while(scanf("%d",&number) == 1){
		binarySearch(&prime, number, 0, N - 1) ? printf("sim\n") : printf("nao\n");
	}

	return 0;
}

int part(int (*sortArray)[], int a, int b)
{
	int v, l, r, y, i;
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
	int p, i;
	if (a < b){
		p = part(sortArray, a, b);
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