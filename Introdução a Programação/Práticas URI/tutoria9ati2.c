#include <stdio.h>
#include <math.h>

typedef struct {
	int distancia1, distancia2;
} Ponto;

void calcular(Ponto x, Ponto y) {
	float dist;
	dist = sqrt(pow((x.distancia2 - x.distancia1), 2) + (pow((y.distancia2 - y.distancia1), 2)));
	if (dist < 0)
		dist = dist * -1;
	printf("D = %f\n", dist);
}

int main() {
	Ponto x, y;
	scanf("%d %d", &x.distancia1, &y.distancia1);
	scanf("%d %d", &x.distancia2, &y.distancia2);
	calcular(x, y);
	return 0;
}