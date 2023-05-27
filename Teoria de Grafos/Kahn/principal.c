#include "kahn.h"

int main() {
    int n, m;
    Grafo *g = NULL;

    lerLinha1(&n, &m);

    g = alocarGrafo(g, n); 

    lerMLinhas (g, m);

    ordenacaoKahn(g, n); 

    g = desalocarGrafo(g, n);
 
    return 0;
}