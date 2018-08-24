#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXTAM 11

typedef struct lista{
	int chaves[MAXTAM];
	int nelem;
}lista;


void inicializar(lista *l);
_Bool consulta(lista *l, int x);
_Bool inserir(lista *l, int x);
void remover(lista *l, int x);
void imprimelista(lista *l);
int consultaendereco(lista *l, int x);

int main(void) {
	lista L;
	int i;
	//abaixo chamada de funções para testes básicos e mostrar como ocorrem as chamadas das funções
	inicializar(&L);

	for(i=0; i < 11 ; i++)
		inserir(&L,i); //inserindo de 0 a 10 na lista

	imprimelista(&L);

	for(i=0; i < 11; i+=2)
		remover(&L,i);	//removendo numeros pares da lista

	imprimelista(&L);

	for(i=0; i < 11; i++)
		if(consulta(&L,i))
			printf("O numero %d pertence a lista\n",i);
		else
			printf("O numero %d nao pertence a lista\n",i);




	return EXIT_SUCCESS;
}


void inicializar(lista *l){
	l->nelem=0;
}

int consultaendereco(lista *l, int x){
	int i;
	for(i=0; i < l->nelem && l->chaves[i] != x; i++);
	if(i==l->nelem)
		return -1;
	return i;
}

_Bool consulta(lista *l, int x){
	return (consultaendereco(l,x) != -1);
}

_Bool inserir(lista *l, int x){
	if(l->nelem == MAXTAM)
		return false;
	l->chaves[l->nelem++]=x;
	return true;
}

void remover(lista *l, int x){
	int i=consultaendereco(l,x);
	if(i!=-1)
		l->chaves[i]=l->chaves[--l->nelem];
}

void imprimelista(lista *l){
	int i;
	printf("\n");
	for(i=0; i < l->nelem ; i++)
		printf("%d , ", l->chaves[i]);
	printf("\n");
}
