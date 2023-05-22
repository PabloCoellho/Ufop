#include <stdio.h>
#include <math.h>

int main() {
	double soma, s, pi, sinal;
	int nrotermos, i, o;
	soma = 0;
	i = 1;
	o = 3;
	sinal = 1;
	printf("Digite o número de termos\n");	
	scanf("%d", &nrotermos);

	do {
		soma += sinal * (1/(pow(o, 3)));	
		o += 2;
		sinal *= -1;
		i++;
		} while (i <= nrotermos);
	s = 1 - soma;
	pi = cbrt (s * 32);
	printf("O valor de pi é: %lf\n", pi);
	return 0;
}
	

