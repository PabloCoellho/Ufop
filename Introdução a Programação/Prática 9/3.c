#include <stdio.h>
#include <stdlib.h>

int verifica(int **A, int n) {
	int *somal, *somac, somap = 0, somas = 0, a = 0;
	somal = malloc(n * sizeof(int));
	somac = malloc(n * sizeof(int));
	
	for (int i = 0; i < n; i++) {
		somal[i] = 0;
		somac[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			somal[i] += A[i] [j];
			somac[i] += A[j] [i];
			if(i == j)
				somap += A[i] [j];
		}
	}
	
	for (int i = n-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if(i == j) 
				somas += A[i] [j];
		}
	}

	for (int i = 0; i < n-1; i++) {
		if(somal[i] != somal[i+1] || somac[i] != somac[i+1])
			a++;
	}
	
	if(somap != somas)
		a++;
	for (int i = 0; i < n; i++) {
		if(somal[i] != somac[i])
			a++;
		else if(somal[i] != somap)
			a++;
		else if(somac[i] != somap)
			a++;
		else if(somal[i] != somas)
			a++;
		else if(somac[i] != somas)
			a++;
	}
	free(somal);
	free(somac);
	if(a == 0)
		return 1;
	else
		return 0;
}

int main() {
	int **A, n;
	printf("Digite o valor de n: ");
	scanf("%d", &n);
	A = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		A[i] = malloc(n * sizeof(int));
	printf("Digite os valores da matriz n x n: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i] [j]);
	}
	if(verifica(A, n) == 1)
		printf("\nEsta matriz é um quadrado mágico!\n");
	else
		printf("\nEsta matriz não é um quadrado mágico!\n");

	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);
	return 0;
}