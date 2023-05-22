#include <stdio.h>

#define v 100

int main() {
	int n, x, vetor[v], cont = 0;
	printf("Digite o numero de X\n");
	scanf("%d", &x);
	FILE *arquivo = fopen("arq.dat", "rb");
	fread(&n, sizeof(int), 1, arquivo);
	for (int i = 0; i < n; i++) { 
		fread(&vetor[i], sizeof(int), 1, arquivo);
		if (vetor[i] == x)
			cont++;
	}
	printf("O numero %d aparece %d vez(es)\n", x, cont);
	fclose(arquivo);
	return 0;
}