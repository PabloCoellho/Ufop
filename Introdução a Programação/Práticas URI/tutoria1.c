#include <stdio.h>

int main(){
    int c, f;
    printf("Digite a temperatura em graus Celsius:\n");
    scanf("%d", &c);
    f = (9.0 * c + 160) /5;
    printf("%d graus Fahrenheit\n", f);
    return 0;
}
