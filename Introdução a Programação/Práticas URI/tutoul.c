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
	char abrir[50];
	int n, m, maior = 0, a, b;
	printf("Digite o nome do arquivo: ");
	scanf("%s", abrir);
	FILE *arquivo = fopen (abrir, "r");
	fscanf(arquivo, "%d %d", &n, &m);
	aloca(&x, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(arquivo, "%s", x[i] [j].nome);
			fscanf(arquivo, "%d", &x[i] [j].preco);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maior < x[i] [j].preco) {
				maior = x[i] [j].preco;
				a = i;
				b = j;
			}
		}
	}
	printf("%s e o carro de maior valor.\n", x[a] [b].nome);
	desaloca(x, n);
	return 0;
}