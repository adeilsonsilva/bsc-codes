#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{
	struct dados 
	{
		int cpf;
		char nome[50];
	};
	
	struct dados pessoa[1024];
	printf("Digite CPF:\n");
	scanf("%d", &pessoa.cpf);
	scanf("%s", pessoa.nome);
	
	
	
	
	
}
