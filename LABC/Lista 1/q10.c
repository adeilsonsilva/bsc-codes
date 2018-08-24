#include <stdio.h>

int main()
{
  float raio=0;
  float pi=3.141592;
  float area=0;
  scanf("%f", &raio);
  area= pi * (raio*raio);
  printf("A area e: %.2f", area);
  return 0;
  
}
