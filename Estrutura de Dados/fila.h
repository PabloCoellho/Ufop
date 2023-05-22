#ifndef fila_h
#define fila_h
#include <stdio.h>

typedef struct {
    int chave;
}TItem;

typedef struct {
    TItem item;
    struct Celula *prox;
}TCelula;

typedef struct {
    TCelula *cabeca;
    TCelula *fim;
}TFila;

void TFila_Inicia (TFila **fila);

int TFila_EhVazia (TFila *fila);

void TFila_Enfileira (TFila **fila, int x);

int TFila_Desenfileira (TFila *fila);

void TFila_Libera (TFila *fila);

void TFila_Impressao(TFila *fila);
#endif