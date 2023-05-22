#include <stdio.h>

int main(){
    double c, f, k;
    printf("Digite a temperatura em Celsius\n");
    scanf("%lf", &c);
    k = c + 273.15;
    f = (c * 9 / 5) + 32;
    printf("Temperatura em Fahrenheit: %.2lf\n", f);
    printf("Temperatura em Kelvin: %.2lf\n", k);

    return 0;
}
