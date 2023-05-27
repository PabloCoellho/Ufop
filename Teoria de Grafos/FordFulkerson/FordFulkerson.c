#include "FordFulkerson.h"

void lerLinha1(int *n, int *m) {
    scanf("%d %d", n, m);
}
 
void lerMLinhas (Grafo *g, int m) {
    int vorigem, vdestino, limitesup;
    for (int a = 0; a < m; a++){
        scanf("%d %d %d", &vorigem, &vdestino, &limitesup);
        NovoVertice(&(g->listaadj[vorigem-1]), vdestino-1, limitesup); 
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
    
    for(int i = 0; i < n; i++) {
        g->listaadj[i].primeiro = (Aresta*) malloc (sizeof(Aresta));
        g->listaadj[i].primeiro->prox = NULL;
    }

    return g;

}

Grafo *desalocarGrafo(Grafo *g) {
    free(g->listaadj);
    free(g);

    g = NULL;

    return g;
}

void NovoVertice (Vertice *lista, int vdestino, int limitesup) { //Adiciona um novo vertice como vizinho
    Aresta *aux = NULL;
    Aresta *novo = NULL;

    aux = lista->primeiro;

    novo = (Aresta *) malloc (sizeof(Aresta));
    novo->vdestino = vdestino;
    novo->limiteSup = limitesup;

    while (aux->prox != NULL) { //Procura a posicao correta para insercao
        if (aux->prox->vdestino > vdestino) 
            break;

        aux = aux->prox;
    }
    
    novo->prox = aux->prox;
	aux->prox = novo;

}

int *alocaVetor(int *vetor, int n) {
    vetor = (int *) malloc (n * sizeof(int));

    if (vetor == NULL) {
        printf ("Erro ao alocar o vetor\n");
        exit (EXIT_FAILURE);
    }

    return vetor;
}

int *desalocaVetor(int *vetor) {
    free(vetor);
    vetor = NULL;
    return vetor;
}

void FordFulkerson(Grafo *go, int n){
    int *camT = NULL;
    int *vVisitado = NULL;
    Grafo *gAux = NULL;

    camT = alocaVetor(camT, n);
    vVisitado = alocaVetor(vVisitado, n);
    gAux = alocarGrafo(gAux, n);

    Aresta *criaGa = NULL;

    for (int t = 0; t < n; t++) { //Criando o grafo com arestas diretas e reversas
		criaGa = go->listaadj[t].primeiro->prox;	
		while (criaGa != NULL) {
            NovoVertice(&(gAux->listaadj[t]), criaGa->vdestino, criaGa->limiteSup); //Criando aresta direta
            NovoVertice(&(gAux->listaadj[criaGa->vdestino]), t, 0); //Criando aresta reversa

			criaGa = criaGa->prox;
		}
	}

    Aresta *aux;
    int chegou = 1;
    int T = n-1;

    while(chegou == 1) {
        chegou = chamaBusca(gAux, 0, camT, vVisitado, n);

        if (chegou == 0)
            break;

        fluxoCaminho = INT_MAX;

        for (int z = 0; z < tamTotalC; z++) {

            if (camT[z] == -1 || camT[z] == T)
                break;
			
            aux = gAux->listaadj[camT[z]].primeiro->prox;
			
			while (aux != NULL) {
				if (aux->vdestino == camT[z+1]) 
					break;

				aux = aux->prox;
			}

			if (aux == NULL)
                break;

			if (verifLimSup(aux) == 1) { //Se o limite superior for maior que 0
				aux->dir = 1;
				if (aux->limiteSup < fluxoCaminho) //Aresta direta
                    fluxoCaminho = aux->limiteSup;  
                
			}	
			else {
				aux->dir = 0;
				if ((aux->limiteSup * -1) < fluxoCaminho) //Aresta reversa, passa o limite superior negativo
                    fluxoCaminho = (aux->limiteSup * -1);
                
			}

            imprimir(camT[z]+1, aux->dir, fluxoCaminho);
			
		}
		printf("\n");
		
		if (fluxoCaminho == 0) 
            break; 

		Aresta *retorno = NULL;

		for (int z = 0; z < tamTotalC; z++) {

            if (camT[z] == -1 || camT[z] == T)
                break;

			aux = gAux->listaadj[camT[z]].primeiro->prox;
            
			while (aux != NULL) {
				if (aux->vdestino == camT[z+1]) 
					break;

				aux = aux->prox;
			}

			if (aux == NULL) 
                break;

			retorno = gAux->listaadj[camT[z+1]].primeiro->prox;

			while (retorno != NULL) {
				if (retorno->vdestino == camT[z]) 
					break;

				retorno = retorno->prox;
			}

            if (retorno == NULL) 
                break;


			if (verifLimSup(aux) == 1) { //Atualizar aresta Direta
                dimiAumenFluxo(aux, 0); //Subtrai o limite superior das arestas
                dimiAumenFluxo(retorno, 0); 

			}	
			else { //Atualizar aresta Reversa
                dimiAumenFluxo(aux, 1); //Soma o limite superior das arestas
                dimiAumenFluxo(retorno, 1);
			}

		}

    }
    camT = desalocaVetor(camT);
    vVisitado = desalocaVetor(vVisitado);
    gAux = desalocarGrafo(gAux);
        
}

int chamaBusca(Grafo *g, int i, int *camT, int *vVisitado, int n) {
    int chegou = 0;
    int tamCaminho = 0;

    limpaVisitacoes(camT, vVisitado, n);
    
    busca(g, i, camT, vVisitado, n, tamCaminho, &chegou);

    return chegou;
}


void busca(Grafo *g, int i, int *camT, int *vVisitado, int n, int tamCaminho, int *chegou) {
    //Verifica se há caminhos entre S e T

    Aresta *aux;
    aux = g->listaadj[i].primeiro->prox;
 
    vVisitado[i] = 1;
    int T = n-1;
          
    while(aux != NULL) { //Enquanto o vertice tiver vizinho

        if (vVisitado[aux->vdestino] == 0 && aux->limiteSup != 0) {
            camT[tamCaminho] = i;
            tamTotalC = tamCaminho + 1;
            busca(g, aux->vdestino, camT, vVisitado, n, tamCaminho + 1, chegou); 
        }

        if (vVisitado[T] == 1) { 
			camT[tamCaminho] = i;
            *chegou = 1; 

			return;
		}
        aux = aux->prox;
        
    }  
    *chegou = 0;
    
}

void imprimir(int ini, int arco, int aumen) {
    
    printf("[%d, ", ini);

    if (arco == 1)
        printf("+, ");
    else    
        printf("-, ");
    
    printf("%d] ", aumen);
        
}

void dimiAumenFluxo(Aresta *aux, int mm) {
    if(mm == 1) {
        aux->limiteSup += fluxoCaminho; 
        return;
    }
    else {
        aux->limiteSup -= fluxoCaminho;
        return;
    } 
}

void limpaVisitacoes(int *camT, int *vVisitado, int n) {
    for(int u = 0; u < n; u++) { //Limpa as visitações dos vertices e o caminho até T
		vVisitado[u] = 0;
        camT[u] = 0;	
	}
}

int verifLimSup(Aresta *aux) {
    if(aux->limiteSup > 0)
        return 1;

    return 0;
}


 