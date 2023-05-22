#include <stdio.h>

int main() {
	int linha, coluna, verif, x, y, dx, dy;
	verif = 0;
	linha = 1;
	coluna = 1;

	while (!verif) {
		printf("Movimentos de um Bispo no xadrex!\n");
		printf("Digite a linha em que o Bispo se encontra: ");
		scanf("%d", &x);
		printf("Digite a coluna em que o Bispo se encontra: ");
		scanf("%d", &y);
		if (x < 1 || x > 8 || y < 1 || y > 8) 
			printf("\nPosições inválidas.\n");
		else 
			 verif = 1;
	}
	
	dx = x + y;
	dy = x - y;

	printf("\nMovimentos possíveis: \n\n");
	printf("     1  2  3  4  5  6  7  8 \n");
	printf("   -------------------------\n");
	
	while (8 >= linha) {
		printf("%d |", linha);
		while (8 >= coluna) {
			if (dx == linha + coluna || dy == linha - coluna)
				printf("  X");
			else 
				printf("  -");
			coluna++;
		}
		printf("\n");
		linha++;
		coluna = 1;
	}
	return 0;
}
