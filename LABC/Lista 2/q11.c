#include <stdio.h>

int main()
{
	float idade, tempo_trabalho;
	
	printf("Digite sua idade: ");
	scanf("%f", &idade);
	printf("\nDigite o tempo de serviço: ");
	scanf("%f", &tempo_trabalho);
	
	if(((idade>=65) || (tempo_trabalho >= 30)) || ((idade>=60) && (tempo_trabalho>=25)))
	   printf("\nVocê pode se aposentar!");
	else
	   printf("\nVocê NÃO pode se aposentar!");
	   
	return 0;
}
