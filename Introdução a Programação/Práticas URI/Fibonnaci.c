#include <stdio.h>

#define v 61

int main() {
	long long int vetor[v] = {0, 1};
	int n, t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 2; j <= n; j++) {
			vetor[j] = vetor[j - 2] + vetor[j - 1];
		}
		printf("Fib(%d) = %lld\n", n, vetor[n]);
	}
	return 0;
}
		
