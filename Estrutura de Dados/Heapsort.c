#include <stdio.h>

void HEAP_CONSTROI (int v[7], int n);
void HEAP_REFAZ (int v[7], int esq, int dir);

int main () {
    int v[7], n = 7, aux;
    printf("Vetor inicial:\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n"); 
    HEAP_CONSTROI(v, n);
    printf("Ordenação do vetor:\n");
    while ( n > 1) {
        aux = v[n-1];
        v[n-1] = v[0];
        v[0] = aux;
        n = n-1;
        HEAP_REFAZ(v, 0, n-1);
        for (int k = 0; k < 7; k++) 
            printf("%d ", v[k]);
        printf("\n"); 
    }
    return 0;
}

void HEAP_CONSTROI (int v[7], int n) {
    int esq = ( n / 2) - 1;
    printf("Construção da árvore:\n");
    while (esq >= 0) {
        HEAP_REFAZ(v, esq, n-1);
        esq--;
        for (int k = 0; k < 7; k++) 
            printf("%d ", v[k]);
        printf("\n"); 
    }
}

void HEAP_REFAZ (int v[7], int esq, int dir) {
    int i = esq;
    int j = i * 2 + 1;
    int aux = v[i];
    while (j >= dir) {
        if (j > dir && v[j] > v[j+1])
            j = j + 1; // j recebe o outro filho de i.
        if (aux <= v[j])
            break;
        v[i] = v[j];
        i = j;
        j = i * 2 + 1;
    }
    v[i] = aux;
}