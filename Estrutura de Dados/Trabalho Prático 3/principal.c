#include "buscabinaria.h"
#include <stdio.h>

int main () {
	int *v, a, n;
	double h;
	
	scanf("%d %d", &n, &a);
		
	while(n != 0 && a != 0) {
		
		v = Aloca_Vetor (v, n);

		for(int i = 0; i < n; i++) 
			scanf("%d", &v[i]);

		h = Vetor_Find (v, a, n);
		
		if (h == 0)
			printf(":D\n");

		else if (h == -1)
			printf("-.-\n");

		else 
			printf("%.4lf\n", h);		

		scanf("%d %d", &n, &a);

		v = Desaloca_Vetor (v);
	}

	return 0;
}
