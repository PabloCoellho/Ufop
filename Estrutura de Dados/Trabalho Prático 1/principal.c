#include "corretor.h"
#include <stdio.h>

int main() {
	int n, s, p;
	TADsub *S;

	lerqtd(&n);
	S = alocartad(S, n);
	lersubs(S, n);
	julgamento(S, n, &s, &p);
	imprimirresul(s, p);
	S = desalocartad(S);

	return 0;
}