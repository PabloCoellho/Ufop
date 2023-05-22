#include <stdio.h>
#include <string.h>

#define s 50

void verifica(char frase[s]) {
	int tam = strlen(frase) - 1;
	for (int i = 0; i < tam; i++) {
		if (frase[i] != 'a' && frase[i] != 'e' && frase[i] != 'i' && frase[i] != 'o' && frase[i] != 'u' && frase[i] != ' ') 
		printf("%d ", i);
	}
}

int main() {
	char frase[s];
	printf("Digite a frase:\n\n");
	fgets(frase, 50, stdin);
	verifica(frase);
	printf("\n");
	return 0;
}
