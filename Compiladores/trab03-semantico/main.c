#include "libs/compiler.h"

int main (int argc,  char*argv[]){
	FILE *arq;

	if(argc == 2){
		arq = fopen(argv[1], "r");
		if(arq){
			if(isArqValid(arq)){
				if(lexicalAnalysis(arq)){
					if(parser()){
						printf("SIM\n");	
						if(semanticAnalysis(parseTree)){
							printf("SIM\n");	
						}else{
							printf("NAO\n");	
						}
					}else{
						printf("NAO\n");	
					}
				}
			}else{
				printf("ARQUIVO INVALIDO!\n");
			}
			fclose(arq);
		}
	}

	return 0;
}
