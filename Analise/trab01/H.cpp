#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
	int numPhrases = 0, cardLength = 0, chars = 0, reps = 0, test = 0, i = 0, j = 0;

	while(1)
	{
		/* Data input */
		scanf("%d %d", &cardLength, &numPhrases);
		if (cardLength == 0){break;}
		int Out[numPhrases+1][cardLength+1];
		int numChars[numPhrases+1];
		int numReps[numPhrases+1];
		for (i = 1; i < numPhrases+1; i++)
		{
			scanf("%d %d", &chars, &reps);
			numChars[i] = chars;
			numReps[i] = reps;
		}

		/* Knapsack problem */
		// for (i = 0; i < numPhrases+1; i++){ Out[i][0] = 0; }
		// for (i = 0; i < cardLength+1; i++){ Out[0][i] = 0; }
		memset(Out, 0, sizeof Out);

		for (i = 1; i < numPhrases+1; i++)
		{
			for (j = 1; j < cardLength+1; j++)
			{
				if (numChars[i] > j){
					Out[i][j] = Out[i-1][j];
				}else{
					if ((numReps[i] + Out[i-1][j-numChars[i]]) > Out[i-1][j]){
						Out[i][j] = numReps[i] + Out[i-1][j-numChars[i]];
					} else {
						Out[i][j] = Out[i-1][j];
					}
				}
			}
		}

		/* Data output */
		printf("Teste %d\n%d\n\n", ++test, Out[numPhrases][cardLength]);
	}
	return 0;
}