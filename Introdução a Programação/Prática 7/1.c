#include <stdio.h>


struct Racional {
	int numerador;
	int denominador;
};

int equal (struct Racional *r1, struct Racional *r2);

int main() {
	struct Racional r1, r2;
	printf("Digite numerador e denominador de r1: ");
	scanf("%d %d", &r1.numerador, &r1.denominador);
	printf("Digite numerador e denominador de r2: ");
	scanf("%d %d", &r2.numerador, &r2.denominador);
	if (equal(&r1, &r2) == 1)
		printf("\nr1 e r2 são iguais!\n");
	else
		printf("\nr1 e r2 são diferentes!\n");
	return 0;
}

int equal (struct Racional *r1, struct Racional *r2) {
	int a, b, resto, mmc1, mmc2;
	a = r1->numerador;
	b = r1->denominador;
	do {
		resto = a % b;
		a = b;
		b = resto;
	}while (resto != 0);
	mmc1 = a;
	for (int i = 0; i < mmc1; i++) {
		if (r1->numerador % mmc1 == 0)
			r1->numerador /= mmc1;
		if(r1->denominador % mmc1 == 0)
			r1->denominador /= mmc1;
	}
	a = r2->numerador;
	b = r2->denominador;
	do {
		resto = a % b;
		a = b;
		b = resto;
	}while (resto != 0);
	mmc2 = a;
	for (int i = 0; i < mmc1; i++) {
		if (r2->numerador % mmc1 == 0)
			r2->numerador /= mmc2;
		if(r2->denominador % mmc2 == 0)
			r2->denominador /= mmc2;
	}
	if ((r1->numerador == r2->numerador) && (r1->denominador == r2->denominador))
		return 1;
	else
		return 0;
}