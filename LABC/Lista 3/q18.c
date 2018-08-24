#include <stdio.h>

int main()
{
  int num=2520, i, soma=0;

  while(soma!=20){
   soma=0;
   num++;
   for(i=1;i!=20;i++){
     if(num%i == 0){
       soma++;
     }
   }
  }

  printf("%d", num);
  return 0;
}
