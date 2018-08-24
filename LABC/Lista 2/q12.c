#include <stdio.h>
#include <math.h>

int main()
{
	int x,y,z, opcao, aux;
	
	printf("Digite os tres numeros: ");
	scanf("%d %d %d", &x,&y,&z);		
	printf("\n1 - Média Geométrica.");
	printf("\n2 - Média Ponderada.");
	printf("\n3 - Média Harmônica.");
	printf("\n4 - Média Aritmética.");
	printf("\nEscolha uma das opções acima: ");
	scanf("%d", &opcao);

	switch(opcao){
		
		case 1:
		  aux=pow((x*y*z), 1.0/3.0);
		  printf("\nResultado: %d", aux);
		  break;
		  
		case 2:
		  aux=(((x) + (2*y) + (3*z))/6);
		  printf("\nResultado: %d", aux);
		  break;
		
		case 3:
		  aux=(1/((1/x) + (1/y) + (1/z)));
		  printf("\nResultado: %d", aux);
		  break;
		
		case 4:
		  aux=(x+y+z)/3;
		  printf("\nResultado: %d", aux);
		  break;
		
		default:
		  printf("\n#*#*#*#*OPÇÃO INVÁLIDA!#*#*#*#*");
		  break;		
	}
	
   return 0;	
}
