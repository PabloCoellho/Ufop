#include <stdio.h>
#include <stdlib.h>

void MERGESORT(int v[8], int l, int r);
void MERGE(int v[8], int l, int m, int r);

int main() {
    int v[7], l = 0, r = 7;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n");
    MERGESORT(v, l, r);
    return 0;
}

void MERGESORT(int v[8], int l, int r) {
    int m;
    if(l < r) {
        m = (l+r) / 2;
        MERGESORT(v, l, m);
        MERGESORT(v, m+1, r);
        MERGE(v, l, m, r);
        for (int i = 0; i < 8; i++) 
            printf("%d ", v[i]);
        printf("\n");
    }
}

void MERGE(int v[7], int l, int m, int r) {
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
