#ifndef TYPES_H_
#define TYPES_H_

#define MAXTOKEN 25
#define MAXRED 10
#define MAXLEXEME 256
#define MAXTYPE 7
#define UNSET_ARRAY -6565656
#define SET_ARRAY 5555555

/* Estrutura pra salvar os tokens, lexemas e outros valores para as fases seguintes do compilador */
typedef struct Node{
	char Token[MAXTOKEN];
	char Lexeme[MAXLEXEME]; 
	struct Node *prox;
}Node,  *NodePT;

/* Estrutura para salvar os estados durante a Análise Sintática */
typedef struct NoPilha{
		int estado;
		struct NoPilha *prox;
}NoPilha,  *PilhaPT;

/* ÁRVORE: Estrutura que representa os nós da árvore */
typedef struct TreeNode{
	char Token[MAXTOKEN]; /* Guardará o Token (Terminal ou não) */
	char Lexeme[MAXLEXEME];
	struct TreeNode *child[MAXRED]; /* Vetor com os filhos daquele nó */
}TreeNode, *TreeNodePT;

/* Pilha de nós da árvore */
typedef struct TreeStack{
	TreeNodePT node;
	struct TreeStack *prox;
}TreeStack, *TreeStackPT;

/* Estrutura da Tabela de Símbolos */
typedef struct SymbolTable{
	char Id[MAXLEXEME];
	char Type[MAXTYPE];
	_Bool isArray;
	int arraySize;
	struct SymbolTable *prox;
}SymbolTable, *SymbolTablePT;

typedef struct LexStack{
	char Id[MAXLEXEME];
	_Bool isArray;
	struct LexStack *prox;
}LexStack, *LexStackPT;

/* A adição é feita no fim da lista,  para manter a ordem da Análise */
_Bool addNodeToken(NodePT *n, char *token, char *lexeme){
	NodePT s, t;

	if(!(s = (NodePT) malloc(sizeof(Node)))){
		return false;	
	}
	s->prox = NULL;
	strcpy(s->Token, token);
	strcpy(s->Lexeme, lexeme);

	for(t = *n; t && t->prox; t = t->prox); /* Vai para o fim da lista */

	if((t) && !(t->prox)){  /* Caso a lista já contenha nós */
		t->prox = s;
	}else if(!(t)){ /* Caso a lista esteja vazia */
		*n = s;	
	}
	return true;
}

/* Função de empilhamento dos Estados da Análise Sintática */
_Bool empilhaEstados(PilhaPT *t,  int x){
	PilhaPT s;
	        
	if(!(s=(PilhaPT) malloc (sizeof(NoPilha))))
	  	return false;
							
	s->prox=(*t);
	s->estado=x;
	(*t)=s;
	return true;
}

/* Função de desempilhamento dos Estados da Análise Sintática */
_Bool desempilhaEstados(PilhaPT *t,  int *tp){
	PilhaPT s;
		      
	s=*t;
	if((s) == NULL){ 
		*tp = INT_MIN;
		return false;
	}
										   
    *tp=s->estado;
    *t=s->prox;
    free(s);
    return true;
}

/* Função de desempilhamento dos Tokens da Análise Sintática */
_Bool desempilhaToken(NodePT *t,  char *Token, char *Lexeme){
	NodePT s;
		      
	s=*t;
	if((s) == NULL){ 
		strcpy(Token, "NOACTION");
		return false;
	}				

	strcpy(Token, s->Token);
	strcpy(Lexeme, s->Lexeme);
    *t=s->prox;
    free(s);
    return true;
}

/* Função de empilhamento dos Tokens da Análise Sintática */
_Bool empilhaToken(NodePT *t,  char *x, char *lexeme){
	NodePT s;
	        
	if(!(s=(NodePT) malloc (sizeof(Node))))
	  	return false;
							
	s->prox=(*t);
	strcpy(s->Token, x);
	strcpy(s->Lexeme, lexeme);
	(*t)=s;
	return true;
}

/* Função de criação de folhas da árvore */
TreeNodePT addTreeLeave(char *Token, char *Lexeme){
	TreeNodePT s;	
	int i;

	if(!(s = (TreeNodePT) malloc(sizeof(TreeNode))))
		return NULL;

	strcpy(s->Token, Token);
	strcpy(s->Lexeme, Lexeme);
	for(i = 0; i < MAXRED; i++){
		s->child[i] = NULL;	
	}
	return s;
}

