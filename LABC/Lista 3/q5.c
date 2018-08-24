#include <stdio.h>

int main()
{
  int n, i;
  int num;

  printf("Digite um numero: ");
  scanf("%d", &n);

  for(i=0, num=0;i<n; i++, num=num+2){
    printf("\n%d", num);
  }

  return 0;
}
