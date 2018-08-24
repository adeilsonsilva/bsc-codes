/* Universidade Federal da Bahia
   Graduação em Ciência da Computação
   MATA40- Estruturas de Dados e Algoritmos I
   Aluno: Adeilson Silva
   Semestre 2013.1   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXVETOR 1023

typedef struct ArvoreBB
{
	int chave;
	struct ArvoreBB *esq;
	struct ArvoreBB *dir;
	
} ArvoreBB;

typedef enum {False, True} boolean;

typedef struct novetor
{
  int n;
  boolean ctrl;
}NoVetor;

NoVetor ArvoreBBVetor[MAXVETOR];
ArvoreBB *arv_rz;
int nnos;


ArvoreBB *InsereNoArvorePonteiro(ArvoreBB *raiz, ArvoreBB *arv, int i); 
void ConsultaNo(ArvoreBB *raiz, int i);
void ImprimeArvorePonteiro(ArvoreBB *raiz); 
void ImprimeIndiceVetor(NoVetor *ArvoreVetor, int i);
void InsereNoArvoreVetor(NoVetor *ArvoreVetor, int j, int i); 
void ImprimeArvoreVetor(NoVetor *ArvoreVetor); 
void ListaChaveEmOrdem(ArvoreBB *raiz, char modo); 
void OrdemDecrescente(ArvoreBB *raiz);
void OrdemCrescente(ArvoreBB *raiz);
void ListaChavePorNivel(NoVetor ArvoreVetor[MAXVETOR], int n);
void ImprimeIndicePorNivelVetor(NoVetor ArvoreVetor[MAXVETOR], int i); 



int main(int argc, char *argv[])
{
   char opr[MAXVETOR], op[MAXVETOR];
   int k,m;

   arv_rz=NULL;
   nnos=0;
   for(m=0;m<MAXVETOR;m++)
    {
	  ArvoreBBVetor[m].ctrl=False;
	  ArvoreBBVetor[m].n=0;	
	}
   
   do
    {
	  scanf(" %[^\n]s",opr);
	  if((opr[0] != 'p') && ((strlen(opr)) == 3 || (strlen(opr)) > 3))
	    sscanf(opr,"%s %d", op, &k);
	  else
	   strcpy(op,opr);  
		 
		  if(op[0] == 'i')
		   {
		      if(!(arv_rz))
		         arv_rz=InsereNoArvorePonteiro(arv_rz, arv_rz, k);		      
		      else
		         InsereNoArvorePonteiro(arv_rz, arv_rz, k);
		         
		      InsereNoArvoreVetor(ArvoreBBVetor, 0, k);
		   }
		  
		  if(op[0] == 'c')
		    ConsultaNo(arv_rz, k);
		  
		  if(op[0] == 'p')
		    ListaChaveEmOrdem(arv_rz, op[2]);
		    
		  if(opr[0] == 'n')
		    ListaChavePorNivel(ArvoreBBVetor, k);
		    
		  if(op[0] == 'q')
		    ImprimeIndiceVetor(ArvoreBBVetor, k);
		    
		  if(opr[0] == 'm')
		    ImprimeIndicePorNivelVetor(ArvoreBBVetor, k); 
	   
		 if(op[0] == 'd')
		   ImprimeArvorePonteiro(arv_rz);
		   
		 if(opr[0]== 'v')
		   ImprimeArvoreVetor(ArvoreBBVetor);       
	
	}while(op[0] != 'e');

   return 0;
	
}

ArvoreBB *InsereNoArvorePonteiro(ArvoreBB *raiz, ArvoreBB *no, int i)
{
    
    if(!(no))
     {
	   no=(ArvoreBB *) malloc(sizeof(ArvoreBB));
	   
	   if(!(no))
	     return NULL;
  
	   no->chave=i;
	   no->esq=NULL;
	   no->dir=NULL;
	   
	   if(!(raiz))
	     return no;
	   
	   if(i < raiz->chave)
	     raiz->esq=no;
	   if(i > raiz->chave)
	     raiz->dir=no;
	   return no;
	    
	 }
		 
	else
	 {
	   if(i < no->chave)
	    InsereNoArvorePonteiro(no, no->esq, i);
	   if(i > no->chave)
	    InsereNoArvorePonteiro(no, no->dir, i);
	 } 
	    
}

void ConsultaNo(ArvoreBB *raiz, int i)
{
	
	if(!(raiz))
	  printf("nao existe no com chave: %d\n", i);
	
	else
	 {
	   if(i == raiz->chave)
	     printf("existe no com chave: %d\n", raiz->chave);
	
	   if(i < raiz->chave)
	     ConsultaNo(raiz->esq, i);
	   
	   if(i > raiz->chave)
	     ConsultaNo(raiz->dir, i);
	 }   
}

void ImprimeArvorePonteiro(ArvoreBB *raiz)
{
	
	if((raiz))
	 { 
		ImprimeArvorePonteiro(raiz->esq);
		
		if((raiz->esq) && (raiz->dir))
		 printf("chave: %d fesq: %d fdir: %d\n", raiz->chave, raiz->esq->chave, raiz->dir->chave);
		else if((raiz->esq) && !(raiz->dir))
		 printf("chave: %d fesq: %d fdir: nil\n", raiz->chave, raiz->esq->chave);
		else if(!(raiz->esq) && (raiz->dir))
		 printf("chave: %d fesq: nil fdir: %d\n", raiz->chave, raiz->dir->chave);
		else if(!(raiz->esq) && !(raiz->dir))
		 printf("chave: %d fesq: nil fdir: nil\n", raiz->chave);
		 
		ImprimeArvorePonteiro(raiz->dir); 
	 } 
	 
}

void ImprimeIndiceVetor(NoVetor *ArvoreVetor, int i)
{
	int j;
	
	for(j=0; j<MAXVETOR; j++)
	 {
	   if(ArvoreVetor[j].n == i)
	    printf("%d\n", j);
	 }
}

void InsereNoArvoreVetor(NoVetor *ArvoreVetor, int j, int i)
{
   
   if(j < MAXVETOR)
    {
   
      if(ArvoreVetor[j].ctrl==False)
       {
	     ArvoreVetor[j].n=i;
	     ArvoreVetor[j].ctrl=True;
	     nnos=nnos+1;
	   }

      else
       {
	     if(i < ArvoreVetor[j].n)
	      InsereNoArvoreVetor(ArvoreVetor, (2*j+1), i);
	    
	     if(i > ArvoreVetor[j].n)
	      InsereNoArvoreVetor(ArvoreVetor, (2*j+2), i);
	   }
	   
	}
	
}

void ImprimeArvoreVetor(NoVetor *ArvoreVetor)
{
	int h,s;
	
	s=nnos;
	
	for(h=0; h<MAXVETOR && s>0; h++)
	 {
		if(ArvoreVetor[h].ctrl == True)
		 {
		   printf("[%d] %d\n", h, ArvoreVetor[h].n);
		   s=s-1;
	     }
		
		else
		  printf("[%d] *\n", h);
	 }
}

void ListaChaveEmOrdem(ArvoreBB *raiz, char modo)
{
  if(modo == 'c')
    OrdemCrescente(raiz);
  if(modo == 'd')
    OrdemDecrescente(raiz);
}



void OrdemCrescente(ArvoreBB *raiz)
{
  if((raiz))
   {
	 OrdemCrescente(raiz->esq);
	 printf("%d\n", raiz->chave);
	 OrdemCrescente(raiz->dir);  
   }	
}

void OrdemDecrescente(ArvoreBB *raiz)
{
	if((raiz))
	 {
		OrdemDecrescente(raiz->dir);
		printf("%d\n", raiz->chave);
		OrdemDecrescente(raiz->esq); 
	 }
}

void ListaChavePorNivel(NoVetor *ArvoreVetor, int n)
{
   int a,b,x,y;
   
   x=(int) pow(2, n-1);   
   y=(int) pow(2, n);   
   
   for(a=x-1, b=y-2; a<b+1; a++)
    {
	  if(a < MAXVETOR)
	   {
	      if(ArvoreVetor[a].ctrl==True)
	       printf("%d\n", ArvoreVetor[a].n);
	   }
	}
}

void ImprimeIndicePorNivelVetor(NoVetor *ArvoreVetor, int n)
{
   int a,b,x,y;
   
   x=(int) pow(2, n-1);
   y=(int) pow(2, n);
   
   for(a=x-1, b=y-2; a<b+1; a++)
    {
	  if(a < MAXVETOR)
	   {
	      printf("%d\n", a);
	   }
	}	
}
