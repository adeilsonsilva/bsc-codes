#include <stdio.h>

int main()
{
  int a=0, soma=0, b=1, aux=0;

  while(aux<4000000){
    aux=a+b;
    a=b;
    b=aux;
    if(aux%2==0){
     soma=soma+aux;
    }
  }

  printf("%d", soma);
  return 0;
}
