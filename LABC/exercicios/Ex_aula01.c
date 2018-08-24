#include <stdlib.h>
#include <stdio.h>

int main ()
{
 int num,aux1,aux2,aux3,aux4,aux5=0;
 printf("Digite um número com 5 dígitos:\n");
 scanf("%d", &num);
  aux1=num/10000; 
  num=num%10000;
  aux2=num/1000;
  num=num%1000;
  aux3=num/100;
  num=num%100;
  aux4=num/10;
  aux5=num%10;
 printf("Os números digitados foram:\n   %d   %d   %d   %d   %d", aux1,aux2,aux3,aux4,aux5);
 return 0;
}
