#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	int preco;
} Carro;

void aloca(Carro ***x, int n, int m) {
	(*x) = malloc(n * sizeof(Carro*));
	for (int i = 0; i < n; i++) 
		(*x)[i] = malloc(m * sizeof(Carro));
}

void desaloca(Carro **x, int n) {
	for (int i = 0; i < n; i++)
		free(x[i]);
	free(x);
}

int main() {
	Carro **x;
	int m, n;
	FILE *arquivo = fopen ("carros.txt", "w");
	printf("Digite o tamanho da matriz: ");
	scanf("%d %d", &n, &m);
	fprintf(arquivo, "%d ", n);
	fprintf(arquivo, "%d ", m);
	aloca(&x, n, m);
	printf("Digite os valores da matriz: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", x[i] [j].nome);
			scanf("%d", &x[i] [j].preco);
		}
	}
	for (int i = 0; i < n; i++) {
		fprintf(arquivo, "\n");
		for (int j = 0; j < m; j++) {
			fprintf(arquivo, "%s ", x[i] [j].nome);
			fprintf(arquivo, "%d ", x[i] [j].preco);
		}
	}
	desaloca(x, n);
	return 0;
}