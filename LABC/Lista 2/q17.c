#include <stdio.h>

int main()
{
	float peso, altura, imc;
	
	printf("Digite seu peso: ");
	scanf("%f", &peso);
	printf("\nDigite sua altura: ");
	scanf("%f", &altura);
	
	imc=peso/(altura*altura);
	
	if(imc <=18.5)
	  printf("\nAbaixo do peso!");
	  
	else if((imc >= 18.6) && (imc <=24.9))
	  printf("\nSaudável!");
	  
	else if((imc >= 25) && (imc <= 29.9))
	  printf("\nPeso em excesso!");
	  
	else if((imc >= 30) && (imc <= 34.9))
	  printf("\nObesidade Grau I!");	
	  
	else if((imc >= 35) && (imc <= 39.9))
	  printf("\nObesidade Grau II (severa)!");
	  
	else if(imc >= 40)
	  printf("\nObesidade Grau III (mórbida)!");
	
	return 0;
}
