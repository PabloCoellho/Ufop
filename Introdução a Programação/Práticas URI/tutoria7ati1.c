#include <stdio.h>
#include <string.h>

#define v 50

int main () {
	int idade1, idade2;
	char nome1[v], nome2[v];
	printf("Digite o nome e a idade de duas pessoas\n");
	scanf("%s", nome1);
	scanf("%d", &idade1);
	fflush(stdin);
	scanf("%s", nome2);
	scanf("%d", &idade2);
	fflush(stdin);
	if (idade1 < idade2)
		printf("%s eh a pessoa mais velha\n", nome2);
	else
		printf("%s eh a pessoa mais velha\n", nome1);
	return 0;
}
	
		
	

