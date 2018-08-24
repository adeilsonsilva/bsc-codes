#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct listasimples{
	int chave;
	struct listasimples *prox;
}lista;

typedef struct fila{
	lista *inicio;
	lista *fim;
}fila, *pfila;

void inicializar(fila *l);
_Bool enfileira(fila *l, int x);
_Bool desenfileira(fila *l, int *x);


int main(void) {
	fila topo;
	int i,x;

	inicializar(&topo);

	for(i=0; i < 11; i++)
		enfileira(&topo, i);

	for(i=0; i < 11; i++){
		desenfileira(&topo, &x);
		printf("desempilhei %d\n",x);
	}



	return EXIT_SUCCESS;
}


void inicializar(fila *l){
	l->inicio=NULL;
	l->fim=NULL;
}




_Bool enfileira(fila *l, int x){
	lista *novo;

	if(!(novo=(lista*)malloc(sizeof(lista))))
		return false;
	novo->chave=x;
	novo->prox=NULL;
	if(l->fim)
		l->fim->prox=novo;
	else
		l->inicio=novo;
	l->fim=novo;
	return true;
}

_Bool desenfileira(fila *l, int *x){
	lista *p;
	if(!(l->inicio))
		return false;
	p=l->inicio;
	*x=p->chave;
	l->inicio=p->prox;
	free(p);
	return true;
}

