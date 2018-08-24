#include <cstdio>
#include <cstring>
#define FLAG 9999
#define MAXBRIDGES 10000
#define MAXPILLARS 1000

int Mat[MAXPILLARS][MAXBRIDGES], Visited[MAXBRIDGES], Distance[MAXBRIDGES];

int main(int argc, char *argv[])
{
	int i = 0, j = 0, k = 0, N = 0, M = 0, sum = 0, holes = 0;

	/* Data input */
	scanf("%d %d", &N, &M);
	N+=2;

	memset(Mat, 0x3f, sizeof(Mat));
	memset(Distance, 0x3f, sizeof(Distance));
  	memset(Visited, 0, sizeof(Visited));
  	Distance[0] = 0;

	/* Read number of holes */
	for(k = 0; k < M; k++)
	{
		//printf("I: %d\n", k);
		scanf("%d %d %d", &i, &j, &holes);
		Mat[i][j] = Mat[j][i] = holes;
	}
	//printf("aaa\n");
	while(1)
	{
		int pillar = -1;
		for(i = 0; i < N; i++)
		{
			if(!Visited[i] && (pillar == -1 || Distance[i] < Distance[pillar])){ pillar = i; }
		}

		if (pillar == -1){ break; }
		Visited[pillar] = 1;

		for(i = 0; i < N; i++)
		{
		  	if(Distance[pillar] + Mat[pillar][i] < Distance[i]){
				Distance[i] = Distance[pillar] + Mat[pillar][i];
			}
		}
	}

	printf("%d\n", Distance[N-1]);
}