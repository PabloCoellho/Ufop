#include "FordFulkerson.h"

int main() {
    int n, m;
    Grafo *go = NULL;

    lerLinha1(&n, &m); //Le a primeira linha de entrada

    go = alocarGrafo(go, n); //Aloca o grafo original

    lerMLinhas(go, m); //Le as M linhas de entrada

    FordFulkerson(go, n); //Chama a função Ford Fulkerson 

    go = desalocarGrafo(go); //Desaloca a lista de adjacencia e o grafo original

    return 0; 
}