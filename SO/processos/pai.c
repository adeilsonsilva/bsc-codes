#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int i, t;

    long pid_filho = fork();

    if (pid_filho != 0){
	//filho termina antes do pai...
	sleep(10);
    }else{
	printf("***********Processo [pai]\n");
	printf("pid pai = %ld\n", (long)getppid());
	for(i = 0; i < 10000000000; i++) t+=t*i;
    }

    return EXIT_SUCCESS;
}


