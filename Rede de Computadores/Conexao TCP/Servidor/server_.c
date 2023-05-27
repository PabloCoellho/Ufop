/****************** SERVER CODE ****************/

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
  int welcomeSocket, newSocket,safe,total=0;
  char recvBuffer[1024], sendBuffer[1024],copia[1024]="./D/";
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  serverAddr.sin_family = AF_INET; 
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  if(listen(welcomeSocket,5)==0)
    printf("Listening\n");
  else
    printf("Error\n");

  newSocket = accept(welcomeSocket, (struct sockaddr *) NULL, NULL);
  if (newSocket==-1) {
    perror("Accept");
    return 0;
  }
  printf ("cliente conectou.\n");

////////////////////////////////////////////

  printf("Esperando Nome do Arquivo...\n");
  recv(newSocket, recvBuffer, sizeof(recvBuffer), 0);
  strcat(copia,recvBuffer);
  printf("Nome do Arquivo para Baixar = %s\n", copia);
  
////////////////////////////////////////////

  FILE* fp = fopen(copia, "wb");
  if(fp != NULL){
    while( (safe = recv(newSocket, recvBuffer, 1024,0))> 0 ) {
      total+=safe;
      fwrite(recvBuffer, 1, safe, fp);
      if(safe<1024)
        break;
    }
    printf("Total de Bytes: %d\n",total);

    fclose(fp);
    } else {
      perror("File");
    }
  //  close(confd);
  //}

////////////////////////////////////////////

  strcpy(sendBuffer, "Arquivo Recebido!");
  printf("enviando mensagem de volta....\n");
  send(newSocket,sendBuffer,sizeof(sendBuffer),0);

  printf("fechando conexao...\n");
  close(newSocket);

  return 0;
}