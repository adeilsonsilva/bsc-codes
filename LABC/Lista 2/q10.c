#include <stdio.h>

int main()
{
	int a,b, opcao;
	
	printf("1 - Soma de dois numeros.\n");
	printf("2 - Diferença entre dois numeros (maior pelo menor).\n");
	printf("3 - Produto entre dois numeros.\n");
	printf("4 - Divisao entre dois numeros (denominador nao pode ser zero)\n");
	printf("Escolha: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
		   printf("Digite os valores a serem calculados: ");
		   scanf("%d %d", &a, &b);
		   printf("\nResultado: %d", a+b);
		   break;
		 
		 case 2:
		   printf("Digite os valores a serem calculados: ");
		   scanf("%d %d", &a, &b);
		   printf("\nResultado: %d", a-b);
		   break;	
		 
		 case 3:
		   printf("Digite os valores a serem calculados: ");
		   scanf("%d %d", &a, &b);
		   printf("\nResultado: %d", a*b);	
		   break;
		   
		 case 4:
		   printf("Digite os valores a serem calculados: ");
		   scanf("%d %d", &a, &b);
		   printf("\nResultado: %d", a/b); 
		   break; 
		   
		 default:
		    printf("\n*******OPCAO INVALIDA!*******");
		    break;
		    
	}
	
	return 0;
	
}
