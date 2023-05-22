#include <stdio.h>

#define v 50

void imprimir(int matriz [v] [v], int n, int m);

int main() {
	int matriz[v] [v], m, n;
	printf("Digite os valores de N e M: ");
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &matriz[i] [j]);
		}
	}	
	imprimir(matriz, n, m);
	return 0;
}

void imprimir(int matriz [v] [v], int n, int m){
	for (int i = 0; i < m; i++) {	
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", matriz[j] [i]);
		}
	}
	printf("\n");
}
