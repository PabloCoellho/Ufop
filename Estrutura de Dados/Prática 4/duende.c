#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende {
  char nome[20];
  int idade;
  int escalado;
};

struct time {
  char lider[20];
  int ilider;
  char entregador[20];
  int ientregador;
  char piloto[20];
  int ipiloto;
};

void lerQuantidade(int *qtd){
  scanf("%d", qtd);
}
//Manter como especificado
TADduende *alocaDuendes(TADduende *D, int qtd){
  D = (TADduende *) malloc (qtd * sizeof(TADduende));
  return D;
}

//Manter como especificado
TADtime *alocaTimes(TADtime *T, int qtd){
  T = (TADtime *) malloc (qtd * sizeof(TADtime));
  return T;
}

//Manter como especificado
TADduende *desalocaDuendes(TADduende *D){
  free(D);
  return D;
}

//Manter como especificado
TADtime *desalocaTimes(TADtime *T){
  free(T);
  return T;
}

//Manter como especificado
void lerDuendes(TADduende *D, int qtd){
  int i;
  for (i = 0; i < qtd; i++) {
    scanf("%s %d", D[i].nome, &D[i].idade);
    D[i].escalado = 0;
  }
  //ler nome e idade de cada duente
  //aproveitar para colocar o valor 0 no campo escalado
}

//Manter como especificado
void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i, indice;
  //completar o XXX
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    //marcar o duende do indice como escalado
    //a linha abaixo copia o nome do duende para a estrutura do time
    strcpy(T[i].lider, D[indice].nome);
    T[i].ilider = D[indice].idade;
    D[indice].escalado = 1;
  }

  //repetir o laco acima, mas para o entregador
  //repetir o laco acima, mara para o piloto
  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    strcpy(T[i].entregador, D[indice].nome);
    T[i].ientregador = D[indice].idade;
    D[indice].escalado = 1;
  }

  for (i=0; i<qtd/3; i++)
  {
    indice = proximoMaisVelho(D, qtd);
    strcpy(T[i].piloto, D[indice].nome);
    T[i].ipiloto = D[indice].idade;
    D[indice].escalado = 1;
  }

}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice = -1, comp;
  comp = -1;
  //determinar o indice do duende mais velho nao escalado ainda
  //variaveis adicionais podem ser criadas
  for (int i = 0; i < qtd; i++) {
    if(D[i].escalado == 0) {
      if(comp < D[i].idade) {
        indice = i;
        comp = D[i].idade;
      }
    }
  }
  return indice;
}

//Manter como especificado
void printTimes(TADtime *T, int qtd){
  for(int i = 0; i<qtd; i++) {
    printf("Time %d\n", i+1);
    printf("%s %d\n", T[i].lider, T[i].ilider);
    printf("%s %d\n", T[i].entregador, T[i].ientregador);
    printf("%s %d\n\n", T[i].piloto, T[i].ipiloto);
  }
}
