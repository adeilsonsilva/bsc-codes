#include <iostream>
#include <cstring>

#define MAXSIZE 20

using namespace std;

int graph[MAXSIZE][MAXSIZE];
int part[MAXSIZE];

int maximum(int a, int b);
int Clique(int lim, int n);

int main(int argc, char const *argv[])
{
	int N = 0, k = 0, test = 0;

	while(1)
	{
		cin >> N;
		cin.ignore();
		if(N == 0){break;}

		memset(graph, 0, sizeof(graph));
		memset(part, 0, sizeof(part));
		for (int i = 0; i < N; i++)
		{
			while(1)
			{
				cin >> k;
				cin.ignore();
				if (k == 0){break;}
				graph[i][k-1] = graph[k-1][i] = 1;
			}
		}
		cout << "Teste " << ++test << endl << Clique(0, N) << endl << endl;
	}
	return 0;
}

int maximum(int a, int b){
	return a >= b ? a : b;
}

int Clique(int lim, int n){
	int max = 0;

	if (lim >= n) return 0;

	max = Clique(lim + 1, n);

	for (int i = 0; i < n; i++){
		if (part[i] && graph[i][lim] == 1){
			return max;
		}
	}

	part[lim] = 1;
	int maxSet = 1 + Clique(lim + 1, n);
	part[lim] = 0;
	return maximum(max, maxSet);
}