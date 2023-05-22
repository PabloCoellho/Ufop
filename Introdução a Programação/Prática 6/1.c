#include <stdio.h>

#define v 10

void lerMatriz(int *m, int *n,  int matriz[v] [v]);
	
void imprimirMatriz(int matrizC[v] [v], int m, int n);

int main() {
	int matrizA[v] [v], matrizB[v] [v], matrizC[v] [v];
	int m, p, q, n;
	printf("Digite as dimensões da matriz A\n");
	lerMatriz(&m, &p, matrizA);
	printf("Digite as dimensões da matriz B\n");
	lerMatriz(&q, &n, matrizB);
	if (q == p) {
		for (int i = 0; i < v; i++) {
			for ( int j = 0; j < v; j++) {
				matrizC[i] [j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for  (int k = 0; k < p; k++) {
					matrizC[i] [j] += matrizA[i] [k] * matrizB[k] [j];
				}
			}
		}
		imprimirMatriz(matrizC, m, n);
	}
	return 0;
}
	
		 

void lerMatriz(int *m, int *n, int matriz[v] [v]) {
	scanf("%d %d", m, n);
	printf("Digite os valores da matriz\n");
	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *n; j++) {
			scanf("%d", &matriz[i] [j]);
		}
	}
}
void imprimirMatriz(int matrizC[v] [v], int m, int n) {
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", matrizC[i] [j]);
		}
	printf("\n");
	}
}










