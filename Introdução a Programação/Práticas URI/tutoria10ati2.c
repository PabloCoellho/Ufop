#include <stdio.h>

int main() {
	int n, vetor[100];
	FILE *arquivo = fopen("arq.dat", "wr");
	printf("Digite o tamanho do vetor e seus respectivos valores\n");
	scanf("%d", &n);
	fwrite(&n, sizeof(int), 1, arquivo);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
		fwrite(&vetor[i], sizeof(int), 1, arquivo);
	}
	fclose(arquivo);
	return 0;
}
