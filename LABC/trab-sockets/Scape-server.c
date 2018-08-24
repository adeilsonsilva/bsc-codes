#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

void *func_thread(void *arg);

int main(int argc, char**argv)
{
   int sockfd,ids;
   struct sockaddr_in servaddr,cliaddr;
   socklen_t len;
   pthread_t threads;
   char *cli_addr_str;

   sockfd=socket(AF_INET,SOCK_STREAM,0); //SOCK_STREAM PADRÃO PRA TCP

   servaddr.sin_family = AF_INET; //FAMILIA
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY); //ENDEREÇO IP
   servaddr.sin_port=htons(32000); //PORTA
   
   bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
   listen(sockfd, 40); //SOCKFD = SOCKET ID E NÚMERO DE CONEXÕES
   

   for (;;)
   {
      len = sizeof(cliaddr);
      int connfd = accept(sockfd, (struct sockaddr *)&cliaddr,&len);
      ids=connfd;
      	
      printf("-------------------------------------------------------\n");
      cli_addr_str = inet_ntoa(cliaddr.sin_addr);
      printf("SCAPE:Nova conexao a partir de: %s:%d\n", cli_addr_str,servaddr.sin_port); 
      
      pthread_create(&threads, NULL, &func_thread, (void *)&ids);      
          
   }
}

void *func_thread(void *arg)
{
	unsigned int aux;
	int n;
	char msg[1000];
	char bem_vindo[]="\t\t*******************************************\n\t\t*Bem vindo ao mensageiro instantâneo Scape*\n\t\t*******************************************\n";
	aux = *(unsigned int *)arg;
	
	send(aux,bem_vindo,strlen(bem_vindo),0);
	
      do
      { 
	    n=recv(aux,msg, 1000, 0);
	    msg[n] = 0;
	    printf("\n\t\t\t%s\n", msg);
	  
      } while(n>0);
		 
	

        
        return 0;
}
