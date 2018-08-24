#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    long pid_filho = fork();
    int i;

    if (pid_filho == 0){
	printf("\n[i=-1]Processo filho:\t %ld\n", (long) getpid());
	printf("[i=-1]Processo pai:\t %ld\n", (long)getppid());
    }

    for(i = 0; i < 3; i++){
       pid_filho = fork();

       if (pid_filho == 0)
         printf("[i=%d]Processo filho (%ld) - Processo pai (%ld)\n", i, (long) getpid(), (long)getppid());
       
    }

   for(i=0; i<1100000000;i++);

    return EXIT_SUCCESS;
}


