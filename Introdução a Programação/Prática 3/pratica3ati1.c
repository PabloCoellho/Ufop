#include <stdio.h>
#include <math.h>

int main() {
	float peso, altura, IMC;
	printf("Digite o peso e a altura de um adulto\n");
	scanf("%f %f", &peso, &altura);
	IMC = peso / pow(altura, 2);
	if (IMC < 18.5)
		printf("Abaixo do peso\n");
	else if (IMC >= 18.5 && IMC < 25)
		printf("Peso normal\n");
	else if (IMC >= 25 && IMC < 30)
		printf("Acima do peso\n");
	else
		printf("Obeso\n");
	return 0;
}
