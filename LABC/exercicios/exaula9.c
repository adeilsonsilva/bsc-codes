#include <stdio.h>
#include <stdlib.h>

FILE *arq;

struct reg_func
{
  char nome[20];
  int idade;
  float salario;
};

void reg_dados()
{
  struct reg_func funcionarios;
 
  arq=fopen("registrodefuncionarios2.txt","ab");
  
     printf("Digite o nome do funcionario:\n");
     scanf("%s", funcionarios.nome);
     printf("\nDigite a idade do funcionario:\n");
     scanf("%d", &funcionarios.idade);
     printf("\nDigite o salario do funcionario:\n");
     scanf("%f", &funcionarios.salario);
     fwrite(&funcionarios,sizeof(struct reg_func),1,arq);
  
  fclose(arq);

}

void le_dados()
{
  struct reg_func funcionarios;
  arq=fopen("registrodefuncionarios2.txt","rb");
   if(arq!=NULL)
    {
     while(!feof(arq))
       {
           fread(&funcionarios,sizeof(struct reg_func),1,arq);
           printf("\nNome:\n%s", funcionarios.nome);
           printf("\nIdade:\n%d", funcionarios.idade);
           printf("\nSalario:\n%.2f", funcionarios.salario);
           
       }
      
       fclose(arq);       
     } 
   else if(arq==NULL)
    {
	  printf("Não existe registro de funcionários\n");	
	}  

}

int main()
{

  int resp=0;
 
    system("clear");
    printf("Digite 1 para cadastro de funcionarios\nDigite 2 para saber os funcionarios ja cadastrados\nDigite 3 para sair\n");
    scanf("%d", &resp);
  
     if(resp==1)
      {
        system("clear");
        reg_dados();  
      }
     else if(resp==2)
      {
        system("clear");
        le_dados();
      } 

  return 0;  
}
