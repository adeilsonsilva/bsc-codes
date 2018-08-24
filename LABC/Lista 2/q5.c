#include <stdio.h>


int main()
{
	float premio,g1,g2,g3;
	
	premio=780.000;
	g1=(premio*46)/100;
	g2=(premio*32)/100;
	g3=premio-g1-g2;
	printf("\nGanhador 1:R$%.3f \nGanhador 2:R$%.3f \nGanhador 3:R$%.3f", g1,g2,g3);
	return 0;	
}
