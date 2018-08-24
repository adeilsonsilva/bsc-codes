#include <stdio.h>

int main()
{
	float altura, peso_ideal;
	char sexo;
	
	printf("Digite seu sexo [M/F] seguido pela sua altura: ");
	scanf("%c %f", &sexo, &altura);
	
	if((sexo == 'm') || (sexo == 'M'))
	   peso_ideal=(72.7 * altura) - 58;
	   
	else if((sexo == 'f') || (sexo == 'F'))
	   peso_ideal=(62.1*altura) - 44.7;
	
	printf("\nO seu peso ideal é: %.2f", peso_ideal);
	return 0;
}
