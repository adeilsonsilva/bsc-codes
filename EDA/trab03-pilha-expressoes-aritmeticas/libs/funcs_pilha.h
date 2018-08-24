/* Universidade Federal da Bahia
   Graduação em Ciência da Computação
   MATA40 - Estruturas de Dados e Algoritmos I
   Aluno: Adeilson Silva
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXEXPRINF 51
#define MAXEXPRPOS 101
#define true 1
#define false 0

//Definição de tipos

typedef struct NoPilha{
	char elem;
	struct NoPilha *prox;
}NoPilha, *PilhaPT;

typedef struct NoPilhaNum{
        float chaves[MAXEXPRINF];
        int topo;
}NoPilhaNum, *PilhaNum;

//Funções de Inicialização

void inicializa(PilhaPT *t)
{
	(*t)=NULL;
}

void inicializa_num(PilhaNum t)
{
        t->topo=0;
}

//Funções de Empilhamento

_Bool empilha (PilhaPT *t, char x)
{
      PilhaPT s;
      
      if(!(s=(PilhaPT) malloc (sizeof(NoPilha))))
	return false;

      s->prox=(*t);
      s->elem=x;
      (*t)=s;
      return true;
}

_Bool empilha_num (PilhaNum t, float x)
{
    if(t->topo == MAXEXPRINF)
        return false;

    t->chaves[t->topo]=x;
    t->topo++;
    return true;
}

//Funções que retornam o topo

_Bool Topo(PilhaPT *t, char *tp)
{
      if((*t) == NULL)
    	return false;
      
      *tp=(*t)->elem;
      return true;
}

_Bool Topo_num(PilhaNum t, float *k)
{
   if(t->topo == 0)
      return false;

   *k=t->chaves[t->topo - 1];
   return true;
}

//Funções de desempilhamento

_Bool desempilha(PilhaPT *t, char *tp)
{
     PilhaPT s;
     
     s=*t;
     
      if((s) == NULL) 
         return false;

      *tp=s->elem;
      *t=s->prox;
      free(s);
      return true;
}

_Bool desempilha_num(PilhaNum t, float *k)
{
   if(t->topo == 0)
      return false;

   *k=t->chaves[t->topo - 1];
   t->topo--;
   return true;
}
