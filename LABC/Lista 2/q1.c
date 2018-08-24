#include <stdio.h>

int main()
{
	float a,b;
	
	printf("Entre com o numero a ser calculado:");
	scanf("%f", &a);
	b=a*a;
	printf("\nO quadrado do numero %.2f e: %.2f\n", a,b);
	return 0;
	
}
