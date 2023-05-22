#include "buscabinaria.h"
#include <stdio.h>
#include <stdlib.h>

int *Aloca_Vetor (int *v, int n) {
    v = (int *) malloc (n * sizeof(int));
    return v;
}

double Vetor_Find (int *v , int a, int n) {
    double i, area = 0, esq, dir;
    int areat = 0;

    for (int j = 0; j < n; j++) {
        areat += v[j];
    }      

    if (areat < a)
        return -1;

    else if (areat == a)
        return 0;

    MERGESORT(v, 0, n-1);

    esq = 0; 
    dir = v[n-1];
    
    do {
        i = (esq + dir) / 2;
        area = 0;

        for (int j = 0; j < n; j++) {
            if (i < v[j])
                area += (v[j] - i);
        }      

        if (area > a) 
            esq = i + 0.0000001;
        
        else 
            dir = i - 0.0000001;
                   
    } while (esq <= dir);

            
    return i;   
}

int *Desaloca_Vetor (int *v) {
    free(v);
    return v;
}

void MERGESORT(int *v, int l, int r) {
    int m;
    if(l < r) {
        m = (l+r) / 2;
        MERGESORT(v, l, m);
        MERGESORT(v, m+1, r);
        MERGE(v, l, m, r);
    }
}

void MERGE(int *v, int l, int m, int r) {
    int i = 0, j = 0;
    int size_l = m - l + 1, size_r = r - m;
    int *vet_l, *vet_r;
    vet_l = (int *) malloc (size_l * sizeof(int));
    vet_r = (int *) malloc (size_r * sizeof (int));

    for (int u = 0; u < size_l; u++)
        vet_l[u] = v[u+l];
    for (int p = 0; p < size_r; p++)
        vet_r[p] = v[m+p+1];
    for (int k = l; k <= r; k++) {
        if (i == size_l) {
            v[k] = vet_r[j++];
        }
        else if (j == size_r) {
            v[k] = vet_l[i++];
        }

        else if (vet_l[i] <= vet_r[j]) {
            v[k] = vet_l[i++];
        }
        else
            v[k] = vet_r[j++];
    }
    free(vet_r);
    free(vet_l);
}