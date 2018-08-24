#ifndef COMPILER_H_
#define COMPILER_H_

#include "lexan_funcs.h"
#include "parser_funcs.h"

/* Função principal da Análise Léxica. Recebe um ponteiro para um arquivo
   JÁ ABERTO como parâmetro.*/
_Bool lexicalAnalysis(FILE *arq){
	int i, lPos,  llPos;;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	/* Seta ponteiro para início do arquivo*/
	rewind(arq);
	for(i = 1; !feof(arq); i++){
		/* Lê uma linha do arquivo*/
		read = getline(&line, &len, arq);
		lPos = strlen(line) - 1;
		llPos = strlen(line) - 2;

		if(llPos >= 2 && line[llPos] == 13){
			line[llPos] = '\0';	
		}else if(lPos >= 1 && line[lPos] == '\n'){
			line[lPos] = '\0';
		}
		/* Passa a linha lida para o analisador*/
		if(read != -1){
			analyseLine(&line[0],  i);
		}
	}
	free(line);
	if(LEXAN_ERRORS == 0){
		return true;
	}
	return false;
}

/* Função principal da Análise Sintática,  não recebe parâmetros pois a análise será feita em uma variável global. */
_Bool parser(){
	NodePT entrada;
	PilhaPT estados;
	int estadoAtual = 0, proxEstado = 0, qtdReducao = 0, j = 0, i = 0;
	_Bool eReducao = false;
	char novoToken[MAXKWSTR], Token[MAXKWSTR], Lexeme[MAXSTR];

	parseTree = addTreeLeave("#SS", "");
	addNodeToken(&nodeList, "$", "");
	
	entrada = nodeList;

	while(true){
	    desempilhaToken(&entrada, Token, Lexeme);
        //printf("%d::%s", estadoAtual, Token);
	 	maquinaEstados(estadoAtual, Token,  &proxEstado, &eReducao);
        //if(eReducao){printf("::red::%d\n", proxEstado);}else{printf("::%d\n", proxEstado);}
		if(proxEstado == INT_MIN){
			return false;	
		}else if(proxEstado == INT_MAX){
			for(i = 0; i < MAXRED; i++){
				currNode = popTree(&parseTreeStack);
				parseTree->child[i] = currNode;
			}
			return true;	
		}else if(eReducao){
			translateReduction(proxEstado, &qtdReducao, novoToken);		
			currNode = addTreeLeave(novoToken, "");
			if(qtdReducao == 0){
				proxEstado = estadoAtual;
			}else{
				//printf("+++No: %s+++", currNode->Token);
				for(j = 0, i = qtdReducao - 1; j < qtdReducao; i--, j++){
					desempilhaEstados(&estados, &proxEstado);
					if(currNode){
						currNode->child[i] = popTree(&parseTreeStack);
					}
					//printf("Filho %d == %s", i, currNode->child[i]->Token);
				}
			}
			empilhaToken(&entrada, Token, Lexeme);
			empilhaToken(&entrada, novoToken, "");
			pushTree(&parseTreeStack, currNode);
			currNode = NULL;
		}else{
			empilhaEstados(&estados, estadoAtual);
			if(!isNonTerminal(Token)){
				pushTree(&parseTreeStack, addTreeLeave(Token, Lexeme));
			}
		}
		estadoAtual = proxEstado;
	}

	return false;
}

