#include <stdio.h>

int main()
{
  int num, a=0, b=1, aux=0;

  scanf("%d", &num);
  printf(" %d %d", a,b);

  while(aux<num){
     aux=a+b;
     a=b;
     b=aux;
     printf(" %d", aux);
  }
  
  return 0;  
}

