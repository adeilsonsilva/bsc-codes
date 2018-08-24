#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXTAM 11

typedef struct fila{
	int chaves[MAXTAM];
	int final;
}fila;


void inicializar(fila *l);
_Bool enfileira(fila *l, int x);
_Bool desenfileira(fila *l, int *x);


int main(void) {
	fila L;
	int i,d;
	//abaixo chamada de funções para testes básicos e mostrar como ocorrem as chamadas das funções
	inicializar(&L);

	for(i=0; i < 11 ; i++)
		enfileira(&L,i); //inserindo de 0 a 10 na pilha

	for(i=0; i < 11; i++){
		desenfileira(&L,&d);
		printf("desemfileirei %d\n",d);
	}

	return EXIT_SUCCESS;
}


void inicializar(fila *l){
	l->final=0;
}




_Bool enfileira(fila *l, int x){
	if(l->final == MAXTAM)
		return false;
	l->chaves[l->final++]=x;
	return true;
}

_Bool desenfileira(fila *l, int *x){
	if(l->final==0)
		return false;
	*x=l->chaves[0];
	l->chaves[0]=l->chaves[--l->final];
	return true;
}
