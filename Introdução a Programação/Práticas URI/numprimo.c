#include <stdio.h>

int primo(int n) {
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
	printf("Digite um número\n");
	scanf("%d", &n);
	if (primo(n) == 1)
		printf("É primo\n");
	else	
		printf("Não é primo\n");
	return 0;
}
