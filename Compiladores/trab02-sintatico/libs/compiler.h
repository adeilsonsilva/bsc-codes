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
	int estadoAtual = 0, proxEstado = 0, qtdReducao = 0, j = 0;
	_Bool eReducao = false;
	char novoToken[MAXKWSTR], Token[MAXKWSTR];


	addNodeToken(&nodeList, "$");
	
	entrada = nodeList;

	while(true){

	        desempilhaToken(&entrada, Token);
                //printf("%d::%s", estadoAtual, Token);
	 	maquinaEstados(estadoAtual, Token,  &proxEstado, &eReducao);
                //if(eReducao){printf("::red::%d\n", proxEstado);}else{printf("::%d\n", proxEstado);}
		if(proxEstado == INT_MIN){
			return false;	
		}else if(proxEstado == INT_MAX){
			return true;	
		}else if(eReducao){
			translateReduction(proxEstado, &qtdReducao, novoToken);	
			
			if(qtdReducao == 0){
				proxEstado = estadoAtual;
			}else{
				for(j = 0; j < qtdReducao; j++){
				desempilhaEstados(&estados, &proxEstado);	
				}
			}
			empilhaToken(&entrada, Token);
			empilhaToken(&entrada, novoToken);
		}else{
			empilhaEstados(&estados, estadoAtual);
		}
		estadoAtual = proxEstado;
	}

	return false;
}

#endif /* COMPILER_H_ */

