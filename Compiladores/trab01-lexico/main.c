#include "libs/lexan.h"

int main (int argc,  char*argv[]){
	FILE *arq;

	if(argc < 2){
		printf("ERRO: Falta de parâmetros.\nUso: ./a.out nome_do_arquivo\n");	
	}else{
		arq = fopen(argv[1], "r");
		if(arq){
			if(isArqValid(arq)){
				lexicalAnalysis(arq);
			}else{
				printf("ARQUIVO INVÁLIDO!\n");
			}
			fclose(arq);
		}
	}

	return 0;
}
