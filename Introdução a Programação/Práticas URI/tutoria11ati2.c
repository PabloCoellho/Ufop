#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, **A;
	printf("Digite o numero de clientes: ");
	scanf("%d", &n);
	A = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		A[i] = malloc(5 * sizeof(int));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			printf("Digite a quantidade do produto %d comprado pelo cliente %d: ", j+1, i+1);
			scanf("%d", &A[i] [j]);
		}
	}
	for (int i = 0; i < n; i++) {
		float conta[5], total = 0; 
		for(int j = 0; j < 5; j++) 
			conta[j] = 0;
		conta[0] = A[i] [0] * 5;
		conta[1] = A[i] [1] * 15;
		conta[2] = A[i] [2] * 9;
		conta[3] = A[i] [3] * 20;
		conta[4] = A[i] [4] * 34;
		for(int k = 0; k < 5; k++)
			total += conta[k];
		printf("Valor total cliente %d: %.2f\n", i+1, total);
	}
	for(int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	return 0;
}