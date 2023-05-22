#include <stdio.h>
#include <math.h>

typedef struct {
	double real;
	double imaginario;
} Complexo;

Complexo somaComplexo(Complexo x, Complexo y);

Complexo subComplexo(Complexo x, Complexo y);

Complexo multComplexo(Complexo x, Complexo y);

int main() {
	printf("Calculadora de números complexos!\n\n");
	Complexo x, y, soma, sub, mult;
	char op;
	printf("Digite os valores de a e b (x = a + bi): ");
	scanf("%lf %lf", &x.real, &x.imaginario);
	printf("Digite os valores de c e d (y = c + di): ");
	scanf("%lf %lf", &y.real, &y.imaginario);
	printf("Digite a operação (+, - ou *): ");
	getchar();
	scanf("%c", &op);
	switch (op) {
		case '+':
			soma = somaComplexo(x, y);
			if (soma.imaginario < 0)
				printf("%.0f %.0fi\n", soma.real, soma.imaginario);
			if (soma.imaginario == 0)
				printf("\nResultado: %.0f\n", soma.real);
			else if (soma.imaginario == 1)
				printf("\nResultado: %.0f + i\n", soma.real);
			else if (soma.imaginario > 1)
				printf("\nResultado: %.0f + %.0fi\n", soma.real, soma.imaginario);
			break;
		case '-':
			sub = subComplexo(x, y);
			if (sub.imaginario < 0)
				printf("%.0f %.0fi\n", sub.real, sub.imaginario);
			if (sub.imaginario == 0)
				printf("\nResultado: %.0f\n", sub.real);
			else if (sub.imaginario == 1)
				printf("\nResultado: %.0f + i\n", sub.real);
			else if (sub.imaginario > 1)
				printf("\nResultado: %.0f + %.0fi\n", sub.real, sub.imaginario);
			break;
		case '*':
			mult = multComplexo(x, y);
			if (mult.imaginario < 0)
				printf("%.0f %.0fi\n", mult.real, mult.imaginario);
			if (mult.imaginario == 0)
				printf("\nResultado: %.0f\n", mult.real);
			else if (mult.imaginario == 1)
				printf("\nResultado: %.0f + i\n", mult.real);
			else if (mult.imaginario > 1)
				printf("\nResultado: %.0f + %.0fi\n", mult.real, mult.imaginario);
			break;
		default:
			printf("ERRO: Operação inválida\n");
	}
	return 0;
}

Complexo somaComplexo(Complexo x, Complexo y) {
	Complexo soma;
	soma.real = x.real + y.real;
	soma.imaginario = x.imaginario + y.imaginario;
	return soma;
}

Complexo subComplexo(Complexo x, Complexo y) {
	Complexo sub;
	sub.real = x.real - y.real; 
	sub.imaginario = x.imaginario - y.imaginario;
	return sub;
}

Complexo multComplexo(Complexo x, Complexo y) {
	Complexo mult;
	mult.real = (x.real * y.real) - (x.imaginario * y.imaginario);
	mult.imaginario = (x.real * y.imaginario) + (x.imaginario * y.real);
	return mult;
}