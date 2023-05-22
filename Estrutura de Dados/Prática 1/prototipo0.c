#include <stdio.h>
int main()
{
   	double M[12][12];//utilize esta matriz para ler os 144 numeros reais
   	char c;
   	double soma, media, soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0, soma5 = 0;
    scanf("%c", &c);
   	for (int i = 0; i < 12; i++) {
   		for (int j = 0; j < 12; j++)
   			scanf("%lf", &M[i][j]);
   	}
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
   	switch (c) {
   		case 'S':	
   			printf("%.1lf\n", soma);
   			break;
   		case 'M':
   			media = soma / 30.0;
   			printf("%.1lf\n", media);
   			break;
   	}
    return 0;//não remova
}
