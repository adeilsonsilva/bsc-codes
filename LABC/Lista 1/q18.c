#include <stdio.h>

int main()
{
  float peso;
  float excesso;
  float multa;

  printf("Digite o peso:");
  scanf("%f", &peso);

  excesso=0;
  multa=0;

  if(peso>50)
   {
     excesso=peso-50;
     multa=excesso*4;
   }

  printf("Para o peso de %.2fkg, o excesso foi de %.2fkg gerando uma multa de R$%.2f.\n", peso, excesso, multa);
  return 0;

}
