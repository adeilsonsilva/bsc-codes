#include <stdio.h>

int main()
{
  float metro;
  float centimetro;

  printf("Conversor metros ~> centimetros\n");
  printf("\nDigite o numero a ser convertido:");
  scanf("%f", &metro);
  centimetro=metro*100;
  printf("%.2f metros equivalem a %.2f centimetros\n", metro,centimetro);
  return 0;
}
