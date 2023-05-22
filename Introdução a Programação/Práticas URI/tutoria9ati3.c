#include <stdio.h>
#include <string.h>

typedef struct {
	char data[50];
} Data;

int main() {
	Data A;
	int dia[2], mes[2], ano[4];
	//int add;
	fgets(A.data, 50, stdin);
	for (int i = 0; i < 2; i++) {
		dia[i] = A.data[i] - 48;
		mes[i] = A.data[i] - 53;
	}
	for(int i = 0; i < 4; i++) {
		ano[i] = A.data[i] - 58;
	}
	//scanf("%d", &add);	
	//if (dia < 31 && mes < 13) {
		printf("%d/%d/%d\n", dia, mes, ano);
	//}
	//else
		//printf("Data inválida\n");
	return 0;
}