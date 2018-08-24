#include <stdio.h>

int main()
{
  float tam_arq_convertido, veloc_net_convertida, veloc_net, tam_arq, tempo_estimado;

  printf("Digite o tamanho do arquivo e a velocidade do link:");
  scanf("%f %f", &tam_arq, &veloc_net);

  tam_arq_convertido=tam_arq*8;
  veloc_net_convertida=veloc_net*60;
  tempo_estimado=tam_arq_convertido/veloc_net_convertida;

  printf("\nO tempo estimado de Download e de %.2f\n minutos.", tempo_estimado);
  return 0;
}
