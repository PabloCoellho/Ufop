#include <stdio.h>

int main() {
	int alunos;
	float menor, maior;
	float media, notas, x;
	notas = 0;
	alunos = 0;
	x = 1;
	maior = 0;
	menor = 99999;
		
	while (x >= 0) {
		printf("DIGITE UMA NOTA (ou uma nota negativa para sair): ");
		scanf("%f", &x);
		if (x >= 0) {
			notas = x + notas;
			media += media;
			alunos++;
			if (x > maior)
				maior = x;	
			if (x < menor )
				menor = x;
		}
	}	
    media = notas / alunos;
	printf("\nA MÉDIA DAS %d NOTAS É: %.2f\n", alunos, media);
	printf("A MAIOR NOTA É: %.1f\n", maior);
	printf("A MENOR NOTA É: %.1f\n", menor);
	return 0;
}
