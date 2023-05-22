#include <stdio.h>

int main(){
    float x1, x2, x3, y;
    printf("Digite os valores de x1, x2, x3:\n");
    scanf("%f", &x1);
    scanf("%f", &x2);
    scanf("%f", &x3);
    y = (x1 + (x2 * x2) + (x3 * x3)) * (x1 + (x2 * x2) + (x3 * x3)) - (x1 * x2 * x3) * (x1 * x2 * x3);
    printf("y = %.0f\n", y);

    return 0;
}
