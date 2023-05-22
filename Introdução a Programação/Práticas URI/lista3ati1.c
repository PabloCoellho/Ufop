#include <stdio.h>

void Troca(int *pa, int *pb, int *pc);

void Troca(int *pa, int *pb, int *pc) {	
 	int aux;
	aux = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = aux;
}

int main() {
	int a, b, c;
	printf("Digite o valor de A:\n");
	scanf("%d", &a);
	printf("Digite o valor de B:\n");
	scanf("%d", &b);
	printf("Digite o valor de C:\n");
	scanf("%d", &c);
	Troca(&a, &b, &c);
	printf("A = %d\nB = %d\nC = %d\n", a, b, c);
	return 0;
}
