#include "prioridade.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
TipoCaixa *alocaVetor(TipoCaixa *heap, int n){
    heap = (TipoCaixa *) malloc (n * sizeof(TipoCaixa));
    return heap;
}

//Manter como especificado
TipoCaixa *desalocaVetor(TipoCaixa *heap){
    free(heap);
    return heap;
}

//Manter como especificado
void Heap_Constroi(TipoCaixa *heap, int n){
    int esq = ( n / 2) - 1;
    while (esq >= 0) {
        Heap_Refaz(heap, esq, n-1);
        esq--;
    }
}

//Manter como especificado
void Heap_Refaz(TipoCaixa *heap, int esq, int dir){
    int i = esq;
    int j = i * 2 + 1;
    
    TipoCaixa aux = heap[i];
    while (j <= dir) {
        if (j < dir ) {
            if(heap[j].tempoaten > heap[j+1].tempoaten)
                j = j + 1;
            else if (heap[j].tempoaten == heap[j+1].tempoaten && heap[j+1].id < heap[j].id)
                j = j + 1;
        }
        if (aux.tempoaten < heap[j].tempoaten)
            break;
        else if (aux.tempoaten == heap[j].tempoaten && aux.id < heap[j].id)
            break;
        heap[i] = heap[j];
        i = j;
        j = i * 2 + 1;
    }
    heap[i] = aux;
}
