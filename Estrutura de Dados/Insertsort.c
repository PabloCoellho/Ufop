#include <stdio.h>

int main() {
    int v[7], aux, j;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n"); 
    for (int i = 1; i < 7; i++) {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && aux < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
        for (int k = 0; k < 7; k++) 
            printf("%d ", v[k]);
        printf("\n");  
    }       
    return 0;
}