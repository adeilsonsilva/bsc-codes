#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
  int sockfd,n;
  struct sockaddr_in servaddr;
  char sendline[1000];
  char recvline[1000];
  
  if (argc != 2)
   {
      printf("USAGE: %s <IP address>\n", argv[0]);
      exit(1);
   }
  
   sockfd=socket(AF_INET,SOCK_STREAM,0);
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=inet_addr(argv[1]);
   servaddr.sin_port=htons(32000);
   
   connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
     
      n=recv(sockfd,recvline,1000,0);
      recvline[n]=0;
      fputs(recvline,stdout);
         
   while (fgets(sendline, 1000,stdin) != NULL)
    { 
      send(sockfd,sendline,1000,0);
      /*n=recv(sockfd,recvline,1000,0);
      recvline[n]=0;      
      fputs(recvline,stdout);*/
   } 
   
   return 0;
}
