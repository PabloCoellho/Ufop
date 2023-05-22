#include <stdio.h>

int main() {
	int idade;
	printf("Digite a idade\n");
	scanf("%d", &idade);
	if (idade <= 10)
		printf("R$90,00\n");
	else if (idade > 10 && idade <= 29)
		printf("R$170,00\n");
	else if (idade > 29 && idade <= 45)
		printf("R$290,00\n");
	else if (idade > 45 && idade <= 59)
		printf("R$400,00\n");
	else if (idade > 59 && idade <= 65)
		printf("R$515,00\n");
	else
		printf("R$695,00\n");
	return 0;
}
