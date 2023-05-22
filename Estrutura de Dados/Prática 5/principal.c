#include "fib.h"
#include<stdio.h>

int main()
{
    int n, i;
    //adicionar variaveis conforme necessidade
    TADfib f;
       
    //fazer a leitura do numero de casos de teste
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        
        scanf("%d", &i);
        
        //ler o caso de teste e processar antes de ler o proximo
        f.chamadas = -1;
        f.resultado = fibonacci(i, &f);

        //imprimir a resposta no formato adequado
        printf("fib(%d) = %.0lf chamadas = %.0lf\n", i, f.chamadas, f.resultado);
    }
    
    return 0;//nao remova
}
