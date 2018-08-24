#include <stdio.h>

int main()
{
  char s1[200];
  char s2[200];
  scanf("%s%s", s1,s2);
  printf("%s\n%s\n%c %c", s1,s2,s1[1],s2[1]);
  return 0;
}
