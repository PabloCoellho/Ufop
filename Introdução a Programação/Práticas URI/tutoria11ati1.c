#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	int matricula;
	float **matriz;
} Aluno;

void alocarMatriz(Aluno *x, int l, float c) {
	x->matriz = malloc(l * sizeof(float*));
	for (int i = 0; i < l; i++) {
		x->matriz[i] = malloc (c * sizeof(float));
	}
	
}

void media(Aluno *x, int l, float c) {
	float soma, media;
	for(int i = 0; i < l; i++) {
		soma = 0, media = 0;
		for (int j = 0; j < c; j++) {
			soma += x->matriz[i] [j];
		}
		media = soma / c;
		printf("Media da disciplina %d = %.2f\n", i+1, media);
		if (media < 6.0)
			printf("O aluno foi reprovado na disciplina %d\n", i+1);
		else
			printf("O aluno foi aprovado na disciplina %d\n", i+1);
	}
}

void desalocaMatriz(Aluno *x, int l) {
	for (int i = 0; i < l; i++) {
		free(x->matriz[i]);
	}
	free(x->matriz);
}

int main() {
	Aluno x;
	int l;
	float c;
	char disciplina[50];
	printf("Digite a quantidade de disciplinas e provas: ");
	scanf("%d %f", &l, &c);
	alocarMatriz(&x, l, c);
	printf("Digite o nome do aluno: ");
	scanf("%s", x.nome);
	printf("Digite a matricula de %s: ", x.nome);
	scanf("%d", &x.matricula);
		for(int i = 0; i < l; i++) {
		printf("Digite a disciplina %d e as respectivas notas:\n", i+1);
		scanf("%s", disciplina);
		for (int j = 0; j < c; j++) {
			scanf("%f", &x.matriz[i] [j]);
		}
	}
	media(&x, l, c);
	desalocaMatriz(&x, l);
	return 0;
}