#include <stdio.h>

int pot (int x, int y)
{
	int aux=1;
	int i;
	 for (i=0;i!=y;i++)
	 {
		aux=aux*x;
	 }
   	return aux;
}

int main ()
{
	int z,w=0;
	printf("Digite dois numeros inteiros POSITIVOS: ");
	scanf("%d %d", &z,&w);
	printf("O resultado E: %d", pot(z,w));
	return 0;
}
