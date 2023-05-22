#include <stdio.h>

int main() {
	int codigo;
	float salario, nsalario, dsalario;
	printf("Digite o salario atual e o codigo do cargo\n");
	scanf("%f %d", &salario, &codigo);
	switch (codigo) {
		case 100:
			nsalario = salario + (salario * 0.03);
			dsalario = nsalario - salario;
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario);
			printf("Diferença entre os salarios = R$%f\n", dsalario);
			break;
		case 101:
			nsalario = salario + (salario * 0.05);
			dsalario = nsalario - salario;
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario);
			printf("Diferença entre os salarios = R$%f\n", dsalario);
			break;
		case 102:
			nsalario = salario + (salario * 0.075);
			dsalario = nsalario - salario;
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario);
			printf("Diferença entre os salarios = R$%f\n", dsalario);
			break;
		case 201:
			nsalario = salario + (salario * 0.1);
			dsalario = nsalario - salario;
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario);
			printf("Diferença entre os salarios = R$%f\n", dsalario);
			break;
		default:
			nsalario = salario + (salario * 0.15);
			dsalario = nsalario - salario;
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario);
			printf("Diferença entre os salarios = R$%f\n", dsalario);
	}
	return 0;
}
