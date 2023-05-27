#ifndef PESQUISAEXTERNA_ACESSOSEQUENCIAL_H
#define PESQUISAEXTERNA_ACESSOSEQUENCIAL_H
#include <stdio.h>
#include "arvoreBinaria.h"
#define ITENSPAGINA 4
#define MAXTABELA 100

typedef struct{
    int chave;
} TipoIndice;

int pesquisaAcessoSequencial(TipoIndice*, int, TipoItem*, FILE*, Analise**);

//Funcao Responsavel por  controlar a insercao na tabela de indice e a pesquisa de  um registro (ou 10 registros)
void acessoSequencial(int, Analise**);
void inicializaAnalise(Analise **analise);
void analise();
#endif //PESQUISAEXTERNA_ACESSOSEQUENCIAL_H
