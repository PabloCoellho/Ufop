#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int fluxoCaminho;
int tamTotalC;
 
typedef struct aresta{ 
    int vdestino; 
    int limiteSup;
    int dir;
    struct aresta *prox;  
} Aresta;

typedef struct vertice{
    Aresta *primeiro;
} Vertice; 

typedef struct {
    Vertice *listaadj;
} Grafo; 

void lerLinha1(int *n, int *m);
Grafo *alocarGrafo(Grafo *g, int n);
void lerMLinhas (Grafo *g, int m); 
void NovoVertice (Vertice *lista, int vdestino, int limitesup);
void busca(Grafo *g, int i, int *camT, int *vVisitado, int n, int tamCaminho, int *chegou);
void FordFulkerson(Grafo* go, int n);
Grafo *desalocarGrafo(Grafo *g);
void imprimir(int ini, int arco, int aumen);
int chamaBusca(Grafo *g, int i, int *camT, int *vVisitado, int n);
void dimiAumenFluxo(Aresta *aux, int mm);
int verifLimSup(Aresta *aux);
void limpaVisitacoes(int *camT, int *vVisitado, int n);
int *alocaVetor(int *vetor, int n);
int *desalocaVetor(int *vetor);


#endif