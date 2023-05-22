/*Nome: Pablo Martins Coelho
*Matrícula: 20.1.4113
*Turma: BCC201_T42
*/

#include <stdio.h>

int main() {
	int codigo;
	float salario, nsalario1, nsalario2, nsalario3, nsalario4, nsalario5;
    float dsalario1, dsalario2, dsalario3, dsalario4, dsalario5;
	printf("Digite o salario atual e o codigo do cargo\n");
	scanf("%f %d", &salario, &codigo);
	nsalario1 = salario + (salario * 0.03);
	dsalario1 = nsalario1 - salario;
	nsalario2 = salario + (salario * 0.05);
	dsalario2 = nsalario2 - salario;
	nsalario3 = salario + (salario * 0.075);
	dsalario3 = nsalario3 - salario;
	nsalario4 = salario + (salario * 0.1);
	dsalario4 = nsalario4 - salario;
	nsalario5 = salario + (salario * 0.15);
	dsalario5 = nsalario5 - salario;

	switch (codigo) {

		case 100:
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario1);
			printf("Diferença entre os salarios = R$%f\n", dsalario1);
			break;
		case 101:
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario2);
			printf("Diferença entre os salarios = R$%f\n", dsalario2);
			break;
		case 102:
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario3);
			printf("Diferença entre os salarios = R$%f\n", dsalario3);
			break;
		case 201:
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario4);
			printf("Diferença entre os salarios = R$%f\n", dsalario4);
			break;
		default:
			printf("salario antigo = R$%f\n", salario);
			printf("novo salario = R$%f\n", nsalario5);
			printf("Diferença entre os salarios = R$%f\n", dsalario5);
	}
	return 0;
}
