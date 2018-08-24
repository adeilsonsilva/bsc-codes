#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;

    long pid_filho = fork();

    if (pid_filho == 0){
	for(i = 0; i < 100000; i++)
		fprintf(stderr,"-----------Processo [filho]\n");
    }else{
	for(i = 0; i < 100000; i++)
		fprintf(stderr,"***********Processo [pai]\n");
    }

    return EXIT_SUCCESS;
}


