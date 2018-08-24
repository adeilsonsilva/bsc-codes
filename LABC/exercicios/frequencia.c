#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pessoas
{
  char nome[20];
  char sobrenome[20];
};

int main(int argc, char **argv)
{
	FILE *arq;
	struct pessoas registro[1000];
	char arquivo[150];
	char *aux1;
	char *aux2;
	int ctrl1,ctrl2,i=0,j=0,t=0;
			
		scanf("%s", arquivo);
		arq=fopen(arquivo, "r");

		 while(!feof(arq))
		  {
			 fread(&arquivo, sizeof(registro),1,arq);
			  for(i=0;i<1000;i++)
			   {	
				aux1=registro[i].nome;
				aux2=registro[i].sobrenome;
				j++;
				 if(i>0) 
				  {
				   ctrl1=strcmp(aux1, aux1-1);
				   if(!ctrl1)
					   {
					 	 ctrl2=strcmp(aux2, aux2-1);
					 	  0?ctrl2: t++; 
					   }	 
			       }
			    }
			}
		  
		 fclose(arq);		  
	printf("%d\n",j-t);
	
	return 0;
	
}
