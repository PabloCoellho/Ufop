#include <stdio.h>

int main(){
	float a, b, r;
	char sinal;
	printf("Digite a operação: \n");
	scanf("%c", &sinal);
	printf("Digite os dois números: \n");
	scanf("%f %f", &a, &b);

	switch (sinal) {

		case '+':
			r = a + b;
			printf("%.4f\n", r);
			break;
		case '-':
			r = a - b;
			printf("%.4f\n", r);
			break;
		case '*':
			r = a * b;
			printf("%.4f\n", r);
			break;
		case '/':
			r = a / b;
			printf("%.4f\n", r);
			break;
		default:
			printf("sinal impróprio\n");
	}
	return 0;
}
			
