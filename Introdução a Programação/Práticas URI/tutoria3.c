#include <stdio.h>

int main() {
	int a, b, c;
	printf("Digite dois valores inteiros\n");
	scanf("%d %d", &a, &b);
	if (a == b) {
		c = a + b;
		printf("C = %d\n", c);}
	else {
		c = a * b;
		printf("C = %d\n", c);}
	return 0;
}
