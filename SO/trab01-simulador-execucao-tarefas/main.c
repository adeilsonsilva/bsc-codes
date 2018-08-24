#include "libs/base.h"

int main(int argc, char *argv[]){
	char algoritmo[5]; /* Variável pra salvar o nome do algoritmo utilizado */
	FILE *arqEntrada, *arqSaida; /* Variáveis de leitura dos arquivos */
	long pid_cpu, pid_escalonador; /* Variáveis pra salvar o pid dos processos */
    TarefaPT s, memoria_compartilhada = NULL;
	Tarefa tarefa_atual;
    int memoria_compartilhada_ID;
    key_t key;
	int m;

    key = 567194; /* Parâmetro desconhecido, retirado do exemplo dado pelo professor */
    memoria_compartilhada = (TarefaPT) malloc(sizeof(Tarefa)); /* Aloca espaço de memoria compartilhada */

        /* Função desconhecida, retirada do exemplo dado pelo professor */
	if ((memoria_compartilhada_ID = shmget(key, sizeof(Tarefa), IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}
        /* Função desconhecida, retirada do exemplo dado pelo professor */
	if ((memoria_compartilhada = shmat(memoria_compartilhada_ID, NULL, 0)) == (TarefaPT) -1) {
		perror("shmat");
		exit(1);
	}

	tarefa_atual.id = -15;
	tarefa_atual.chegada = -33;
	tarefa_atual.tempo_execucao = -23;
	tarefa_atual.entrada_IO = -44;
	tarefa_atual.saida_IO = -77;
	memoria_compartilhada = &tarefa_atual;
	
	if(argc != 4){ /* Se não forem passados três argumentos,  o programa encerra*/
		return -1;	
	}		
	
	strcpy(algoritmo, argv[1]);
	arqEntrada = fopen(argv[2], "r");
	arqSaida = fopen(argv[3], "w");

	
	if(arqEntrada && arqSaida){ /* Caso a abertura dos arquivos funcione */

		pid_escalonador = fork(); /* Cria processo da CPU */
		
		if(pid_escalonador == 0){ /* Código do Escalonador */
			pid_cpu = fork(); /* Cria processo da CPU; É criado aqui pois somente o processo pai deve criá-lo */

			if(pid_cpu == 0){
				for(m = 0; m < 10; m++){
					while(memoria_compartilhada == NULL){
						printf("CPU idle...");
					}			
					//executa(tarefaCompartilhada);	
					printf("mem: %i\n",  *memoria_compartilhada);
					printf("tf: %i\n",  &tarefa_atual);
					printf("fffff %d\n", memoria_compartilhada->id);	
				}
			}else{
				for(m = 0; m < 10; m++){
					printf("mem: %i\n",  *memoria_compartilhada);
					printf("tf: %i\n",  &tarefa_atual);
					s = (TarefaPT) malloc(sizeof(Tarefa));
					s->id = m;
					memoria_compartilhada = s;
					printf("endS: %i\n",  &s);
					printf("shm: %i\n", memoria_compartilhada->id);
				}
				//escalonador(arqEntrada, algoritmo, &tarefa_atual);
			}
		}else{	
			
		}
	}
	return 0;
}
