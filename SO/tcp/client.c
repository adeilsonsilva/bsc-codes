#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"USO %s ip_server port_server\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERRO AO ABRIR O SOCKET");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERRO, SERVIDOR NAO ENCONTRADO\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERRO DE CONEXAO");

    printf("Cliente conectado ao servidor! Enviando mensagem...\n");

    n = write(sockfd,"Mensagem",17);
    if (n < 0) 
         error("ERRO, MSG NAO ENVIADA");

    printf("Aguardando resposta do servidor!\n");

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("MSG NAO RECEBIDA...");
    printf("%s\n",buffer);

    close(sockfd);
    printf("Conexão encerrada com o servidor.\n");
    return 0;
}