/* Função de empilhamento dos nós da árvore */
_Bool pushTree(TreeStackPT *t, TreeNodePT node){
	TreeStackPT s;
	        
	if(!(s=(TreeStackPT) malloc (sizeof(TreeStack))))
	  	return false;
							
	s->prox=(*t);
	s->node = node;
	(*t)=s;

	//printf("**Adicionado: %s\n", s->node->Token);
	return true;
}

/* Função de desempilhamento dos nós da árvore sintática */
TreeNodePT popTree(TreeStackPT *t){
	TreeStackPT s;
	TreeNodePT node;
	s = *t;

	if(!(s)){
		return NULL;	
	}

	node = s->node;
	*t = s->prox;
	//printf("**Removido %s\n", node->Token);
	return node;
}

/* A adição é feita no fim da lista,  para manter a ordem da Análise */
_Bool addNodeST(SymbolTablePT *n, char *id, char *type, _Bool isArray){
	SymbolTablePT s, t;

	if(!(s = (SymbolTablePT) malloc(sizeof(SymbolTable)))){
		return false;	
	}
	s->prox = NULL;
	strcpy(s->Id, id);
	strcpy(s->Type, type);
	s->isArray = isArray;
	s->arraySize = UNSET_ARRAY;
	
	for(t = *n; t && t->prox; t = t->prox); /* Vai para o fim da lista */

	if((t) && !(t->prox)){  /* Caso a lista já contenha nós */
		t->prox = s;
	}else if(!(t)){ /* Caso a lista esteja vazia */
		*n = s;	
	}
	return true;
}

/* Função que retorna o tipo da variável passada */
void getIdType(SymbolTablePT *table, char *id, char *type){
	SymbolTablePT s;

	for(s = *table; s; s = s->prox){
		if(!strcasecmp(s->Id, id)){
			strcpy(type, s->Type);
			return;
		}	
	}
}

/* Função que informa sobre a existência de um Id na tabela */
_Bool isOnTable(SymbolTablePT *table, char *id){
	SymbolTablePT s;

	for(s = *table; s; s = s->prox){
		if(!strcasecmp(s->Id, id)){
			return true;
		}	
	}

	return false;
}

_Bool isArray(SymbolTablePT *table, char *id){
	SymbolTablePT s;

	for(s = *table; s; s = s->prox){
		if(!strcasecmp(s->Id, id)){
			return s->isArray;
		}	
	}

	return false;
}

int getArraySize(SymbolTablePT *table, char *id){
	SymbolTablePT s;

	for(s = *table; s; s = s->prox){
		if(s->isArray && !strcasecmp(s->Id, id)){
			return s->arraySize;
		}	
	}

	return UNSET_ARRAY;
}

_Bool setArraySize(SymbolTablePT *table, char *id, int size){
	SymbolTablePT s;

	for(s = *table; s; s = s->prox){
		if(s->isArray && !strcasecmp(s->Id, id)){
			s->arraySize = size;
			return true;
		}	
	}

	return false;
}

/* Função de empilhamento dos Lexemas enquanto a busca acontece na Árvore */
_Bool empilhaLexema(LexStackPT *t,  char *lexeme, _Bool isArray){
	LexStackPT s;
	        
	if(!(s=(LexStackPT) malloc (sizeof(LexStack))))
	  	return false;
							
	s->prox=(*t);
	strcpy(s->Id, lexeme);
	s->isArray = isArray;
	(*t)=s;
	return true;
}

/* Função de desempilhamento dos Lexemas enquanto a busca acontece na Árvore */
_Bool desempilhaLexema(LexStackPT *t,  char *lexeme, _Bool *isArray){
	LexStackPT s;
	     
	s = *t;
	if(!(s)){
		return false;	
	}

	strcpy(lexeme, s->Id);
	*isArray = s->isArray;
	(*t)=s->prox;
	free(s);
	return true;
}

/* Função que desempilha os tokens da pilha de Lexemas e adiciona à Tabela de Símbolos  */
_Bool adicionaNaTabela(LexStackPT *Lex, SymbolTablePT *symbolTable, char *type, int scope){
	char Id[MAXLEXEME];
	_Bool isArray;
	
	while(desempilhaLexema(Lex, Id, &isArray)){
		if(!isOnTable(symbolTable, Id)){
			addNodeST(symbolTable, Id, type, isArray);
		}else{
			return false;	
		}
	}

	return true;
}

#endif /* TYPES_H_ */

