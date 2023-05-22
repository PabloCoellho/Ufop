#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, *vet1, *vet2, *vet3, media, soma = 0, a = 0, b = 0;
	printf("Digite o valor de n: ");
	scanf("%d", &n);
	vet1 = malloc (n * sizeof(int));
	printf("Digite os valores do vetor: ");
	for (int i = 0; i < n; i++) 
		scanf("%d", &vet1[i]);
	for (int i = 0; i < n; i++) {
		soma += vet1[i];
	}
	media = soma / n;
	printf("A média é: %d\n", media);
	for (int i = 0; i < n; i++) {
		if (vet1[i] < media)
			a++;
		else
			b++;
	}
	vet2 = malloc (a * sizeof(int));
	vet3 = malloc (b * sizeof(int));
	a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (vet1[i] < media) {
			vet2[a] = vet1[i];
			a++;
		}
		else {
			vet3[b] = vet1[i];
			b++;
		}
	}
	printf("Vetor com os valores abaixo da média: [ ");
	for (int i = 0; i < a; i++) {
		printf("%d ", vet2[i]);
	}
	printf("]\n");
	printf("Vetor com os valores iguais ou acima da média: [ ");
	for (int i = 0; i < b; i++) {
		printf("%d ", vet3[i]);
	}
	printf("]\n");
	free(vet1);
	free(vet2);
	free(vet3);
	return 0;
}