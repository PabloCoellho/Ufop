#include <stdio.h>

int main() {
    int v[8], aux, min;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n"); 
    for (int i = 0; i < 8; i++) {
        min = i;
        for (int j = i+1; j < 8; j++) {
            if(v[j] < v[min]) 
                min = j;
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
        for (int k = 0; k < 8; k++) 
            printf("%d ", v[k]);
         printf("\n");  
    }       
    return 0;
}