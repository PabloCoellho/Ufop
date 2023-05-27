#ifndef DFS_H
#define DFS_H

#include <stdio.h>
#include <stdlib.h> 

typedef struct aresta{ 
    int vdestino; 
    int peso;
    int visitada;
    struct aresta *prox;  
} Aresta;

typedef struct vertice{
    Aresta *primeiro;
    int visitado;
} Vertice; 

typedef struct {
    Vertice *listaadj;
} Grafo; 

void lerLinha1(int *n, int *m, int *b, int *i);
Grafo *alocarGrafo(Grafo *g, int n);
void lerMLinhas (Grafo *g, int b, int m); 
void busca(Grafo *g, int i);
void NovoVertice(Vertice *lista, int vdestino, int peso);
Grafo *desalocarGrafo(Grafo *g);

#endif