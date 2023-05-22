#include <stdio.h>

int main(){
    int x, y, z;
    printf("Digite 3 numeros\n");
    scanf("%d %d %d", &x, &y, &z);
    if(x < y && x < z)
    	printf("Menor: %d\n", x); 
    if(y < x && y < z)
    	printf("Menor: %d\n", y); 
    if(z < y && z < x)
    	printf("Menor: %d\n", z);
    if((x > y && z < y) || (y > x && y < z))
   	printf("Intermediário: %d\n", y);
    if((y > x && z < x) || (x > y && x < z))
    	printf("Intermediário: %d\n", x);
    if((z > x && z < y) || (z < x && z > y))
    	printf("Intermediário: %d\n", z); 
    if(x > y && x > z)
    	printf("Maior: %d\n", x); 
    if(y > x && y > z)
    	printf("Maior: %d\n", y); 
    if(z > y && z > x)
    	printf("Maior: %d\n", z); 
    return 0;
}


