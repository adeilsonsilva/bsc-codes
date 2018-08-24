#include <stdio.h>

int main()
{
  float cels;
  float faren;

  printf("Digite a temperatura em Celsius:");
  scanf("%f", &cels);
  faren=(cels*1.8)+32;
  printf("\n%.2f graus Celsius equivalem a %.2f Farenheits.\n",cels, faren);
  return 0;
}
