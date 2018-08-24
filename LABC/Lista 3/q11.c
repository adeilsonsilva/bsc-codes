#include <stdio.h>

int main()
{
  int i;
  char str[1000];

  printf("Digite a string: ");
  scanf("%s", str);

  i=0;
  while(i<1000){
    if(str[i]=='0'){
      str[i]='1';
    }
    i++;
  }

  printf("A string de saida e: %s", str);
  return 0;
}
