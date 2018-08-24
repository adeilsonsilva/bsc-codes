#include <stdio.h>

int main()
{
  float altura;
  float peso_ideal;

  printf("Digite sua altura:");
  scanf("%f", &altura);
  peso_ideal=(72.7*altura)-58;
  printf("\nSeu peso ideal e:%.2f\n", peso_ideal);
  return 0;
}
