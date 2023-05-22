#include <stdio.h>

int main() {
	int vetor[10];
	vetor[0] = 1;
	vetor[1] = 1;
	printf("O número  1 da série de Fibonacci eh: %d\n", vetor[0]);
	printf("O número  2 da série de Fibonacci eh: %d\n", vetor[1]);
	for (int i = 2; i < 10; i++) {
		vetor[i] = vetor[i - 2] + vetor[i - 1];
		printf("O número %2d da série de Fibonacci eh: %d\n", i + 1, vetor [i]); 
	}
	return 0;
}

