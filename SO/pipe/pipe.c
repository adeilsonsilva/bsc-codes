#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(void)
{
        int     fd[2], nbytes;
        pid_t   childpid;
	char	pid[4];
        char    readbuffer[80];

        pipe(fd);
        
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                /* filho fecha a saida do pipe para esperar ip do pai */
                close(fd[1]);

                /* le mensagem do pai */
                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("PID_filho = %ld\n", (long) getpid());
                printf("Filho recebeu a msg: %s [numero de bytes lidos: %d]\n", readbuffer, nbytes);
        }
        else
        {
                /* pai fecha entrada do pipe para mandar id ao filho */
                close(fd[0]);
		//sprintf(pid, "%ld", (long) getpid());
		sprintf(pid, "%ld", (long) childpid);
                /* envia id via pipe */
                write(fd[1], pid, 5);
                exit(0);
        }
        
        return(0);
}

