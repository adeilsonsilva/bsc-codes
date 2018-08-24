#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int a,b=0;
  a=atoi(argv[1]);
  b=atoi(argv[2]);
  printf("A soma de %d + %d e: %d\n", a,b,a+b);
  return 0;
}
