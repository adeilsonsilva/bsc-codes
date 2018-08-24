#include <stdio.h>

int main()
{
	int n1,n2,n3,res;
	
	printf("Digite tres numeros:");
	scanf("%d %d %d", &n1,&n2,&n3);
	
	res=(n1*n1) + (n2*n2) + (n3*n3);
	printf("\nResultado:%d", res);
	return 0;
}
