#include <stdio.h>

int main()
{
  float altura, peso_ideal;
  char sexo;

  printf("Digite sua altura e o sexo(M/F):");
  scanf("%f %c", &altura, &sexo);
  
  if(sexo == 'M')
    peso_ideal=(72.7*altura)-58;
  
  if(sexo == 'F')
    peso_ideal=(62.1*altura)-44.7; 
   
  printf("Seu peso ideal e:%.2f\n", peso_ideal);
  return 0;
}
