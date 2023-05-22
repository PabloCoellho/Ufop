#include "matriz.h"
#include <stdio.h>

void lerOperacao(char *operacao){
	scanf("%c", operacao);
}

void lerMatriz(double M[][12]){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++)
			scanf("%lf", &M[i][j]);
	}
}

double somaMatriz(double M[][12]){
	double soma, soma1, soma2, soma3, soma4, soma5;
	for (int i = 1; i < 11; i++)
   		soma1 += M[0][i];
   	for (int i = 2; i < 10; i++)
   		soma2 += M[1][i];
  	for (int i = 3; i < 9; i++)
   		soma3 += M[2][i];
   	for (int i = 4; i < 8; i++)
   		soma4 += M[3][i];
   	for (int i = 5; i < 7; i++)
   		soma5 += M[4][i];
   	soma = soma1 + soma2 + soma3 + soma4 + soma5;
   	return soma;
}

double media(double resultado){
	double media;
	media = resultado / 30.0;
	return media;
}

void printResultado(double resultado){
	printf("%.1lf\n", resultado);
}
