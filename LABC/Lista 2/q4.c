#include <stdio.h>

int main()
{
	float sal, novo_sal;
	
	printf("Digite seu salario:");
	scanf("%f", &sal);
	
	novo_sal=sal+(sal*25)/100;
	printf("O novo salario e de R$%.2f", novo_sal);
	return 0;
}
