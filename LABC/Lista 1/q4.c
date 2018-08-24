#include <stdio.h>

int main()
{
  int x=0;
  char y;
  
  printf("Digite um caracter:\n");
  scanf("%c", &y);
  x=y;
  printf("%c = %d", y,x);
  return 0;
}
