#ifndef TYPES_H_
#define TYPES_H_

#define MAXTOKEN 25

/* Estrutura pra salvar os tokens, lexemas e outros valores para as fases seguintes do compilador */
typedef struct Node{
	char Token[MAXTOKEN];
	//char *Lexeme; Será usado no terceiro trabalho
	struct Node *prox;
}Node,  *NodePT;

/* Estrutura para salvar os estados durante a Análise Sintática */
typedef struct NoPilha{
		int estado;
		struct NoPilha *prox;
}NoPilha,  *PilhaPT;


/* A adição é feita no fim da lista,  para manter a ordem da Análise */
_Bool addNodeToken(NodePT *n, char *token){
	NodePT s, t;

	if(!(s = (NodePT) malloc(sizeof(Node)))){
		return false;	
	}
	s->prox = NULL;
	strcpy(s->Token, token);

	for(t = *n; t && t->prox; t = t->prox); /* Vai para o fim da lista */

	if((t) && !(t->prox)){  /* Caso a lista já contenha nós */
		t->prox = s;
	}else if(!(t)){ /* Caso a lista esteja vazia */
		*n = s;	
	}
	return true;
}

/* Função de empilhamento dos Estados da Análise Sintática */
_Bool empilhaEstados(PilhaPT *t,  int x)
{
	PilhaPT s;
	        
	if(!(s=(PilhaPT) malloc (sizeof(NoPilha))))
	  	return false;
							
	s->prox=(*t);
	s->estado=x;
	(*t)=s;
	return true;
}

/* Função de desempilhamento dos Estados da Análise Sintática */
_Bool desempilhaEstados(PilhaPT *t,  int *tp)
{
	PilhaPT s;
		      
	s=*t;
	if((s) == NULL){ 
		*tp = INT_MIN;
		return false;
	}
										   
    *tp=s->estado;
    *t=s->prox;
    //free(s);
    return true;
}

/* Função de desempilhamento dos Tokens da Análise Sintática */
_Bool desempilhaToken(NodePT *t,  char *Token)
{
	NodePT s;
		      
	s=*t;
	if((s) == NULL){ 
		strcpy(Token, "NOACTION");
		return false;
	}				

    //*tp=s->elem;
	strcpy(Token, s->Token);
    *t=s->prox;
    free(s);
    return true;
}

/* Função de empilhamento dos Tokens da Análise Sintática */
_Bool empilhaToken(NodePT *t,  char *x)
{
	NodePT s;
	        
	if(!(s=(NodePT) malloc (sizeof(Node))))
	  	return false;
							
	s->prox=(*t);
	strcpy(s->Token, x);
	(*t)=s;
	return true;
}


#endif /* TYPES_H_ */

