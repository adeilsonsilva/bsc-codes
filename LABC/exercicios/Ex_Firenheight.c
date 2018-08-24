#include <stdio.h>
#include <stdlib.h>

int main ()
{
  float C,F=0;
  while (F<=300)
  {
   C=(5.0/9.0)*(F-32);
   printf("%.0f F = %.1f C\n", F,C);
   F=F+20;
  }
  return 0;
}
