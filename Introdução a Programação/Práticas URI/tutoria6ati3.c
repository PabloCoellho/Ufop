#include <stdio.h>

int main() {
	int n, x, y;
	y = 1;
	x = 1;
	printf("Digite o valor de n\n");
	scanf("%d", &n);
	if (n > 0) {
		while (x <= n) {
			while (y <= n) {
				printf("(%d, %d)\n", x, y);
				y++; 
			}
			x++; 
			y = 1;
		}
	}
	return 0;
}
