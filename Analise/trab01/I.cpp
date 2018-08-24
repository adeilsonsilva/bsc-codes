#include <cstdio>
#include <cstring>

#define MAXVAL 999999

int main(int argc, char const *argv[])
{
	int price = 0, numCoins = 0;

	while(1)
	{
		scanf(" %d", &price);
		if(price == 0){break;}
		scanf(" %d", &numCoins);
		int coins[numCoins];
		int minCoins[price+1];
		for (int i = 0; i < numCoins; i++)
		{
			scanf(" %d", &coins[i]);
		}

		memset(minCoins, 0, sizeof minCoins);
		for (int value = 1; value < price+1; value++)
		{
			int min = MAXVAL;
			for(int i = 0;  i < numCoins; i++){
				if((coins[i] <= value) && (minCoins[value - coins[i]] + 1 < min)){
					min = minCoins[value - coins[i]] + 1;
				}
			}
			minCoins[value] = min;
		}

		minCoins[price] > 0 && minCoins[price] != MAXVAL ? printf("%d\n", minCoins[price]) : printf("Impossivel\n");
	}
	return 0;
}