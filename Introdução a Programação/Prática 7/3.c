#include <stdio.h>

#define v 100

typedef struct {
	char nome[v];
	int nota;
	int frequencia;
} Aluno;

int main() {
	float n;
	Aluno x [v];
	FILE *arquivo = fopen("alunos.txt", "w");
	printf("Quantos alunos deseja incluir? ");
	scanf("%f", &n);
	fprintf(arquivo, "%f\n", n);
	for (int i = 0; i < n; i++) {
		printf("Digite o nome do aluno %d: ", i+1);
		scanf("%s", x[i].nome);
		fprintf(arquivo, "%s\n", x[i].nome);
		printf("Digite a nota do aluno %d: ", i+1);
		scanf("%d", &x[i].nota);
		fprintf(arquivo, "%d\n", x[i].nota);
		printf("Digite a frequência percentual do aluno %d: ", i+1);
		scanf("%d", &x[i].frequencia);
		fprintf(arquivo, "%d\n", x[i].frequencia);
	}
	fclose(arquivo);
	return 0;
}