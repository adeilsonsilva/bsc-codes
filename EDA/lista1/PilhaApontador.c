#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct pilha{
	int chave;
	struct pilha *prox;
}pilha,*ppilha;


void inicializar(ppilha *l);
_Bool topo(ppilha *l, int *x);
_Bool empilha(ppilha *l, int x);
_Bool desempilha(ppilha *l, int *x);


int main(void) {
	ppilha topo;
	int i,x;

	inicializar(&topo);

	for(i=0; i < 11; i++)
		empilha(&topo, i);

	for(i=0; i < 11; i++){
		desempilha(&topo, &x);
		printf("desempilhei %d\n",x);
	}



	return EXIT_SUCCESS;
}


void inicializar(ppilha *l){
	*l=NULL;
}


_Bool topo(ppilha *l, int *x){
	if(!(*l))
		return false;
	*x=(*l)->chave;
	return true;
}

_Bool empilha(ppilha *l, int x){
	ppilha novo;
	if(!(novo=(ppilha)malloc(sizeof(pilha))))
		return false;
	novo->chave=x;
	novo->prox=*l;
	*l=novo;
	return true;
}

_Bool desempilha(ppilha *l, int *x){
	ppilha p=*l;

	if(!p)
		return false;
	*x=p->chave;
	*l=p->prox;
	free(p);
	return true;
}

