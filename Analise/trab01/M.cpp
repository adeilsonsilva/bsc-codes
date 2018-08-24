#include <cstdio>

using namespace std;

int maximum(int a, int b);

int main(int argc, char *argv[])
{
	int N = 0;

	while(1)
	{
		scanf(" %d", &N);

		if(N == 0){break;}

		int array[N];
		int maxTotal = 0, maxNow = 0, num = 0;
		scanf(" %d", &num);
		maxNow = maxTotal = num;
		for(int i = 1; i < N; i++)
		{
			scanf(" %d", &num);
			maxNow = maximum(num, maxNow + num);
			maxTotal = maximum(maxTotal, maxNow);
		}

	    if(maxTotal <= 0){
	    	printf("Losing streak.\n");
	    }else{
	    	printf("The maximum winning streak is %d.\n", maxTotal);
	    }
	}
	return 0;
}

int maximum(int a, int b){
	return a >= b ? a : b;
}