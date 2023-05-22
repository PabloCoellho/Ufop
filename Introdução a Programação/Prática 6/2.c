#include <stdio.h>
#include <string.h>

#define v 50

int main () {
	int tam;
	char palavra[v], comparar[v];
	printf("Digite uma palavra ou FIM para sair: ");
	scanf("%s", palavra);
	while (strcmp(palavra, "FIM") != 0) {
		tam = strlen(palavra);
		strcpy(comparar, palavra);
		for (int i = 0; i < tam; i++) {
       		comparar[i] = palavra[(tam - 1) - i];
		}
		if (strcmp(palavra, comparar) == 0)
			printf("%s é um palíndromo\n", palavra);
		else
			printf("%s não é um palíndromo\n", palavra);
		printf("\nDigite uma palavra ou FIM para sair: ");
		scanf("%s", palavra);
	}
	return 0;
}
