#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main ()
{
  int i=0,o=0,x,a,b;
  char nome[MAX];
  char teste[MAX];
  char aux[MAX];
   for (i=0;i==MAX;i++)
    {
     nome[i]=0;
     teste[i]=0;
    }
   printf("Digite a palavra a ser testada:\n");
   scanf("%s",nome);
   strcpy(aux,nome);
   o=strlen(nome)-1;
    for (i=0;nome[i]!='\0';i++)
     {
        teste[o]=nome[i]; 
        o--; 
	   if(teste[o]==aux[i])
		{
		 printf("1");
		 break;
		} 
	   else if(teste[o]!=aux[i])
	    {
		 printf("0");
		 break;
		}
     } 
     teste[i]='\0';

 /*    x=strcmp(nome,teste);
     printf("%s",teste);
     if(x==0)
      printf("0");
     else if(x!=0)
      printf("1"); */
    
    return 0;
}
