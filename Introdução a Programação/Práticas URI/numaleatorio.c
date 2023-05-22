#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int i, na, h;
	i = 1;	
	h = 20;

	while(i <= 10) {
		na = h + rand() % (200 - h + 1);
		printf("%d ", na);
		i++;
		h++;
	}
	printf("\n");
	return 0;
}
	
	
	

