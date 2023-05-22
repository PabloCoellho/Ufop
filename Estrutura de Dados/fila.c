#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void TFila_Inicia (TFila **fila) {
    (*fila)->cabeca = (TCelula *) malloc (sizeof(TCelula));
    (*fila)->cabeca = NULL;
    (*fila)->fim = (*fila)->cabeca;
       
}

int TFila_EhVazia (TFila *fila) {
    return fila->cabeca == fila->fim;
}

void TFila_Enfileira (TFila **fila, int x) {
    TCelula *aux = (TCelula *) malloc (sizeof(TCelula));
    aux->item.chave = x;
    aux->prox = NULL;
    (*fila)->fim->prox = aux;
    (*fila)->fim = aux;
}

int TFila_Desenfileira (TFila *fila) {
    if (TFila_EhVazia(fila))
        return 0;
    TCelula *aux = fila->cabeca->prox;
    fila->cabeca->prox = fila->cabeca->prox->prox;
    free(aux);
    return 1;
}

void TFila_Libera (TFila *fila) {
    TItem t;
    while(TFila_Desenfileira(fila, &t));
}

void TFila_Impressao(TFila *fila) {
    if (fila->cabeca->prox != NULL) {
        printf("%d ", fila->cabeca->item);
        fila->cabeca->prox = fila->cabeca->prox->prox;
    }
}
