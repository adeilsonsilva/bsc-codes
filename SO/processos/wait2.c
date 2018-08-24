#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
    int i, t, status;

    long pid_filho = fork();

    if (pid_filho == 0){
	sleep(5);
	//filho termina antes do pai...
    }else{
	printf("***********Processo [pai]\n");
	wait(&status);
	fprintf(stderr, "Processo pai inicia execucao\n");
	printf("Processo filho finalizado.\n");
	for(i = 0; i < 10000000000; i++) t+=t*i;
    }

    return EXIT_SUCCESS;
}


