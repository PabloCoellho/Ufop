#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int a, b;
    printf("Digite o número A:\n");
    scanf("%d", &a);
    printf("Digite o número B:\n");
    scanf("%d", &b);
    int nroAleatorio = a + rand() % (b - a + 1);
    printf("Numero gerado: %d\n", nroAleatorio);
    return 0;
}
