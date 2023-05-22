#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

double fibonacci(int i, TADfib *f){
//preencher o algoritmo recursivo
	f->chamadas++;
	if (i == 0) {
		return 0;
	}
	else if (i == 1) {
		return 1;
	}
	else {
		return fibonacci(i-1, f) + fibonacci(i-2, f);
	}
}
