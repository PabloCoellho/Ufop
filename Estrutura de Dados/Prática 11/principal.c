#include "arvore.h"
#include <stdio.h>

int main ()
{
	int n, no;
	TItem x;
	TArvore *arvore;

	//ler n
	scanf("%d", &n);
	
	TArvore_Inicia(arvore);
	
	//ler o primeiro no e criar a raiz da arvore
	scanf("%d", &no);
	x.chave = no;
	TArvore_Insere_Raiz(arvore, x);
	
	for(int i = 1; i<n; i++) {
		//ler o no
		scanf("%d", &no);
		x.chave = no;
		//inserir na arvore
		TArvore_Insere(arvore, x);
	}


	//gerar percurso em ordem prefixa
	printf("PREFIXA: ");
	Prefixa(*arvore);

	//gerar percurso em ordem infixa
	printf("\nINFIXA: ");
	Infixa(*arvore);

	//gerar percurso em ordem posfixa
	printf("\nPOSFIXA: ");
	Posfixa(*arvore);
	printf("\n");

	return 0;
}
