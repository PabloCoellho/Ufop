#include <stdio.h>

int main() {
	int n, x, vetor[50];
	printf("Digite o valor de N: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vetor[i]);
	}
	printf("Digite o valor de X: ");
	scanf("%d", &x);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((vetor[i] + vetor[j] == x) && (i != j)) {
			printf("%d %d\n", vetor[i], vetor[j]);
			return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
