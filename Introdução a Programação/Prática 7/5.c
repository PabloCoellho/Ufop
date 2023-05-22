#include <stdio.h>
#include <string.h>

#define v 100

typedef struct {
	char nome[v];
	int nota;
	int frequencia;
} Aluno;

void Calmedia(Aluno x[v], float n, float *media);

void frequencia(Aluno x[v], float n);

void aprovacao(Aluno x[v], float n);

void nomes(Aluno x[v], float n, float *media);

int main() {
	int tam;
	float n, media;
	char abrir[50];
	Aluno x[v];
	printf("Digite o nome do arquivo texto: ");
	scanf("%s", abrir);
	FILE *arquivot = fopen(abrir, "r");
	fscanf(arquivot, "%f", &n);
	for (int i = 0; i < n; i++) {
		fscanf(arquivot, "%s", x[i].nome);
		fscanf(arquivot, "%d", &x[i].nota);
		fscanf(arquivot, "%d", &x[i].frequencia);
	}
	tam = strlen(abrir);
	abrir[tam-3] = 'd';
	abrir[tam-2] = 'a';
	abrir[tam-1] = 't';
	FILE *arquivob = fopen(abrir, "rb");
	fread(&n, sizeof(float), 1, arquivob);
	for (int i = 0; i < n; i++) {
		fread(x[i].nome, sizeof(char), 100, arquivob);
		fread(&x[i].nota, sizeof(int), 1, arquivob);
		fread(&x[i].frequencia, sizeof(int),1, arquivob);
	}
	printf("Aquivo %s criado com sucesso!\n", abrir);
	printf("\n");
	Calmedia(x, n, &media);
	frequencia(x, n);
	aprovacao(x, n);
	nomes(x, n, &media);
	fclose(arquivot);
	fclose(arquivob);
	return 0;
}
void Calmedia(Aluno x[v], float n, float *media) {
	float soma = 0;
	for (int i = 0; i < n; i++) {
		soma += x[i].nota;
	}
	*media = soma / n;
	printf("Nota média: %.1f\n", *media);
}
void frequencia(Aluno x[v], float n) {
	float freq, soma = 0;
	for (int i = 0; i < n; i++) {
		soma += x[i].frequencia;
	}
	freq = soma / n;
	printf("Frequência média: %.0f%%\n", freq);
}
void aprovacao(Aluno x[v], float n) {
	float aprov, cont = 0;

	for (int i = 0; i < n; i++) {
		if (x[i].nota >= 6)
			cont++;
	}
	aprov = (cont / n) * 100;
	printf("Percentual de aprovação: %.0f%%\n\n", aprov);
}
void nomes(Aluno x[v], float n, float *media) {
	printf("Nome dos alunos com nota acima da nota média:\n");
	for (int i = 0; i < n; i++) {
		if (x[i].nota > *media)
			printf("%s\n", x[i].nome);
	}
}