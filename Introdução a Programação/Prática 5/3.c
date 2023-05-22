#define b 501
#define a 100000

#include <stdio.h>
#include <stdlib.h>

void imprimir(int vetorCont[b], int n);

int main() {
	int na, n, vetorCont[b], vetorA[a];
	printf("Digite um número inteiro <= 500\n");
	scanf("%d", &n);
	for (int i = 1; i < b; i++)
		vetorCont[i] = 0;
	if (n <= 500) {
	for (int i = 0; i < a; i++) {
		na = 1 + rand() % n;
		vetorA[i] = na; 
	}
	for (int i = 0; i < a; i++)
		vetorCont[vetorA[i]]++;
	}
	imprimir(vetorCont, n);	
	return 0;
}
	 

void imprimir(int vetorCont[b], int n) {
	for (int i = 1; i <= n; i++)
		printf("%d\n", vetorCont[i]);
}





