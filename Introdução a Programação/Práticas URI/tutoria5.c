#include <stdio.h>

int main() {
	int i, x, soma;
	printf("Digite o valor de x\n");
	x = -1;
	i = 1;
	
	while (x != 0) {
		soma = 0;
		scanf("%d", &x);
		if (x == 0)
			return 0;
		if (x % 2 == 0) {	
			while (i < 6) {
				soma += x;
				printf("%d\n", soma);	
				x += 2;
				i++;
			}
		}
		else {
			x += 1;
			while (i < 6) {
				soma += x;
				printf("%d\n", soma);	
				x += 2;
				i++;
			}
		}
		printf("%d\n", soma);	
	}
	
	return 0;
}
