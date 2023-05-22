
#include <stdio.h>
#include <string.h>

#define s 70

int main() {
	int t, tamtotal = 0, pos = 0, tam3;
	char nome[s];
	printf("Digite o nome completo: ");
	fgets(nome, 70, stdin);
	printf("\n");
	t = strlen(nome) - 1;
	for(int i = 0; i < t; i++) {
		if (nome[i] != ' ')
			tamtotal++;
	}
	for (int i = 0; i < t; i++) {
		if (nome[i] == ' ')
			pos = i + 1;
	}
	for (int i = pos; i < t; i++) {
		printf("%c", nome[i]);
	}
	printf(", ");
	for (int i = 0; i < pos; i++) {
		printf("%c", nome[i]);
	}
	printf("\n");
	printf("Total de letras: %d\n", tamtotal);
	tam3 = t - pos; 
	printf("Total de letras do último sobrenome: %d\n", tam3);
	return 0;
}
