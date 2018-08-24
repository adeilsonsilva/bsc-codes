#include <stdio.h>

int main()
{
	int a;
	
	printf("Digite um numero:");
	scanf("%d", &a);
	printf("\nAntecessor:%d\nSucessor:%d", a-1,a+1);
	return 0;	
}
