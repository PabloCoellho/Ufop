#include <stdio.h>

int main() {
	FILE *arquivo = fopen("bin.dat", "rb");
	for(int i = 0; i < 3; i++) {
		fread(&x.matricula, sizeof(int), 1, arquivo);
		fread(&x.frequencia, sizeof(float), 1, arquivo);
		fread(&x.nota, sizeof(float), 1, arquivo);
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ", x.matricula);
		printf("%f ", x.frequencia);
		printf("%f\n", x.nota);
	}
	return 0;	
}