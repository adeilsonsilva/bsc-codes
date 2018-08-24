#include <cstdio>
#include <cmath>
#include<vector>

#define MAXKEYS 32
#define MAXDIR 20
#define MAXCOMBS 10000

using namespace std;

typedef struct Director{
	unsigned int keys;
	int keyNum;
}Director;

typedef struct Combination{
    unsigned int keys1;
    unsigned int keys2;
}Combination;

int main (int argc, char const *argv[])
{
	int M = 0, T = 0, C = 0, D = 0;
	scanf(" %d", &T);

	for(int i = 0; i < T; i++)
	{
		scanf(" %d %d", &M, &D);
		unsigned int bitmask = 0b00000000000000000000000000000000;
		Director directors[D];
		vector<Combination> combinations;

		for(int dir = 0; dir < D; dir++)
		{
			scanf(" %d", &C);
			directors[dir].keyNum = C;
			directors[dir].keys = bitmask;

			for(int k = 0; k < C; k++)
			{
				int key;
				scanf(" %d", &key);
				directors[dir].keys |= (1u << key-1);	
			}
		}
		unsigned int bits = pow(2, D) - 1;
		unsigned int comp = 0, k2 = 0, k1 = 0,  k = 0;
		Combination combAux;

		while(k2 != (bits+1u))
		{
			comp = k2;
			k1 = 0;
			k = 0;
			
			for(int j = D-1; j >= 0; j--)
			{
				if ((comp >> j) & 1)
				{
					k1 |= directors[j].keys;
				}
			}

			if(__builtin_popcount(k1) >= M)
			{
				combAux.keys1 = __builtin_popcount(k1);
				combAux.keys2 = __builtin_popcount(k2);
				combinations.push_back(combAux);
			}

			k2 += 1u;
		}
		
		k = 0;
		for(int j = 1; j < combinations.size(); j++){
			if(combinations[j].keys1 < combinations[k].keys1){
				k = j;
			}else if((combinations[j].keys1 == combinations[k].keys1) && (combinations[j].keys2 < combinations[k].keys2)){
				k = j;
			}
		}

		(combinations.empty()) ? printf("Desastre!\n") : printf("%d\n", combinations[k].keys2);
	}
	return 0;
}
