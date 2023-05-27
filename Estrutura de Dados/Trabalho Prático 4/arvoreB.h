#ifndef PESQUISAEXTERNA_ARVOREB_H
#define PESQUISAEXTERNA_ARVOREB_H
#include "arvoreBinaria.h"

int  Pesquisa(TipoRegistro *, TipoApontador, Analise**);
void InsereNaPagina(TipoApontador , TipoRegistro , TipoApontador , Analise**);
void ControlaInsercao(TipoRegistro , TipoApontador , short *, TipoRegistro *, TipoApontador *, Analise**);
void Inicializa(TipoApontador *);
TipoApontador criaArvoreB(int quantidade_arquivo, Analise **analise);
long long int* criaChavesAleatorias(long long int quantidade_arquivo);
void ImprimeArvoreB(TipoApontador arvore);
#endif //PESQUISAEXTERNA_ARVOREB_H
