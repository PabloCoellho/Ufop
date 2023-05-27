#include <stdio.h>

void multiplicacao (int M1[2][2], int M2[2][2]) {
    int a = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];
    int b = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];
    int c = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];
    int d = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];
    M1[0][0] = a;
    M1[0][1] = b;
    M1[1][0] = c;
    M1[1][1] = d;
}
/*
Análise da função multiplicacao: θ(1)
linha 4: θ(1)
linha 5: θ(1)
linha 6: θ(1)
linha 7: θ(1)
linha 8: θ(1)
linha 9: θ(1)
linha 10: θ(1)
linha 11: θ(1)
*/

void potencia(int M[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    int M1[2][2] ={{1, 1}, {1, 0}};
    potencia(M, n/2);
    multiplicacao(M, M);
    if (n % 2 != 0)
        multiplicacao(M, M1);
}
/*
Análise da função potencia: θ(log n)
linha 26: θ(1)
linha 27: θ(1)
linha 28: θ(1)
linha 29: T(n/2)
linha 30: θ(1)
linha 31: θ(1)
linha 31: θ(1)

Relação de Recorrência:
T(0) = θ(1)
T(1) = θ(1)
T(n) = θ(1) + T(n/2^1)

Resolvendo Relação de Recorrência:
T(n) = θ(1) + T(n/2^1)
     = θ(1) + θ(1) + T(n/2^2) = 2θ(1) + T(n/2^2)
     = 2θ(1) + θ(1) + T(n/2^3) = 3θ(1) + T(n/2^3)
     = 3θ(1) + θ(1) + T(n/2^4) = 4θ(1) + T(n/2^4)

     = k * θ(1) + T(n/2^k)

Caso Base: T(1) = θ(1)
T(n): k * θ(1) + T(n/2^k)

n/2^k = 1
2^k = n
k = log n

T(n): k * θ(1) + T(n/2^k)
T(n) = log n * θ(1) + θ(1)
T(n) = θ(log n) + θ(1)
T(n) = θ(log n)
*/

int fib(int n) {
    int M[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    potencia(M, n-1);
    return M[0][0];
    
}
/*
Análise da função fib: θ(log n)
linha 71: θ(1)
linha 72: θ(1)
linha 73: θ(1)
linha 74: θ(log n)
linha 75: θ(1)
*/

int main() {
    int result = fib(9);
    printf("%d\n", result);
    return 0;
}
/*
Análise do main: θ(log n)
linha 88: θ(log n)
linha 89: θ(1)
linha 90: θ(1)

Ordem de complexidade do algoritmo = θ(log n)
*/
