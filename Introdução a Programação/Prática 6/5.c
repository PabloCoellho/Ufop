#include <stdio.h>
#include <string.h>

#define s 100

void strmaius(char frase[s]);

int main() {
	char frase[s];
	printf("Digite o texto: \n");
	fgets(frase, 100, stdin);
	strmaius(frase);
	printf("%s\n", frase);	
	return 0;
}

void strmaius(char frase[s]) {
	int tam;
	tam = strlen(frase);
	for (int i = 0; i < tam; i++) {
		if (frase[i] > 96)
			frase[i] = frase[i] - 32;
	}	
}

















	
