#include <stdio.h>

int main()
{
  float salario_total;
  float salario_hora;
  int horas_trabalho;

  printf("Digite o seu salario por hora:");
  scanf("%f", &salario_hora);
  printf("Digite o numero de horas trabalhadas por mes:");
  scanf("%d", &horas_trabalho);
  salario_total=salario_hora*horas_trabalho;
  printf("\nSeu salario mensal e de R$%.2f.\n", salario_total);
  return 0;

}
