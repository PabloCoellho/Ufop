#include "DFS.h"

void lerLinha1(int *n, int *m, int *b, int *i) {
    scanf("%d %d %d %d", n, m, b, i);
}
 
void lerMLinhas (Grafo *g, int b, int m) {
    int vorigem, vdestino, peso;

    if (b == 0) { //Se o grafo for direcionado
        for (int a = 0; a < m; a++){
            scanf("%d %d %d", &vorigem, &vdestino, &peso);
            NovoVertice(&(g->listaadj[vorigem-1]), vdestino-1, peso);  
            NovoVertice(&(g->listaadj[vdestino-1]), vorigem-1, peso);  
        }
    }
    else { //Se o grafo nao for direcionado
        for (int a = 0; a < m; a++){
            scanf("%d %d %d", &vorigem, &vdestino, &peso);
            NovoVertice(&(g->listaadj[vorigem-1]), vdestino-1, peso);
        }
    } 
}

Grafo *alocarGrafo(Grafo *g, int n) {
    g = (Grafo *) malloc (sizeof(Grafo));  
    if (g == NULL) {
        printf ("Erro ao alocar o grafo\n");
        exit (EXIT_FAILURE);
    }

    g->listaadj = (Vertice *) malloc (n * sizeof(Vertice));
    if (g->listaadj == NULL) {
        printf ("Erro ao alocar a lista de adjacencia\n");
        exit (EXIT_FAILURE);
    }
    
    for(int i = 0; i < n; i++) { //Inicializa a lista de adjacencia
        g->listaadj[i].primeiro = NULL;
        g->listaadj[i].visitado = 0;       
    }

    return g;

}

Grafo *desalocarGrafo(Grafo *g) {
    free(g->listaadj);
    free(g);

    g = NULL;

    return g;
}

void busca(Grafo *g, int i) {
    Aresta *aux = NULL;

    g->listaadj[i].visitado = 1; //Visita o vertice
    printf("%d\n", i+1); //Imprime o vertice visitado   

    aux = g->listaadj[i].primeiro;

    while (aux != NULL) { //Enquanto o vertice tiver vizinho
        if(g->listaadj[aux->vdestino].visitado == 0) { //Se o vizinho não foi visitado
            g->listaadj[i].primeiro->visitada = 1;
            busca(g, aux->vdestino);
        }
        else {
            if(g->listaadj[i].primeiro->visitada == 0) { //Se a aresta nao tiver sido visitada
               g->listaadj[i].primeiro->visitada = 1;                
            }
                    
        }  

        aux = aux->prox;
    }
}

void NovoVertice (Vertice *lista, int vdestino, int peso) { //Adiciona um novo vertice como vizinho
    Aresta *aux = lista->primeiro;
    Aresta *ant = NULL;
    Aresta *novo = NULL;

    novo = (Aresta *) malloc (sizeof(Aresta));
    novo->vdestino = vdestino;
    novo->peso = peso;
    novo->visitada = 0;

    while (aux != NULL) { //Procura a posicao correta para insercao 
        if (vdestino < aux->vdestino) 
            break;
        ant = aux;
        aux = aux->prox;
    }
    
    if (ant == NULL) { //Insercao no inicio da lista
        novo->prox = lista->primeiro;
        lista->primeiro = novo;
    } 
    
    else { //Insercao no fim da lista
        novo->prox = ant->prox;
        ant->prox = novo;
    }

}
