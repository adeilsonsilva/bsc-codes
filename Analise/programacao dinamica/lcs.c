#include <stdio.h>
#include <string.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(int argc, char *argv[]){
	char X[] = {'A', 'X', 'A', 'C', 'E', 'B'};
	char Y[] = {'A', 'X', 'A', 'C', 'E', 'B', 'E', 'B'};

	int i, m, n, j;

	n = strlen(X);
	m = strlen(Y);

	int LCS[n+1][m+1];

	for(i=0; i <= n; i++){
		LCS[i][0] = 0;
	}
	for(i=0; i <= m; i++){
		LCS[0][i] = 0;	
	}

	for(i=1; i<=n; i++){
		for(j=1; j <=m; j++){
			if(X[i-1] == Y[j-1]){
				LCS[i][j] = 1 + LCS[i-1][j-1];	
			}else {
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);	
			}
		}	
	}
	// for(i=0; i < n+1; i++){
	// 	for(j=0; j < m+1; j++){
	// 		printf("%d %d: %d\n", i, j, LCS[i][j]);	
	// 	}
	// }

	printf("A maior subsequência comum tem tamanho %d\n", LCS[n][m]);

	return 0;	
}
