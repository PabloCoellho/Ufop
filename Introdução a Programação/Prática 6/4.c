#include <stdio.h>
#include <string.h>

#define s 100

int main() {
	int tam;
	char frase[s];
	printf("Digite o texto para censurar: \n");
	fgets(frase, 100, stdin);
	tam = strlen(frase);
	for (int i = 0; i < tam; i++) {
		if (frase[i] == 'a')
			frase[i] = '@';
		else if (frase[i] == 'e')
			frase[i] = '_';
		else if (frase[i] == 'i')
			frase[i] = '|';
		else if (frase[i] == 'o')
			frase[i] = '0';
		else if (frase[i] == 'u')
			frase[i] = '#';
		else if (frase[i] == 's')
			frase[i] = '$';
	}
	printf("\n%s", frase);
	return 0;
}
