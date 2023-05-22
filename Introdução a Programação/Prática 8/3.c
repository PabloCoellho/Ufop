#include <stdio.h>
#include <stdlib.h>

int main() {
	double **A, **B, **soma = 0;
	int m, n;
	printf("Digite a quantidade de linhas e colunas da matriz: ");
	scanf("%d %d", &m, &n);
	A = malloc (m * sizeof(double*));
	for (int i = 0; i < m; i++)
		A[i] = malloc (n * sizeof(double));
	B = malloc (m * sizeof(double*));
	for (int i = 0; i < m; i++)
		B[i] = malloc (n * sizeof(double));
	soma = malloc (m * sizeof(double*));
	for (int i = 0; i < m; i++)
		soma[i] = malloc (n * sizeof(double));
	printf("Digite os valores da matriz 1\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf("%lf", &A[i] [j]);
	}
	printf("Digite os valores da matriz 2\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf("%lf", &B[i] [j]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			soma[i] [j] += A[i] [j] + B[i] [j];
	}
	printf("A soma das matrizes 1 e 2 é: \n");
	for (int i = 0; i < m; i++) {
		printf("\n");
		for (int j = 0; j < n; j++)
			printf("%5.2lf ", soma[i] [j]);
	}
	printf("\n");
	for (int i = 0; i < m; i++) {
		free(A[i]);
		free(B[i]);
		free(soma[i]);
	}
	free(A);
	free(B);
	free(soma);
	return 0;
}