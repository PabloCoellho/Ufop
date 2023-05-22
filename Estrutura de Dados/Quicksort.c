#include <stdio.h>

void QUICKSORT (int *v, int l, int r);
int PARTITION (int *v, int l, int r);

int main() {
    int v[7], l = 0, r = 6;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n");
    QUICKSORT(v, l, r);
    for (int i = 0; i < 7; i++) 
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}

void QUICKSORT (int *v, int l, int r) {
    int q;
    if (l < r) {
        q = PARTITION(v, l, r);
        QUICKSORT(v, l, q-1);
        QUICKSORT(v, q+1, r);
    }
}

int PARTITION (int *v, int l, int r) {
    int x, i, aux;
    x = v[r];
    i = l - 1;
    for (int j = l; j < r; j++) {
        if (v[j] <= x) {
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            for (int i = 0; i < 7; i++)
                printf("%d ", v[i]);
            printf("\n");
        }
        
    }
    aux = v[i+1];
    v[i+1] = v[r];
    v[r] = aux;
    for (int i = 0; i < 7; i++)
        printf("%d ", v[i]);
    printf("\n");
    return i+1;
}