#include <stdio.h>

int main()
{
  int i, soma, num;

  for(soma=num=i=0;i<50;i++, num=num+2){
     soma=soma+num;
  }

  printf("\nSoma: %d", soma);
  return 0;
}
