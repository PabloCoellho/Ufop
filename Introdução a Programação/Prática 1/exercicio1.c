#include <stdio.h>

int main(){
    float a, b, c, d, x;
    printf("Digite os valores de a, b, c, d:\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    x = a * a * a * ((b + c) / d);
    printf("\na = %.0f, b = %.0f, c = %0.f, d = %.0f\n", a, b, c, d);
    printf("x = %0.f\n", x);

    return 0;
}
