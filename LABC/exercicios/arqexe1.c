#include <stdio.h>
#define MAX 1000

int main ()
{
  char CODIGO[10],NOME[MAX];
  int CH,x;
  float NOTA;
  FILE *arq;
  
  printf("Digite o nome do arquivo a ser criado:\n");
  gets(NOME);
  arq=fopen(NOME, "w");
   
   while(x!=0)
   {
    printf("\nDigite o CODIGO da disciplina:\n");
    scanf("%s", CODIGO); 
    printf("\nDigite a CARGA HORÁRIA da disciplina:\n");
    scanf("%d", &CH);
    printf("\nDigite a NOTA FINAL da disciplina:\n");
    scanf("%f", &NOTA);
    fprintf(arq, "%s %d %f", CODIGO,CH,NOTA);
    printf("\nDigite 0 para encerrar e 1 para continuar.\n");
    scanf("%d", &x);
   }  

 fclose(arq);
 return 0;

}
