#define v 15

#include <stdio.h>

int main() {
	float vetor1[v], vetor2[v];
	for (int i = 0; i < v; i++) {
		printf("Digite as notas das duas provas do aluno %d\n", i + 1);
		scanf("%f", &vetor1[i]);
		scanf("%f", &vetor2[i]);
	}
	for (int i = 0; i < v; i++) {
		if ((vetor1[i] + vetor2[i]) / 2 >= 60)
			printf("O aluno %2d está APROVADO\n", i + 1);
		else
			printf("O aluno %2d está REPROVADO\n", i + 1);
	}
	return 0;
}





