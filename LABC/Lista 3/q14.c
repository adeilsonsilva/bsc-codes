#include <stdio.h>

int main()
{
  int valores[10];
  int i, soma;

  for(soma=i=0;i<10;i++){
     printf("Digite um valor: \n");
     scanf("%d", &valores[i]);
     soma=soma+valores[i];
  }
 
  printf("Soma: %d", soma);
  return 0;
}
