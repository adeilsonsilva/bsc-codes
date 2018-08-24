#include <stdio.h>
int main() 
{
  float v[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  int i;
  float *p;
  for (i=0; i<9; i++)
     printf("%.1f ", v[i]);
  printf("\n");
   p=&v[0]; //p=&v[0] é equivalente a p=v, ou seja, os dois apontam pro INĨCIO do vetor
  for (i=0; i<9; i++)
     printf("%.1f ", *(p+i));
  printf("\n");
  for (i=0, p=v; i<9; i++, p++)
     printf("%.1f ", *p);
  printf("\n");
  return 0;
}
