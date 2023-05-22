#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista)
{
    pLista->pPrimeiro = (TCelula *)malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista)
{
    return (pLista->pPrimeiro == NULL);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x)
{

    pLista->pUltimo->pProx = (TCelula *)malloc(sizeof(TCelula));

    pLista->pUltimo = pLista->pUltimo->pProx;

    strcpy(pLista->pUltimo->item.nome, x.nome);

    pLista->pUltimo->pProx = NULL;

    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX)
{
    if (TLista_EhVazia(pLista))
        return 0;
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux->item;
    pLista->pPrimeiro->pProx = pAux->pProx;
    free(pAux);
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {

    TCelula *aux;
    aux = pLista->pPrimeiro->pProx;
    while (aux->pProx != NULL) {
    
        printf("%s ", aux->item.nome);
        aux = aux->pProx;
    }
    printf("%s\n", aux->item.nome);
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {

    TCelula *pAux = pLista->pPrimeiro, *pAux2;

    while (pAux != NULL) {
    
        pAux2 = pAux;
        pAux = pAux->pProx;
        free(pAux2);
    }

    pLista->pPrimeiro = NULL;
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2) {
    pLista1->pUltimo->pProx = pLista2->pPrimeiro->pProx;
    pLista1->pUltimo = pLista2->pUltimo;
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str) {

   TCelula *aux, *aux1;
   aux = pLista1->pPrimeiro;

    while (strcmp(aux->item.nome, str) != 0) {
    
        aux1 = aux;
        aux = aux->pProx;
    }

    aux1->pProx = pLista2->pPrimeiro->pProx;
    pLista2->pUltimo->pProx = aux;
}
