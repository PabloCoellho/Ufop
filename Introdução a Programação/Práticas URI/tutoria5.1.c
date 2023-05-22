#include <stdio.h>

int main() {
	int i, n, r;
	printf("Digite o valor de N\n");
	scanf("%d", &n);
	i = 0;
	r = 1;
		
	while (i < n) {
		r *= (n - i);
		i++;
	}
	printf("%d\n", r);
	return 0;
}
