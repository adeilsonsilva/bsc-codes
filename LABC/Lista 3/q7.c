#include <stdio.h>

int main()
{
  int num, i, ctl;

  printf("Digite o numero a ser testado: ");
  scanf("%d", &num);

  for(ctl=0,i=1; i<=num; i++){
     if(num % i==0){
       ctl++; 
   }       
  }

  if(ctl == 2)
    printf("O numero %d e primo.", num);
  else
    printf("O numero %d NAO e primo.", num);

  return 0;
}
