#include <stdio.h>
#include <string.h>

#define v 50

int main () {
	int tamt, tam1, tam2;
	char pala1[v], pala2[v];
	printf("Digite as duas strings\n");
	scanf("%s", pala1);
	scanf("%s", pala2);	
	tam1 = strlen(pala1);
	tam2 = strlen(pala2);
	tamt = strlen(pala1) + strlen(pala2);
	if (tamt < 10) {
		strcat(pala1, pala2);
		printf("%s\n", pala1);
	}
	if (tamt >= 10) {
		for (int i = 0; i < tam1; i += 2) {
			printf("%c ", pala1[i]);
		}
		for (int i = 1; i < tam2; i += 2) {
			printf("%c ", pala2[i]);
		}
	printf("\n");
	}
	return 0;
}
