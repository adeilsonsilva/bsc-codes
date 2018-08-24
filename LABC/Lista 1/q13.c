#include <stdio.h>

int main()
{
  float faren;
  float cels;

  printf("Digite a temperatura em Farenheit:");
  scanf("%f", &faren);
  cels=(5*(faren-32)/9);
  printf("\n%.2f Farenheits equivalem a %.2f graus Celsius.\n", faren, cels);
  return 0;

}
