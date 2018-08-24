#include <stdio.h>

int main()
{
	int num, aux, num_inv, resto;
	
	printf("Digite o numero a ser invertido: ");
	scanf("%d", &num);
    
    aux=num;
    while(aux>0){
		resto=aux%10;
		num_inv=(10*num_inv)+resto;
		aux= aux/10;		
	}
    
	printf("Resultado: %d", num_inv);
	return 0;
}
