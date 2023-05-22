#include <stdio.h>

int main() {
    int v[7], aux;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n"); 
    for (int i = 0; i < 7; i++) {
        for (int j = 1; j < 7-i; j++) {

            if(v[j] < v[j-1]) {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                for (int k = 0; k < 7; k++) 
                    printf("%d ", v[k]);
                printf("\n");  
            }
        }
    }       
    return 0;
}