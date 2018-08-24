#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigproc();
void quitproc(); 
 
int
main()
{
	signal(SIGINT, sigproc);
	signal(SIGQUIT, quitproc);
	printf("ctrl-c disabled use ctrl-\\ to quit\n");
	for(;;); /* infinite loop */
	return 0;
}
 
void sigproc()
{ 		 
	signal(SIGINT, sigproc); /*  */
	printf("you have pressed ctrl-c \n");
}
 
void quitproc()
{ 	
	printf("ctrl-\\ pressed to quit\n");
	exit(0); /* normal exit status */
}


