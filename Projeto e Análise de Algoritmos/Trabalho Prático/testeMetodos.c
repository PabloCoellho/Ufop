#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;

void merge(int *vetor, int p, int q, int r);
void mergeSort(int *vetor, int l, int r);
void selection_sort(int *vetor);
void radixsort(int *vetor);
void callMergeSort(int *vGerador);
void callSelectionSort(int *vGerador);
void callRadixSort(int *vGerador);
void testeAutomatico(int *vGerador);
void testeEspecifico(int *vGerador);

int *alocaVetor(int *vetor) {
    vetor = (int *) malloc ((n+1) * sizeof(int));
    return vetor;
}

int *desalocaVetor(int *vetor) {
    free(vetor);
    return vetor;
}

int main() {

    int *vGerador;
    int op;

    srand(time(NULL));

    while (1){

        printf("Digite a opção desejada:\n");
        printf("1 -> teste especifico\n");
        printf("2 -> teste automatico\n");
        printf("3 -> sair\n");

        scanf("%d", &op);

        if(op == 1)
            testeEspecifico(vGerador);
        else if(op == 2)
            testeAutomatico(vGerador);
        else if(op == 3)
            break;
        else
            printf("Opcao invalida!\n");

    }

    return 0;
}

void testeEspecifico(int *vGerador){

    printf("Insira o tamanho do array: ");
    scanf("%d", &n);

    printf("Resultado expresso em ms -> ");
    printf("N = %d\n", n);
    //Alocando Vetor
    vGerador = alocaVetor(vGerador);
    printf("%12s%12s\t   %12s  %12s\n", "Instancia", "Merge", "Selection", "Radix");

    for(int k = 0; k < 20; k++){
        for (int i = 1; i <= n; i++) {
            vGerador[i] = rand() % n + 1;
        }
        printf("%12d", k + 1);
        callMergeSort(vGerador);
        callSelectionSort(vGerador);
        callRadixSort(vGerador);

        printf("\n");

    }

    //Desalocando Vetor
    vGerador = desalocaVetor(vGerador);  

}

void testeAutomatico(int *vGerador){

    for(n = 100; n <= 1000000; n*=10){
        printf("N = %d\n", n);
        //Alocando Vetor
        vGerador = alocaVetor(vGerador);
        printf("%12s%12s\t   %12s  %12s\n", "Instancia", "Merge", "Selection", "Radix");

        for(int k = 0; k < 20; k++){
            for (int i = 1; i <= n; i++) {
                vGerador[i] = rand() % n + 1;
            }
            printf("%12d", k + 1);
            callMergeSort(vGerador);
            callSelectionSort(vGerador);
            callRadixSort(vGerador);

            printf("\n");

        }

        //Desalocando Vetor
        vGerador = desalocaVetor(vGerador);
    }
}

void callMergeSort(int *vGerador){
    
    long long tempo, tempoGasto;
    int *v1;
    v1 = alocaVetor(v1);

    for (int i = 1; i <= n; i++) 
        v1[i] = vGerador[i];
    
    tempo = clock();
    mergeSort(v1, 1, n);
    tempoGasto = clock() - tempo;
    printf("%12lld\t", tempoGasto);

    v1 = desalocaVetor(v1);

}

void callSelectionSort(int *vGerador){
    
    long long tempo, tempoGasto;
    int *v1;

    v1 = alocaVetor(v1);

    for (int i = 1; i <= n; i++) 
        v1[i] = vGerador[i];

    tempo = clock();
    selection_sort(v1);
    tempoGasto = clock() - tempo;
    printf("%12lld\t", tempoGasto);

    v1 = desalocaVetor(v1);

}

void callRadixSort(int *vGerador){
    
    long long tempo, tempoGasto;
    int *v1;

    v1 = alocaVetor(v1);
    for (int i = 1; i <= n; i++) 
        v1[i] = vGerador[i];

    tempo = clock();
    radixsort(vGerador);
    tempoGasto = clock() - tempo;
    printf("%12lld\t", tempoGasto);

    v1 = desalocaVetor(v1);

}

//MERGESORT
void merge(int vetor[], int p, int q, int r) {

    //Criar v1 ← vetor[p..q] e v2 ← vetor[q+1..r]
    int tamv1 = q - p + 1;
    int tamv2 = r - q;

    int *v1, *v2;

    v1 = (int *) malloc (tamv1 * sizeof(int));
    v2 = (int *) malloc (tamv2 * sizeof(int));

    for (int i = 0; i < tamv1; i++)
        v1[i] = vetor[p + i];

    for (int j = 0; j < tamv2; j++)
        v2[j] = vetor[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < tamv1 && j < tamv2) {
        if (v1[i] <= v2[j]) {
            vetor[k] = v1[i];
            i++;
        } else {
            vetor[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < tamv1) {
        vetor[k] = v1[i];
        i++;
        k++;
    }

    while (j < tamv2) {
        vetor[k] = v2[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);
        merge(vetor, l, m, r);
    }
}

//SELECTIONSORT
void selection_sort (int vetor[]) {
    int i, j, min, aux;

    for (i = 1; i <= n; i++) {

        min = i;
        for (j = i+1; j <= n; j++) {

            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        if (i != min) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }

}

//RADIXSORT
void radixsort(int *vetor) {
    int i, exp = 1, m = 0, bucket[n + 1], temp[n + 1];

    for(i = 1; i <= n; i++) {

        if(vetor[i] > m) {
            m = vetor[i];

        }
    }

    while((m/exp) >= 1) {

        for (i = 1; i <= n; i++) 
            bucket[i] = 0;

        for(i = 1; i <= n; i++) 
            bucket[(vetor[i] / exp) % 10 + 1]++;
        
        for(i = 2; i <= n; i++) 
            bucket[i] += bucket[i-1];
        
        for(i = n; i >= 1; i--) 
            temp[--bucket[(vetor[i] / exp) % 10 + 1]] = vetor[i];

        for(i = 1; i <= n; i++) 
            vetor[i] = temp[i - 1];
                
        exp *= 10;
    }

}