#include <stdbool.h>

typedef struct Tarefa{
	int id;
    int chegada;
    int tempo_execucao;
    int entrada_IO;
    int saida_IO;
	struct Tarefa *prox;
}Tarefa,  *TarefaPT;

/* A adição é feita no fim da lista */
_Bool addTarefa(TarefaPT *n, int id, int chegada, int tempo_execucao, int entrada_IO, int saida_IO){
	TarefaPT s, t;

	if(!(s = (TarefaPT) malloc(sizeof(Tarefa)))){
		return false;	
	}
	
	s->prox = NULL;
	s->id = id;
    s->chegada = chegada;
	s->tempo_execucao = tempo_execucao;
	s->entrada_IO = entrada_IO;
	s->saida_IO = saida_IO;

	for(t = *n; t && t->prox; t = t->prox); /* Vai para o fim da lista */

	if((t) && !(t->prox)){  /* Caso a lista já contenha nós */
		t->prox = s;
	}else if(!(t)){ /* Caso a lista esteja vazia */
		*n = s;	
	}
	return true;
}

/* Remove tarefa com determinado ID da lista */
_Bool removeTarefa(TarefaPT *l, int id){
	TarefaPT s, t;

	if(!(*l)){ /* Lista vazia */
		return false;	
	}

	for(t = *l; (t->prox) && (t->prox->id != id); t = t->prox);

	if(!(t->prox)){ /* ID não encontrado */
		return false;	
	}
	s = t->prox;
	t->prox = s->prox;
	free(s);
	return true;
}
