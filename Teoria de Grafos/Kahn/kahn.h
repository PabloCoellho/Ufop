#ifndef KAHN_H
#define KAHN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
    int aresta;
} Matriz; 

typedef struct {
    Matriz **matrizadj;
    int *vEntrada;
    int arcos;
} Grafo; 

void lerLinha1(int *n, int *m);
Grafo *alocarGrafo(Grafo *g, int n);
void lerMLinhas (Grafo *g, int m);
void ordenacaoKahn (Grafo *g, int n);
Grafo *desalocarGrafo(Grafo *g, int n);
int arcoEntrada (Grafo *g, int n, int *s);
void imprime(int *l, int j);
int listaS(int *s, int n);
int *alocaVetor(int *v, int n);
int *desalocaVetor(int *v);

#endif