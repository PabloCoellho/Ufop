#ifndef PESQUISAEXTERNA_ARVOREBINARIA_H
#define PESQUISAEXTERNA_ARVOREBINARIA_H
#include <stdlib.h>
#include <stdio.h>
#include "stdbool.h"
#include "string.h"
#include "time.h"
#include "geradorArquivos.h"

#define M 2
#define MM M * M
#define QUANTIDADE_ITEM_ARVORE_BINARIA 15

typedef struct TipoItem{
    long long int chave;
    long int dado1;
    char dado2[1000];
    char dado3[5000];
} TipoItem;

typedef long long int TipoChave;

typedef struct TipoRegistro{
    TipoChave chave;
    TipoItem item;
} TipoRegistro;

typedef struct No{
    TipoItem item;
    int esq;
    int dir;
} No;

typedef struct TipoPagina *TipoApontador;

typedef struct TipoPagina{
    short elemento;
    TipoRegistro registro[MM];
    TipoApontador apontadores[MM+1];
} TipoPagina;

typedef struct tipoNode TipoNode;

typedef struct Analise{

    long long int comparacao_pos_processamento;
    long long int transferencia_pos_processamento;
    long long int transferencia_pre_processamento;
    long long int comparacao_pre_processamento;
    clock_t tempo_inicial_total;
    clock_t tempo_final_total;
    clock_t tempo_inicial_pre_processamento;
    clock_t tempo_final_pre_processamento;
    clock_t tempo_inicial_pos_processamento;
    clock_t tempo_final_pos_processamento;
    TipoItem chave;
    long long int *vetor;
    int situacao;
}Analise;

int CriaArvoreBinariaExterna(int quantidade, Analise **);

int InsereArvoreBinaria(FILE *arv, TipoItem *item, int posicao, Analise **);

No CriaNoArvoreBinaria(TipoItem *item);

int PesquisaArvoreBinaria(FILE *arv, TipoItem *x, Analise **);

#endif //PESQUISAEXTERNA_ARVOREBINARIA_H
