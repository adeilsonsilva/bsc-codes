#include <stdio.h>
#include <unistd.h>

int main()
{
    int valor = 500;

    long pid_filho = fork();

    if (pid_filho == 0){
	printf("-----------\nProcesso filho\n");
        printf("PID processo filho.. %ld\n", (long)getpid());
	printf("valor inicial filho = %d\n", valor);
	valor = 200;
    }else{

	printf("-----------\nProcesso pai\n");
	printf("PID processo pai %ld\n", (long)getpid());
	printf("PID processo filho %ld\n", pid_filho);
	printf("valor inicial pai = %d\n", valor);
	valor = 100;
    }

    printf("valor = %d\n", valor);
    return 0;
}


