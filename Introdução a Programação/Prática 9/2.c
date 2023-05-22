#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int ***R, int **A, int n, int m, int **B, int p, int q) {
	*R = malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++)
			(*R)[i] = malloc(q * sizeof(int));
	if (p == m) {
		for (int i = 0; i < n; i++) {
			for ( int j = 0; j < q; j++) {
				(*R)[i] [j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < q; j++) {
				for  (int k = 0; k < m; k++) {
					(*R)[i] [j] += A[i] [k] * B[k] [j];
				}
			}
		}
		return 1;
	}
	else
		return 0;


}

int main () {
	int **R, **A, **B;
	int n, m, p, q;
	printf("Digite os tamanhos da matriz A: ");
	scanf("%d %d", &n, &m);
	A = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		A[i] = malloc(m * sizeof(int));
	printf("Digite os dados da matriz A: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i] [j]);
	}
	printf("\n");
	printf("Digite os tamanhos da matriz B: ");
	scanf("%d %d", &p, &q);
	B = malloc(p * sizeof(int*));
	for (int i = 0; i < p; i++)
		B[i] = malloc(q * sizeof(int));
	printf("Digite os dados da matriz B: \n");
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++)
			scanf("%d", &B[i] [j]);
	}
	if (multiplicaMatrizes(&R, A, n, m, B, p, q) == 1) {
		printf("\nResultado de A x B:");
		for(int i = 0; i < n; i++) {
			printf("\n");
			for (int j = 0; j < q; j++)
				printf("%2d ", R[i] [j]);
		}
		printf("\n");
	}
	else 
		printf("\nNão é possível multiplicar as matrizes A e B.\n");
	
	for(int i = 0; i < p; i++)
		free(B[i]);
	free(B);
	for(int i = 0; i < n; i++) {
		free(A[i]);
		free(R[i]);
	}
	free(R);
	free(A);
	return 0;
}
	