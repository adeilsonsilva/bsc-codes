#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>

#define MAXNAME 16
#define MAXPOINTS 12
#define MAXPLAYERS 1000

typedef struct player
{
	char name[MAXNAME];
	int points;
} player;

// int comparison (const player& a, const player& b){
// 	int ret = b.points - a.points;
// 	if (ret != 0 )
// 	{
// 		return ret;
// 	}
//     return strcmp(a.name, b.name);
// }

int comparison(const void * p1, const void * p2)
{
  int ret = ((player *)p2)->points - ((player *)p1)->points;
  if (ret != 0)
    return ret;
  return strcmp(((player *)p1)->name, ((player *)p2)->name);
}

player Players[MAXPLAYERS];
int Points[MAXPOINTS] = {0};

int main(int argc, char const *argv[])
{
	int numPlayers = 0, test = 0, i = 0, j = 0, pos = 0, lastPoints = 0, qtd = 0, pts = 0, least = 99999999, greater = -99999999, p = 0;

	while(1)
	{
		/* Data input */
		scanf(" %d", &numPlayers);
		if (numPlayers == 0){ break; }
		qtd = 1;
		for (i = 0; i < numPlayers; i++)
		{
			scanf("%s", Players[i].name);
			p = pts = 0; least = 99999999; greater = -99999999;
			for (j = 0; j < MAXPOINTS; j++)
			{
				scanf(" %d", &p);
				if (p < least)
					least = p;
				if (p > greater)
					greater = p;
				pts += p;
			}
			Players[i].points = pts - greater - least;
			// std::sort(Points, Points+MAXPOINTS);
			// Players[i].points = std::accumulate(Points+1,Points+(MAXPOINTS-1),0);
		}

		/*Processing */
		qsort(Players, numPlayers, sizeof(player), comparison);

		/* Data output */
		printf("Teste %d\n", ++test);
		for (pos = 0, i = 0; i < numPlayers; i++)
		{
			if (Players[i].points != lastPoints)
			{
				pos += qtd;
				qtd = 0;
			}
			printf("%d %d %s\n", pos, Players[i].points, Players[i].name);
			lastPoints = Players[i].points;
			qtd++;
		}
		printf("\n");
	}

	return 0;
}