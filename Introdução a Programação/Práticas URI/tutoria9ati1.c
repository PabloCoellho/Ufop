#include <stdio.h>
#include <string.h>

#define s 50

typedef struct {
	char nome[s], disciplina[s];
	int matricula;
	float nota[3], media;
} Aluno;

void ler(Aluno *x){
	fgets(x->nome, 50, stdin);
	scanf("%d", &x->matricula);
	getchar();
	fgets(x->disciplina, 50, stdin);
	for (int i = 0; i < 3; i++){
		scanf("%f", &x->nota[i]);
	}
}

void calcularMedia (Aluno *x) {
	float soma = 0;
	for(int i = 0; i < 3; i++) {
		soma += x->nota[i];
	}
	x->media = soma/3.0;
}

void imprimir(Aluno x) {
	x.nome[strlen(x.nome) - 1] =  '\0';
	x.disciplina[strlen(x.disciplina) - 1] = '\0';
	printf("A média de %s na disciplina %s foi %.1f\n", x.nome, x.disciplina, x.media);
	
}

void editar(Aluno *x) {
	printf("Edite as notas do aluno\n");
	for (int i = 0; i < 3; i++){
		scanf("%f", &x->nota[i]);
	}
}
int main() {
	int n;
	Aluno x;
	ler(&x);
	calcularMedia(&x);
	imprimir(x);
	printf("\nSe quiser editar as notas digite 1, se não 0\n");
	scanf("%d", &n);
	if (n == 1)
		editar(&x);
	return 0;
}