#include "kahn.h"

void lerLinha1(int *n, int *m) {
    scanf("%d %d", n, m);
}

void lerMLinhas (Grafo *g, int m) { //ler a M linhas de entrada
    int vorigem, vdestino;
    g->arcos = m;
    for (int i = 0; i < m; i++){
        scanf("%d %d", &vorigem, &vdestino);
        g->matrizadj[vorigem-1][vdestino-1].aresta = 1;
        g->vEntrada[vdestino-1]++; 
    }
    
}

Grafo *alocarGrafo(Grafo *g, int n) {
    g = (Grafo *) malloc (sizeof(Grafo));  
    if (g == NULL) {
        printf ("Erro ao alocar o grafo\n");
        exit (EXIT_FAILURE);
    }

    g->vEntrada = (int *) malloc (n * sizeof(int));

    g->matrizadj = (Matriz **) malloc (n * sizeof(Matriz*));
    for (int i = 0; i < n; i++) {
        g->matrizadj[i] = (Matriz *) malloc (n * sizeof(Matriz));
    }
    
    for(int i = 0; i < n; i++) { //Inicializa a matriz de adjacencia e o restante do grafo
        g->vEntrada[i] = 0;
        for (int j = 0; j < n; j++) {
            g->matrizadj[i][j].aresta = 0;
        }  
    }
    
    return g;

}

Grafo *desalocarGrafo(Grafo *g, int n) {
    for(int i = 0; i < n; i++)
        free(g->matrizadj[i]);
    free(g->matrizadj);
    free(g->vEntrada);
    free(g);

    g = NULL;

    return g;
}

int arcoEntrada (Grafo *g, int n, int *s) { //Verifica se o vértice tem arco de entrada, 
    int a = 0;                             //Se nao tiver ele é colocado no vetor s.
    for (int i = 0; i < n; i++) {
        if (g->vEntrada[i] == 0) {
            s[a] = i;
            a++;
        }         
    }
    return a;
}

void ordenacaoKahn (Grafo *g, int n) {
    int *l = NULL;
    int *s = NULL;
    int j = 0, x = 0, a;

    l = alocaVetor(l, n);
    s = alocaVetor(s, n); //Vetor com os vertices que nao tem arco de entrada

    //vEntrada, vetor que marca quantos vértices de entrada o vértice tem

    a = arcoEntrada(g, n, s);


    while (listaS(s, n) != 0) {  //enquanto a lista s tiver elementos entra no while    
        l[j] = s[x];
        x++; //contador do vetor s
       
        for (int b = 0; b < n; b++) {
            if(g->matrizadj[l[j]][b].aresta != 0){
                g->matrizadj[l[j]][b].aresta = 0;
                g->arcos--;
                g->vEntrada[b]--;
                if(g->vEntrada[b] == 0) {
                    s[a] = b;
                    a++;
                }
            }
        }    

        s[j] = -1; //remove o elemento do vetor s
        j++;
    }

    if (g->arcos != 0)
        printf("Erro: ciclo detectado\n");
    else    
        imprime(l, j);
    
    s = desalocaVetor(s);
    l = desalocaVetor(l);
          
}

int listaS(int *s, int n) { //funcao que retorna se o vetor s esta vazio ou nao
    for(int i = 0; i < n; i++) {
        if (s[i] != -1)
            return 1;
    }
    return 0;

}

int *alocaVetor(int *v, int n) {
    v = (int *) malloc (n * sizeof(int)); //aloca o vetor
    if (v == NULL)
        exit(EXIT_FAILURE);

    for (int z = 0; z < n; z++) { //inicializa o vetor
        v[z] = -1;
    }

    return v;
}

int *desalocaVetor(int *v) {
    free(v);
    v = NULL;
    return v;
}

void imprime(int *l, int j) { //Imprime o vetor l
    printf("L = {");
    for (int i = 0; i < j-1; i++) {
        printf("%d, ", l[i]+1);
    }
    printf("%d}\n", l[j-1]+1);

}