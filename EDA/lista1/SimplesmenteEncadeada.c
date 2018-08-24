#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct listasimples{
	int chave;
	struct listasimples *prox;
}listasimples, *plistasimples;


void inicializar(plistasimples *l);
_Bool consulta(plistasimples *l, int x);
_Bool inserir(plistasimples *l, int x);
void remover(plistasimples *l, int x);
void imprimelista(plistasimples *l);

int main(void) {
	plistasimples L;
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


void inicializar(plistasimples *l){
	*l=NULL;
}

plistasimples consultaendereco(plistasimples *l, int x){
	plistasimples p;
	for(p=*l; (p) && (p->chave != x); p=p->prox);
	return p;
}

_Bool consulta(plistasimples *l, int x){
	return (consultaendereco(l,x));
}
_Bool inserir(plistasimples *l, int x){
	plistasimples novo;
	if(!(novo=(plistasimples)malloc(sizeof(listasimples))))
		return false;
	novo->chave=x;
	novo->prox=*l;
	*l=novo;
	return true;
}

void remover(plistasimples *l, int x){
	plistasimples p,q;
	for(p=*l,q=NULL; (p) && (p->chave != x); q=p, p=p->prox);
	if(p){
		if(q)
			q->prox=p->prox;
		else
			*l=p->prox;
		free(p);
	}
}

void imprimelista(plistasimples *l){
	plistasimples p;
	printf("\n");
	for(p=*l; (p) ; p=p->prox)
		printf("%d , ", p->chave);
	printf("\n");
}
