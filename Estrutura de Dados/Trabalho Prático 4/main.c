#include <time.h>
#include <stdio.h>
#include "geradorArquivos.h"
#include "acessoSequencial.h"
#include "arvoreBinaria.h"
#include "arvoreB.h"
#include "arvoreBEstrela.h"
#include "string.h"

void analise_ler(Analise **analise){
    printf("Comparacoes Acesso Sequencial Pre - Processamento: %lld\n", (*analise)->comparacao_pre_processamento);
    printf("Transferencia Acesso Sequencial Pre - Processamento: %lld\n", (*analise)->transferencia_pre_processamento);
    printf("Tempo de execucao Pre - Processamento: %f\n", ((float)(*analise)->tempo_final_pre_processamento)/CLOCKS_PER_SEC);
    printf("*******\n");
    printf("Comparacoes Acesso Sequencial Pos - Processamento: %lld\n", (*analise)->comparacao_pos_processamento);
    printf("Transferencia Acesso Sequencial Pos - Processamento: %lld\n", (*analise)->transferencia_pos_processamento);
    printf("Tempo de execucao Pos - Processamento: %f\n", ((float)(*analise)->tempo_final_pos_processamento)/CLOCKS_PER_SEC);
    printf("*******\n");
    printf("Comparacoes Acesso Sequencial TOTAL: %lld\n", ((*analise)->comparacao_pos_processamento + (*analise)->comparacao_pre_processamento));
    printf("Transferencia Acesso Sequencial TOTAL: %lld\n", ((*analise)->transferencia_pos_processamento + (*analise)->transferencia_pre_processamento));
    (*analise)->tempo_final_total = clock() - (*analise)->tempo_inicial_total;
    printf("Tempo de execucao: %f\n\n", (((float)(*analise)->tempo_final_total)/CLOCKS_PER_SEC) * 10);
}

int main(int argc, char *argv[]) {
    long long int* comp = 0;
    long long int* trans = 0;
    TipoItem* resposta;
    //TipoItem item;
    char comando[10];
    int metodo;
    int quantidade;
    int situacao;
    int chave;
    int opicional = 0;
    char parametro6[4];
    Analise *analise = malloc (sizeof(Analise));

    if(argv[5] == NULL)
        strcpy(parametro6, "full");
    else
        strcpy(parametro6, argv[5]);


    metodo = atoi(argv[1]);

    quantidade = atoi(argv[2]);

    situacao = atoi(argv[3]);

    chave = atoi(argv[4]);

    (*analise).situacao = situacao;

    if (argc != 5 && argc != 6)
        exit(1);


    if (strcmp(parametro6, "[-P]") == 0)
        opicional++;

    if (quantidade <= 0) {
        exit(1);
    }

    switch (situacao) {
        case 1:
            criaGeradorArquivoCrescente(quantidade);
            break;
        case 2:
            criaGeradorArquivoDecrescente(quantidade);
            break;
        case 3:
            criaGeradorArquivoAleatorio(quantidade);
            break;
        default:
            exit(1);
            break;
    }

    if (metodo == 1) { //Acesso Sequencial Indeixado
        inicializaAnalise(&analise);
        analise->tempo_inicial_total = clock();
        analise->chave.chave = chave;
        acessoSequencial(quantidade, &analise);
        analise_ler(&analise);
    }else if (metodo == 2) { //Arvore Binaria
        inicializaAnalise(&analise);
        analise->tempo_inicial_total = clock();
        analise->chave.chave = chave;
        CriaArvoreBinariaExterna(quantidade, &analise);
        analise_ler(&analise);
    }else if (metodo == 3) { //Arvore B
        inicializaAnalise(&analise);
        analise->tempo_inicial_total = clock();
        analise->chave.chave = chave;
        criaArvoreB(quantidade, &analise); //Nao encontra a chave
        analise_ler(&analise);

    }else if (metodo == 4) { //Arvore B*
        inicializaAnalise(&analise);
        analise->tempo_inicial_total = clock();
        analise->chave.chave = chave;
        criaArvoreBEstrela(quantidade, &analise);
        analise_ler(&analise);

    }else
        exit(1);

    if (opicional == 1) {
        lerVetor(analise->vetor);
    }

    return 0;
}