#define v 15
 
#include <stdio.h>

int main() {
    int vetor1[v], vetor2[v], n;
    printf("Digite o vetor de 15 posições\n");
	for (int i = 0; i < v; i++)  {  
		scanf("%d", &vetor1[i]);
	}
	printf("O vetor digitado eh: ");
    for (int i = 0; i < v; i++) {
    	printf("%d ", vetor1[i]);
    }
	printf("\nDigite o número de posições que o vetor deve ser rotacionado\n");
	scanf("%d", &n);
    printf("O vetor rotacionado eh: ");
    for (int i = 0; i < n; i++) {
        vetor2[i] = vetor1[i];
    }
    for (int i = 0; i < (v - n); i++) {
        vetor1[i] = vetor1[i+n];
    }
    for (int i = 0; i < n; i++) {
        vetor1[v-n+i] = vetor2[i];
    }
    for (int i = 0; i < v; i++) {
        printf("%d ", vetor1[i]);
    }
	printf("\n");
    return 0;
}
