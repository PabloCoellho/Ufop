#include "corretor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sub {
	char iden;
	int tempo;
	char palavra[15];
};

void lerqtd(int *n) {
	scanf("%d", n);
}

TADsub *alocartad(TADsub *S, int n) {
	S = (TADsub *) malloc (n * sizeof (TADsub));
	return S;
}

void lersubs (TADsub *S, int n) {
	for (int i = 0; i < n; i++) {
		scanf(" %c ", &S[i].iden);
		scanf("%d", &S[i].tempo);
		scanf("%s", S[i].palavra);
	}	
}

void julgamento(TADsub *S, int n, int *s, int *p) {
	*s = 0, *p = 0;
	int i;
	char *a;
	a = (char *) malloc (n * sizeof(char));
	
	for (i = 0; i < n; i++) {
		if (strcmp(S[i].palavra, "correto") == 0) {
			int c = 0;
			*s += 1;
			for (int j = 0; j <= i; j++) {
				if (S[i].iden == a[j]) 
					c++;
			}
			
			*p += S[i].tempo + c * 20;
		}
			
		else 
			a[i] = S[i].iden;
	}
	free(a);
}

void imprimirresul (int s, int p) {
	printf("%d %d\n", s, p);
}

TADsub *desalocartad (TADsub *S) {
	free(S);
	return S;
}