/* Retorna 0 se encontra algum erro */
int semanticAnalysis(TreeNodePT parseeTree){
	int j, idScope = 0;
	_Bool declared = false, Array = false;
	char idType[MAXLEXEME], Id[MAXLEXEME];

	if(!parseeTree)
		return 1;

	if(!strcasecmp(parseeTree->Token, "#LIST")){
		//printf("Lexeme found: %s Escopo: %d\n", parseeTree->child[0]->Lexeme, Scope);
		if(parseeTree->child[1] && !strcasecmp(parseeTree->child[1]->Lexeme, "[")){ /* Empilha ids não declarados até descobrir seu tipo */
			empilhaLexema(&Lex, parseeTree->child[0]->Lexeme, true);
		}else{
			empilhaLexema(&Lex, parseeTree->child[0]->Lexeme, false);
		}
	}else if(!strcasecmp(parseeTree->Token, "[")){
		Scope++;	
	}else if(!strcasecmp(parseeTree->Token, "]")){
		Scope--;	
	}else if(!strcasecmp(parseeTree->Token, "#TIPO")){ /* Ao chegar em um tipo,  põe na tabela os ids empilhados */
		//printf("\"%s\"\n", parseeTree->child[0]->Token);
		//return adicionaNaTabela(&Lex, &symbolTable[Scope], parseeTree->child[0]->Token, Scope);	/* Redeclaração de variáveis já é checada nessa função */
		while(desempilhaLexema(&Lex, Id, &Array)){
			for(j = 0; j <= Scope; j++){
				if(isOnTable(&symbolTable[j], Id)){
					declared = true;
					idScope = j;
					break;
				}	
			}
			if(!declared){
				addNodeST(&symbolTable[Scope], Id, parseTree->child[0]->Token, Array);
			}else{
				return 0;
			}
		} 	
	}else if(!strcasecmp(parseeTree->Token, "#OPERANDO") && !strcasecmp(parseeTree->child[0]->Token, "id")){ /* Quando chega em um id verifica se ele já foi declarado */
		for(j = 0; j <= Scope; j++){
			if(isOnTable(&symbolTable[j], parseeTree->child[0]->Lexeme)){
				declared = true;
				idScope = j;
				break;
			}	
		}
		if(!declared){
			return 0;	
		}
		if(parseeTree->child[1] && !strcasecmp(parseeTree->child[1]->Token, "[")){ /* Caso tente utilizar vetor sem alocar OU indexar não-vetor */
			if((getArraySize(&symbolTable[idScope], parseeTree->child[0]->Lexeme) == UNSET_ARRAY) || (!isArray(&symbolTable[idScope], parseeTree->child[0]->Lexeme))){
				return 0;	
			}	
		}else if(isArray(&symbolTable[idScope], parseeTree->child[0]->Lexeme) && !parseeTree->child[1]){ /* Se é um vetor ele tem que ser indexado nesse caso. Basta verificar se tem o primeiro filho,  pois se tiver com certeza é '[' por causa da gramática */
			return 0;
		}
	}else if(!strcasecmp(parseeTree->Token, "#ID")){ /* Quando chega em um id verifica se ele já foi declarado */
		for(j = 0; j <= Scope; j++){
			if(isOnTable(&symbolTable[j], parseeTree->child[0]->Lexeme)){
				declared = true;
				idScope = j;
				break;
			}	
		} 
		if(!declared){
			return 0;	
		}
		if(parseeTree->child[1] && !strcasecmp(parseeTree->child[1]->Token, "[")){ /* Caso tente utilizar vetor sem alocar OU indexar não-vetor */
			if((getArraySize(&symbolTable[idScope], parseeTree->child[0]->Lexeme) == UNSET_ARRAY) || (!isArray(&symbolTable[idScope], parseeTree->child[0]->Lexeme))){
				return 0;	
			}	
		}else if(isArray(&symbolTable[idScope], parseeTree->child[0]->Lexeme) && !parseeTree->child[1]){ /* Se é um vetor ele tem que ser indexado nesse caso. Basta verificar se tem o primeiro filho,  pois se tiver com certeza é '[' por causa da gramática */
			return 0;
		}
	}else if(!strcasecmp(parseeTree->Token, "#Alocacao")){
		for(j = 0; j <= Scope; j++){
			if(isOnTable(&symbolTable[j], parseeTree->child[1]->Lexeme)){
				declared = true;
				idScope = j;
				break;
			}	
		} 
		if(!declared){
			return 0;	
		}
		if(!isArray(&symbolTable[idScope], parseeTree->child[1]->Lexeme)){ /* Tentativa de alocar não-vetor */
			return 0;	
		}else{
			setArraySize(&symbolTable[idScope], parseeTree->child[1]->Lexeme, SET_ARRAY);	
		}	
	}else if(!strcasecmp(parseeTree->Token, "#Loop") && !strcasecmp(parseeTree->child[0]->Token, "foreach")){
		for(j = 0; j <= Scope; j++){
			if(isOnTable(&symbolTable[j], parseeTree->child[3]->Lexeme)){
				declared = true;
				idScope = j;
				break;
			}	
		} 
		if(!declared){
			return 0;	
		}
		if((!isArray(&symbolTable[idScope], parseeTree->child[3]->Lexeme)) || (getArraySize(&symbolTable[idScope], parseeTree->child[3]->Lexeme) == UNSET_ARRAY && isArray(&symbolTable[idScope], parseeTree->child[3]->Lexeme))){ /* Tentativa de usar não-vetor em foreach */
			return 0;	
		}
	}else if(!strcasecmp(parseeTree->Token, "#Atribuicao") && !strcasecmp(parseeTree->child[1]->Token, "CONSTSTR")){
		for(j = 0; j <= Scope; j++){
			if(isOnTable(&symbolTable[j], parseeTree->child[3]->Lexeme)){
				declared = true;
				idScope = j;
				break;
			}	
		} 
		if(!declared){
			return 0;	
		}
		getIdType(&symbolTable[idScope], parseeTree->child[3]->Lexeme, idType);
		//printf("\"%s\"\n", idType);
		if(!strcasecmp(idType, "number")){ /* Tentativa de colocar string em vetor de number */
			return 0;	
		}
	}

/*
	printf("Token: %s", parseeTree->Token);
	for(j = 0; j < MAXRED && parseeTree->child[j]; j++){
		printf("::TokenFilho %d>>%s", j, parseeTree->child[j]->Token);	
	}
	printf("\n");
*/

	for(j = 0; j < MAXRED && parseeTree->child[j]; j++){
		if(!semanticAnalysis(parseeTree->child[j])){
			return 0;	
		}
	}

	return 1;
}


#endif /* COMPILER_H_ */

