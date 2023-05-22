#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	printf("Digite os valores dos lados do triangulo\n");
	scanf("%d %d %d", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
		printf("Respeita a restricao\n");
	else
		printf("Nao respeita a restricao\n");
	return 0;
}
