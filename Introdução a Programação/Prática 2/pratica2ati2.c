#include <stdio.h>
#include <math.h>
  
int main() {
    int ano;
    printf("Digite o ano\n");
    scanf("%d", &ano);
    if(ano % 4 == 0 && ano % 100 != 0)
    	printf("%d e um ano bissexto\n", ano);
    if(ano % 100 == 0 && ano % 400 == 0)
    	printf("%d e um ano bissexto\n", ano);
    return 0;
}
