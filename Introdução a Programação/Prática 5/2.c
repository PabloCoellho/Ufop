#include <stdio.h>

void temp(double vetor[30]);

int main() {
	double vetor[30];
	printf("Digite a temperatura de 30 dias\n");
	for (int i = 0; i < 30; i++)
		scanf("%lf", &vetor[i]);
	temp(vetor);
	return 0;
}

void temp(double vetor[30]) {
	int abaixo = 0, acima = 0, soma = 0;
	double media;
	for (int i = 0; i < 30; i++) 
		soma += vetor[i];
	media = soma / 30.0;
	for (int i = 0; i < 30; i++) {
		if (media > vetor[i])
			abaixo++;
		if (media < vetor[i])
			acima++; }
	printf("%d dias tiveram a temperatura abaixo da média\n", abaixo);
	printf("%d dias tiveram a temperatura acima da média\n", acima);
}
		

	
