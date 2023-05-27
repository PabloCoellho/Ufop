/****************** CLIENT CODE ****************/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(){
  int cSocket,portMann,safe;
  char recvBuffer[1024], sendBuffer[1024],ipMann[15],fileName[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  cSocket = socket(PF_INET, SOCK_STREAM, 0);
  serverAddr.sin_family = AF_INET;
  
  //portMann=7891;
  scanf("%d",&portMann);
  serverAddr.sin_port = htons(portMann);

  //strcpy(ipMann,"127.0.0.1");
  scanf("%s", ipMann);
  serverAddr.sin_addr.s_addr = inet_addr(ipMann);

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  addr_size = sizeof serverAddr;
  safe = connect(cSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  if(safe==-1){
    printf("Servidor com Porta: %i e Ip: %s não encontrado.\n",portMann,ipMann);
    return 0;
  }

  printf("Servidor com Porta: %i e Ip: %s foi encontrado!\n",portMann,ipMann);

////////////////////////////////////////////

  printf("Esperando Nome do Arquivo...\n");

  scanf("%s", fileName);

  strcpy(sendBuffer,fileName);

  send(cSocket,sendBuffer,sizeof(sendBuffer),0);

////////////////////////////////////////////

  FILE *fp = fopen(fileName, "rb");
  if(fp == NULL){
    printf("Arquivo %s não encontrado.\n",fileName);
    return 0;
  }
  while( (safe = fread(sendBuffer, 1, sizeof(sendBuffer), fp))>0 ){
    send(cSocket, sendBuffer, safe, 0);
    if(safe<1024)
      break;
  }  

  fclose(fp);

////////////////////////////////////////////

  recv(cSocket,recvBuffer, sizeof(recvBuffer), 0);

  printf("\nData received: %s\n",recvBuffer);

  printf("Fechando Conexao e encerrando o programa...\n"); 
  close(cSocket);

  return 0;
}

/*
Feito - Seja um servidor e um cliente em execução.
Feito - Ao executar o cliente, pede-se o IP e porta do servidor.
Feito - Em seguida, o programa irá pedir o nome do arquivo que que está armazenado no cliente e que será enviado para o servidor. 
Feito - Então, o programa cliente realiza uma conexão TCP com o servidor e envia o arquivo. 
Feito - O arquivo pode possuir qualquer tamanho e extensão.
*/