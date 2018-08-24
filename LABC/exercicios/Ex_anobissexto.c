#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int ano=0;
  printf("Digite o ano a ser calculado:\n");
  scanf("%d", &ano);
  if ((ano%4==0 && ano%100!=0) || ano%400==0)
  {
   printf("O ano %d e bissexto.", ano); 
  }
  else
  {
   printf("O ano %d nao e bissexto.", ano);
  }
  return 0;
  }
