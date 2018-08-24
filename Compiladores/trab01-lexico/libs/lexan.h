#include "lexan_funcs.h"

/* Função principal da Análise Léxica. Recebe um ponteiro para um arquivo
   JÁ ABERTO como parâmetro.*/
int lexicalAnalysis(FILE *arq){
	int i = 0,  maxErrors = 0;
	char line[MAXSTR], *lineErrors[];

	rewind(arq);
	for(i = 0; !feof(arq); i++){
		fscanf(arq, " %[^\n]s", line);
		isValidLine(line,  lineErrors, &maxErrors);
		if(maxErrors > 0){
			for(j = 0; j < maxErrors; j++){
				printf("LINE %d: %s\n", lineErrors[j]);
			}
		}
	}
	return 0;
}
