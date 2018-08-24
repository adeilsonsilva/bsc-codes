#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct listadupla{
	int chave;
	struct listadupla *ant;
	struct listadupla *prox;
}listadupla, *plistadupla;


void inicializar(plistadupla *l);
_Bool consulta(plistadupla *l, int x);
_Bool inserir(plistadupla *l, int x);
void remover(plistadupla *l, int x);
void imprimelista(plistadupla *l);

int main(void) {
	plistadupla L;
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


void inicializar(plistadupla *l){
	*l=NULL;
}

plistadupla consultaendereco(plistadupla *l, int x){
	plistadupla p;
	for(p=*l; (p) && (p->chave != x); p=p->prox);
	return p;
}

_Bool consulta(plistadupla *l, int x){
	return (consultaendereco(l,x));
}
_Bool inserir(plistadupla *l, int x){
	plistadupla novo;
	if(!(novo=(plistadupla)malloc(sizeof(listadupla))))
		return false;
	if(*l)
		(*l)->ant=novo;
	novo->chave=x;
	novo->prox=*l;
	novo->ant=NULL;
	*l=novo;
	return true;
}

void remover(plistadupla *l, int x){
	plistadupla p;
	for(p=*l; (p) && (p->chave != x); p=p->prox);
	if(p){
		if(p->prox)
			p->prox->ant=p->ant;
		if(p->ant)
			p->ant->prox=p->prox;
		else
			*l=p->prox;
		free(p);
	}
}

void imprimelista(plistadupla *l){
	plistadupla p;
	printf("\n");
	for(p=*l; (p) ; p=p->prox)
		printf("%d , ", p->chave);
	printf("\n");
}
