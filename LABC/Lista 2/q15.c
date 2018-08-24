#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, k, resp[5], perg[5], resp_lida, acertos=0;
	unsigned int x,y;
	
	srand( (unsigned) time(NULL));
			
    printf("Responda as questões a seguir:");
	
	for(i=0; i<5; i++){
		k= 1+ (rand() % 100);
		perg[i]=1+ (rand() % 100);
		resp[i]=k + perg[i];
		printf("\n%d + %d=", k,perg[i]);
		scanf("%d", &resp_lida);
		if(resp_lida == resp[i])
		   acertos++;		
	}
	
	printf("\nRespostas:");
	
	for(i=0; i<5 ; i++){
		x=resp[i]-perg[i];
		y=resp[i]-x;
		printf("\n%d + %d=%d", x, y, resp[i]);		
	}
	
	printf("\nNúmero de acertos: %d", acertos);
	return 0;	
}
