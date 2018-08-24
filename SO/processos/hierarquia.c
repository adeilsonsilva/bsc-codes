#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int
main(){
	int pid_filho = fork();

	if(pid_filho == 0){
		fprintf(stderr, "Meu PID: %d\n", pid_filho);
		fprintf(stderr, "Meu PID: %ld\n", (long) getpid());
		fprintf(stderr, "PID pai: %ld\n", (long) getppid());
	}else{
	
		fprintf(stderr, "[pai] Meu PID: %ld\n", (long) getpid());
	}


	return EXIT_SUCCESS;
}
