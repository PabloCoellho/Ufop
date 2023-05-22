#include <stdio.h>

int main() {
    int v[7], aux, j, h;
    for (int i = 0; i < 7; i++) {
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    printf("\n"); 
    for (h = 1; h < 7;)
        h = 3 * h + 1;

    do {
        h = (h-1) / 3;
        printf("h = %d\n", h);
        for (int i = h; i < 7; i++) {
            aux = v[i];
            j = i;
            while (v[j-h] > aux) {
                v[j] = v[j-h];
                j = j - h;
                if( j < h)
                    break;
            }
            v[j] = aux;
            for (int k = 0; k < 7; k++) 
                printf("%d ", v[k]);
            printf("\n");  
        }
    }while(h != 1);
       
    return 0;
}