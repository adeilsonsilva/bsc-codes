#include <stdio.h>

int main()
{
  int i, qtd;
  char str[1000];

  printf("Digite a string: ");
  scanf("%s", str);

  for(qtd=i=0;i<1000;i++){
     if(str[i]=='1'){
       qtd++;
   }
  }

  printf("A string digitada possui %d caracteres '1'.", qtd);
  return 0;
}
