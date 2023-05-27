#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

//a) Encontrar o maior valor em um vetor
void MaiorValor(int *vetor, int esq, int dir, int *maior) {
    if (dir <= esq)
        return;
    int meio = floor((dir + esq) / 2);

    if(vetor[meio] > *maior)
        *maior = vetor[meio];

    MaiorValor(vetor, esq, meio, maior);
    MaiorValor(vetor, meio+1, dir, maior); 
}

//b) Encontrar o maior e o menor elemento em um vetor
void MaiorMenor(int *vetor, int esq, int dir, int *maior, int *menor) {
    if (dir <= esq)
        return;
    int meio = floor((dir + esq) / 2);

    if(vetor[meio] > *maior)
        *maior = vetor[meio];

    if(vetor[meio] < *menor)
        *menor = vetor[meio];

    MaiorMenor(vetor, esq, meio, maior, menor);
    MaiorMenor(vetor, meio+1, dir, maior, menor); 
}

//c) Exponenciação
int Exponenciacao (int base, int potencia) {
    if (potencia == 0)
        return 1;
    
    int resul = Exponenciacao(base, potencia / 2);

    if (potencia % 2 == 0) {
        return resul * resul;
    }
    else {
        return base * resul * resul;
    }
}

int main() {
    int vetor[10];
    int maior1 = INT_MIN, maior2 = INT_MIN, menor = INT_MAX, expo;

    srand(time(NULL));

    printf("Valores do Vetor: ");
    for (int i = 0; i < 10; i++){
        vetor[i] = rand() % 100;
        printf("%d  ", vetor[i]);
    }
    printf("\n");


    MaiorValor(vetor, 0, 10, &maior1);
    printf("Maior Valor = %d\n", maior1);

    MaiorMenor(vetor, 0, 10, &maior2, &menor);
    printf("Maior = %d e Menor = %d\n", maior2, menor);

    expo = Exponenciacao(5, 4);
    printf("Exponenciacao = %d\n", expo);

    return 0; 
}