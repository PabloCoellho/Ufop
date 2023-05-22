#include <stdio.h>

int ehPrimo(int n);

int ehPrimo(int n) {
	int i;	
	i = 2;
	if (n == 1)
		return 0;
	while (i < n) {
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int main() {
	int n;
	printf("Digite um número: ");
	scanf("%d", &n);
	if (ehPrimo(n) == 1)
		printf("\n%d é um número primo!\n", n);
	else	
		printf("\n%d NÃO é um número primo!\n", n);
	return 0;
}
