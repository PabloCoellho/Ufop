#include "DFS.h"

int main() {
    int n, m, b, i;
    Grafo *g = NULL;
    
    lerLinha1(&n, &m, &b, &i); //Le a primeira linha de entrada 
    
    g = alocarGrafo(g, n); //Aloca o grafo e aloca e inicializa a lista de adj

    lerMLinhas(g,  b, m); //Le as M linhas de entrada

    busca(g, i-1); //Funcao da busca em profundidade

    g = desalocarGrafo(g); //Desaloca a lista de adjacencia e o grafo

    return 0;
} 