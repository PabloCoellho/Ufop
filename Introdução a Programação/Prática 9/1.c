#include <stdio.h>
#include <stdlib.h>

double** transposta (double **A, int m, int n);
	
double** criaMatriz(int m, int n);

void liberaMatriz(double **A, int m);

int main() {
	int m, n;
	double **A, **At;
	printf("Digite as dimensões da matriz: ");
	scanf("%d %d", &m, &n);
	if (criaMatriz(m, n) == NULL)
		return 0;
	else {
		A = criaMatriz(m, n);
		printf("Digite os valores da matriz:\n");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				scanf("%lf", &A[i] [j]);
		}
		printf("\nMatriz original:");
		for (int i = 0; i < m; i++) {
			printf("\n");
			for (int j = 0; j < n; j++) 
				printf("%2.0lf ", A[i] [j]);
		}

		At = transposta(A, m, n);
		printf("\n\nMatriz transposta:");
		for (int i = 0; i < n; i++) {
			printf("\n");
			for (int j = 0; j < m; j++)
				printf("%2.0lf ", At[i] [j]);
		}
		printf("\n");
		liberaMatriz(A, m);
		liberaMatriz(At, m);
	}
	return 0;
}

double** transposta (double **A, int m, int n) {
	double **At;
	At = criaMatriz(n, m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			At[j] [i] = A[i] [j];
	}
	return At;
}

double** criaMatriz(int m, int n) {
	double **A = NULL;
	A = malloc(m * sizeof(double*));
	for (int i = 0; i < m; i++) {
		A[i] = malloc(n * sizeof(double));
	}
	return A;
}

void liberaMatriz(double **A, int m) {
	for (int i = 0; i < m; i++)
		free(A[i]);
	free(A);
}