#include "tipos.h"

#define MAXINT 15

/* Função de leitura do arquivo e separação das entradas */
void separa(char *destino,char *destino2,char *destino3,char *destino4, char *origem,int *num) {
	int palavra=0;
	while (*origem) {
		if (*origem==';'){
				origem++;
				break;
		}
		  *destino = *origem;
		  origem++;
		  destino++;
		  
	   }
	   	   *destino = '\0';
	while (*origem) {
		if (!(*origem==';')){
				palavra=2;
		}
		if (*origem==';'){
			origem++;
			break;
			
		}
		  *destino2 = *origem;
		  origem++;
		  destino2++;
		}
		*destino2 = '\0';
while (*origem) {
	  if (!(*origem==';')){
			palavra=3;
		}
		if (*origem==';'){
			origem++;
			break;
		}
		  *destino3 = *origem;
		  origem++;
		  destino3++;
	   }
	
	   *destino3 = '\0';
   while (*origem) {
		if (!(*origem==';')){
			palavra=4;
		}else
			break;
		*destino4 = *origem;
		origem++;
		destino4++;
   }
   
	*destino4 = '\0';
	*num=palavra;
}


/* Função de retirada das vírgulas na leitura dos dados de IO do processo */
void separavirgula(char *origem, int *numEntrada, int *numSaida) {
	char aux[10];
	int tamanho=strlen(origem);
	int i,k=0;

        for(i = 0; i < tamanho && origem[i] != ','; i++){
                aux[i] = origem[i];
        }
        aux[i] = '\0';
        *numEntrada = atoi(aux);
        if(origem[i] == ','){
            for(i += 1, k = 0; i < tamanho; i++, k++){
                aux[k] = origem[i];
            }
            *numSaida = atoi(aux);
        }
}


/* Função principal do escalonador */
int escalonador(FILE *entrada, char *algoritmo, TarefaPT tarefa_atual){
    int numId, numChegada, numExecucao, num_entradaIO, num_saidaIO, i;
    char linha[5*MAXINT], id[MAXINT], chegada[MAXINT], execucao[MAXINT], IO[MAXINT]; /* Variáveis que armazenarão as informações sobre cada processo que serão lidas do arquivo de entrada */
    TarefaPT listaTarefas = NULL; /* Variáveel que armazena a lista de processos criada pelo escalonador */

    while(!feof(entrada)){
        i=1;
        fscanf(entrada,"\n\r%[^\n]",linha);
		separa(id, chegada, execucao, IO, linha, &i);
        
        numId = atoi(id);
        numChegada = atoi(chegada);
        numExecucao = atoi(execucao);
    
		if(i>3){
	  		separavirgula(IO, &num_entradaIO, &num_saidaIO);
	  		addTarefa(&listaTarefas, numId, numChegada, numExecucao, num_entradaIO, num_saidaIO); /* Se a tarefa faz IO, adicionamos o momento de entrada e saida da tarefa na lista de processos */
		}else{
           addTarefa(&listaTarefas, numId, numChegada, numExecucao, -100, -100); /* Adicionamos um valor "qualquer" para sabermos que aquela tarfa não faz IO */
    	}
	}
	//imprime();
//	fclose(entrada);

	tarefa_atual->id = listaTarefas->id;
	tarefa_atual->chegada = listaTarefas->chegada;
	tarefa_atual->tempo_execucao = listaTarefas->tempo_execucao;
	tarefa_atual->entrada_IO = listaTarefas->entrada_IO;
	tarefa_atual->saida_IO = listaTarefas->saida_IO;

	for(;listaTarefas->prox;listaTarefas = listaTarefas->prox){ printf("Id: %d; Chegada: %d; Execucao: %d; Entrada_IO: %d; Saida_IO: %d\n", listaTarefas->id, listaTarefas->chegada,listaTarefas->tempo_execucao,listaTarefas->entrada_IO,listaTarefas->saida_IO); }
	//addTarefa(memoria_compartilhada, listaTarefas->id, listaTarefas->chegada,listaTarefas->tempo_execucao,listaTarefas->entrada_IO,listaTarefas->saida_IO);
	//*memoria_compartilhada = &(*listaTarefas->prox);
	return 0;
}

