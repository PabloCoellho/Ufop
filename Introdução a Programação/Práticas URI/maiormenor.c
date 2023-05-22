#include <stdio.h>

#define v 10000

int main() {
	int n, vetor[v];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}
	for (int i = 1; i < n; i++) {
		if (vetor[i] < vetor[i - 1]) {
			printf("%d\n", i + 1);	
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
	
