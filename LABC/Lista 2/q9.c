#include <stdio.h>

int main()
{
	float sal, emp, aux;
	
	printf("Digite o salario: ");
	scanf("%f", &sal);
	printf("Digite o valor da prestação: ");
	scanf("%f", &emp);
	
	aux=(sal*20)/100;
	
	if(emp > aux)
	  printf("Emprestimo nao concedido!\n");
	else
	  printf("Emprestimo Concedido!\n");	  
	return 0;	
}
