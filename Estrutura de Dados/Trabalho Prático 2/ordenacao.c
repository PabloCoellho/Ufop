#include "ordenacao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

paises *alocarpaises(paises *pais, int n) {
    pais = (paises *) malloc (n * sizeof(paises));
    return pais;
}

paises *lerpaises (paises *pais, int n) { 
    for (int i = 0; i < n; i++) {
        scanf("%s", pais[i].nome);
        scanf("%d", &pais[i].ouro);
        scanf("%d", &pais[i].prata);
        scanf("%d", &pais[i].bronze);
    }
    return pais;
}

void impressao (paises *pais, int n) {
    for (int i = 0; i < n; i++) 
        printf("%s %d %d %d\n", pais[i].nome, pais[i].ouro, pais[i].prata, pais[i].bronze);
    
}

paises *desalocarpaises (paises *pais) {
    free(pais);
    return pais;
}

void ordenarpaises (paises *pais, int n) {
    paises aux;
    int max;
    for (int i = 0; i < n; i++) {
        max = i;
        for (int j = i+1; j < n; j++) {
            if(pais[j].ouro > pais[max].ouro) 
                max = j;
            else if (pais[j].ouro == pais[max].ouro) {
                if (pais[j].prata > pais[max].prata)
                    max = j;
                else if (pais[j].prata == pais[max].prata) {
                    if (pais[j].bronze > pais[max].bronze)
                        max = j;
                    else if (pais[j].bronze == pais[max].bronze) {
                        int a = strcmp(pais[j].nome, pais[max].nome);
                        if (a < 0)
                            max = j;  
                    }
                } 
            }
        }
        aux = pais[i];
        pais[i] = pais[max];
        pais[max] = aux;
    }
}