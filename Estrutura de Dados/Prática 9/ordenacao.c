#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    vetor = (int *) malloc (n * sizeof(int));
    return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
    int l = 0, r = n-1;
        
    MERGESORT(vetor, l, r, movimentos);
    
}

void MERGESORT(int *vetor, int l, int r, int *movimentos) {
    int m;
    
    if(l < r) {
        m = (l+r) / 2;
        MERGESORT(vetor, l, m, movimentos);
        MERGESORT(vetor, m+1, r, movimentos);
        MERGE(vetor, l, m, r, movimentos);
    }
}

void MERGE(int *vetor, int l, int m, int r, int *movimentos) {
    int i = 0, j = 0;
    int size_l = m - l + 1, size_r = r - m;
    int *vet_l, *vet_r;
    vet_l = (int *) malloc (size_l * sizeof(int));
    vet_r = (int *) malloc (size_r * sizeof (int));
    for (int u = 0; u < size_l; u++)
        vet_l[u] = vetor[u+l];
    for (int p = 0; p < size_r; p++)
        vet_r[p] = vetor[m+p+1];
    for (int k = l; k <= r; k++) {
        if (i == size_l) {
            vetor[k] = vet_r[j++];
        }
        else if (j == size_r) {
            vetor[k] = vet_l[i++];
        }
        else if (vet_l[i] <= vet_r[j]) {
            vetor[k] = vet_l[i++];
        }
        else {
            vetor[k] = vet_r[j++];
            *movimentos = *movimentos + (size_l - i);
        }
    }
    free(vet_r);
    free(vet_l);
}
