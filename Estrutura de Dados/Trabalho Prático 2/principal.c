#include "ordenacao.h"
#include <stdio.h>

int main() {
    paises *pais = NULL;
    int n;
    scanf("%d", &n);
    pais = alocarpaises(pais, n);
    pais = lerpaises(pais, n);
    ordenarpaises(pais, n);
    impressao(pais, n);
    pais = desalocarpaises(pais);
    return 0;
}