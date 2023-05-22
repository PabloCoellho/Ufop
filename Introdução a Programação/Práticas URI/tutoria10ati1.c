#include <stdio.h>

int main() {
	char c;
	FILE *arquivo = fopen("arq.txt", "w");
	printf("Digite no arquivo, tecle 0 para sair\n");
	do {
		scanf("%c", &c);
		if(c != '0')
			fprintf(arquivo, "%c", c);
	} while (c != '0');
	fclose(arquivo);

	FILE *entrada = fopen("arq.txt", "r");
	printf("Impressão do arquivo\n");
	do {
		fscanf(arquivo, "%c", &c);
		printf("%c", c);
	} while (!feof(arquivo));
	fclose(entrada);
	return 0;
}