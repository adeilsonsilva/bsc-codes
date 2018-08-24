#include <stdio.h>

int main()
{
	float h,a,b;
	
	printf("Digite os valores dos catetos:");
	scanf("%f %f", &a,&b);
	
	h=(a*a)+(b*b);
	printf("O valor da hipotenusa e: %.2f\n", h);
	return 0;
}
