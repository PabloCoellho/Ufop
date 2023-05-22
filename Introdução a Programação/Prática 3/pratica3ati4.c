#include <stdio.h>

int main() {
	char conceito;
	printf("Digite o conceito\n");
	scanf("%c", &conceito);
	switch (conceito) {
		case 'A':
			printf("Excelente\n");
			break;
		case 'B':
			printf("Ótimo\n");
			break;
		case 'C':
			printf("Bom\n");
			break;
		case 'D':
			printf("Regular\n");
			break;
		case 'E':
			printf("Ruim\n");
			break;
		case 'F':
			printf("Nos vemos de novo ano que vem...\n");
			break;
		default:
			printf("Erro: conceito inexistente\n");
	}
	return 0;
}
