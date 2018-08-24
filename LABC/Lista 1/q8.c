#include <stdio.h>

int main()
{
  float m1,m2,m3,m4;
  
  printf("Digite as 4 notas bimestrais:\n");
  scanf("%f %f %f %f", &m1,&m2,&m3,&m4);
  printf("A media e: %.2f", (m1+m2+m3+m4)/4);
  return 0;
}
