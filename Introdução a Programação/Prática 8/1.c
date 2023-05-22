#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	float *nota1, *nota2, *media;
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &n);
	nota1 = malloc (n * sizeof(float));
	nota2 = malloc (n * sizeof(float));
	media = malloc (n * sizeof(float));
	for (int i = 0; i < n; i++) {
		printf("Digite as notas do aluno %d\n", i+1);
		scanf("%f", &nota1[i]);
		scanf("%f", &nota2[i]);
	}
	for (int i = 0; i < n; i++) {
		float soma = 0;
		soma = (nota1[i] * 4) + (nota2[i] * 6);
		media[i] = soma/10;
	}
	printf("\nv1 = {");
	for (int i = 0; i < n-1; i++) 
		printf("%.1lf, ",nota1[i]);
	printf("%.1lf} e \n", nota1[n-1]);

	printf("v2 = {");
	for (int i = 0; i < n-1; i++) 
		printf("%.1lf, ",nota2[i]);
	printf("%.1lf}, o vetor resultante será \n\n", nota2[n-1]);
	
	printf("v3 = {");
	for (int i = 0; i < n-1; i++) 
		printf("%.1lf, ",media[i]);
	printf("%.1lf}.\n", media[n-1]);
	
	free(nota1);
	free(nota2);
	free(media);
	return 0;
}