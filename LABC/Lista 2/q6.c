#include <stdio.h>

int main()
{
	float sal, sal_liq, sal_brt;
	int dias;
	
	sal=30;
	printf("Digite o numero de dias trabalhados:");
	scanf("%d", &dias);
	
	sal_brt=sal*dias;
	sal_liq=sal_brt-(sal_brt*8)/100;
	printf("Quantia a ser paga:R$%.2f", sal_liq);
	return 0;	
}
