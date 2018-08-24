#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sighup(); 
void sigint();
void sigquit();

int
main()
{ int pid;

   if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
   }
    
   if (pid == 0){ 

       signal(SIGHUP,sighup);
       signal(SIGINT,sigint);
       signal(SIGQUIT, sigquit);
       for(;;);

     } else { 

       printf("\nPAI: SIGHUP\n\n");
       kill(pid,SIGHUP);
       sleep(5);
       printf("\nPAI: SIGINT\n\n");
       kill(pid,SIGINT);
       sleep(5);
       printf("\nPAI: SIGQUIT\n\n");
       kill(pid,SIGQUIT);
       sleep(5);

     }

     return(0);
}

void 
sighup()
{  
   signal(SIGHUP,sighup);
   printf("FILHO: SIGHUP\n");
}

void 
sigint()
{  
   signal(SIGINT,sigint);
   printf("FILHO: SIGINT\n");
}

void 
sigquit()
{ 
   printf("MORTO PELO PROCESSO PAI\n");
   exit(0);
}

