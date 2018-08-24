#include <cstdio>
#include <cstring>

#define INFINITE 10000
#define FLAG 999998
#define MAXTABAS 1001
#define MAXBRANCHES 4951

int Find(int i);
int Union(int i,int j);

int Mat[MAXTABAS][MAXBRANCHES], Mat2[MAXTABAS][MAXBRANCHES], Parent[MAXBRANCHES];

int main(int argc, char *argv[])
{
	int test = 1;

	/* Data input */
	while(1)
	{
		int tabaX = 0, tabaY = 0, tabas = 0, branches = 0, impact = 0, min = 0, i = 0, j = 0, k = 0, soma = 0, x1 = 1, y1 = 1;
		scanf(" %d %d", &tabas, &branches);
		if (tabas == 0){break;}

		memset(Mat, INFINITE, sizeof(Mat));
		memset(Mat2, 0, sizeof(Mat2));
		memset(Parent, 0, sizeof(Parent));

		for(i = 0; i < branches; i++)
		{
			scanf(" %d %d %d", &tabaX, &tabaY, &impact);
			Mat[tabaX-1][tabaY-1] = Mat[tabaY-1][tabaX-1] = impact;
			//Mat[tabaX-1][tabaY-1] = impact;
		}

		printf("Teste %d\n", test++);
		k = 0;
		while(k < tabas - 1)
		{
			soma = 0;
			for (i = 0,  min = INFINITE; i < tabas; i++)
			{
				for (j = 0; j < tabas; j++)
				{
					if(min > Mat[i][j]) {
						min = Mat[i][j];
						tabaX = x1 = i;
						tabaY = y1 = j;
					}
				}
			}
			Mat[tabaX][tabaY] = Mat[tabaY][tabaX] = INFINITE;
			int parent1 = Find(tabaX);
			int parent2 = Find(tabaY);
			if(parent1 != parent2){
				Union(parent1, parent2);
				printf("%d %d\n",  tabaX+1,  tabaY+1);	
				Mat2[tabaX][tabaY] = FLAG;
				k++;
			}
		}

		#if 0
		for (i = 0; i < tabas; i++)
		{
			for (j = 0; j < tabas; j++)
			{
				if(Mat2[i][j] == FLAG){
					printf("%d %d\n", i+1, j+1);
				}
			}
		}
		#endif
		printf("\n");
	}
	return 0;
}

int Find(int i)
{
     //if(Parent[i]==-1)return i;
     //return Parent[i] = Find(Parent[i]);
	//while(Parent[i]){
	//	i = Parent[i];
	//}
	//return i;
	int j = i;
	while (Parent[j] && Parent[j] != j) j = Parent[j];
	return j;
}

int Union(int i,int j)
{
    Parent[i] = j;
    return 0;
	//if (i < j) Parent[j] = i;
	//else Parent[i] = j;
}
