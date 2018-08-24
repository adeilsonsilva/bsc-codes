#include <stdio.h>

int main()
{
  float salario_hora, salario_total, salario_liquido, horas, ir, inss, sindicato, descontos;

  printf("Digite o seu salario por hora e a quantidade de horas trabalhadas no mes:");
  scanf("%f %f", &salario_hora, &horas);

  salario_total=salario_hora*horas;
  ir=(salario_total*11)/100;
  inss=(salario_total*8)/100;
  sindicato=(salario_total*5)/100;
  descontos=ir+inss+sindicato;
  salario_liquido=salario_total-descontos;

  printf("\n+ Salario Bruto: R$%.2f\n- IR(11%%): R$%.2f\n- INSS(8%%): R$%.2f\n- Sindicato(5%%): R$%.2f\n= Salario Liquido: R$%.2f\n", salario_total, ir, inss, sindicato, salario_liquido);
  return 0;
  
}
