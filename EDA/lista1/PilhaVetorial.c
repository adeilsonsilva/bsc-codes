#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXTAM 11

typedef struct pilha{
	int chaves[MAXTAM];
	int topo;
}pilha;


void inicializar(pilha *l);
_Bool topo(pilha *l, int *x);
_Bool empilha(pilha *l, int x);
_Bool desempilha(pilha *l, int *x);
void imprimepilha(pilha *l);

int main(void) {
	pilha L;
	int i,d;
	//abaixo chamada de funções para testes básicos e mostrar como ocorrem as chamadas das funções
	inicializar(&L);

	for(i=0; i < 11 ; i++)
		empilha(&L,i); //inserindo de 0 a 10 na pilha

	for(i=0; i < 11; i++){
		desempilha(&L,&d);
		printf("desempilhei %d\n",d);
	}

	return EXIT_SUCCESS;
}


void inicializar(pilha *l){
	l->topo=0;
}




_Bool empilha(pilha *l, int x){
	if(l->topo == MAXTAM)
		return false;
	l->chaves[l->topo++]=x;
	return true;
}

_Bool desempilha(pilha *l, int *x){
	if(l->topo==0)
		return false;
	*x=l->chaves[--l->topo];
	return true;
}

_Bool topo(pilha *l, int *x){
	if(l->topo == 0)
		return false;
	*x=l->chaves[l->topo];
	return true;
}


void imprimepilha(pilha *l){
	int i;
	printf("\n");
	for(i=0; i < l->topo ; i++)
		printf("%d , ", l->chaves[i]);
	printf("\n");
}
