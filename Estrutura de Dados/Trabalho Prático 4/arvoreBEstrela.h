#ifndef PESQUISAEXTERNA_ARVOREBESTRELA_H
#define PESQUISAEXTERNA_ARVOREBESTRELA_H
#include "arvoreBinaria.h"

typedef enum {Interna, Externa} TipoInternaExterna;
typedef struct TipoPaginaEstrela *TipoApontadorEstrela;

typedef struct TipoPaginaEstrela {
    TipoInternaExterna  tipo_interna_externa;
    union{
        struct {
            int elemento_interno;
            TipoChave indices_interno[MM];
            TipoApontadorEstrela apontador_interno[MM + 1];
        } UniaoInterno;
        struct {
            long int elemento_externo;
            TipoRegistro registro_externo[MM*2];
        } UniaoExterno;
    } UniaoInternaExterna;
} TipoPaginaEstrela;

void InsereArvoreBEstrela(TipoRegistro, TipoApontadorEstrela *, Analise **);
void ControlaInsercaoArvoreB(TipoRegistro, TipoApontadorEstrela, short *, TipoRegistro *, TipoApontadorEstrela *, Analise **);
//void InsereNaPagina(TipoApontadorEstrela, TipoChave, TipoRegistro, TipoApontadorEstrela);
//void InsereNaPagina(TipoApontadorEstrela, TipoRegistro, TipoApontadorEstrela);
void InsereNaPaginaInterna(TipoApontadorEstrela, TipoChave, TipoApontadorEstrela, Analise **);
void InsereNaPaginaExterna(TipoApontadorEstrela, TipoRegistro, Analise **);
void PesquisaBEstrela(long long int *x_chave, TipoRegistro *x, TipoApontadorEstrela *apontador, Analise **);

void InicializaArvoreEstrela(TipoApontadorEstrela *arvore);
void criaArvoreBEstrela(int quantidade_arquivo, Analise **);
void ImprimeArvoreBEstrela(TipoApontadorEstrela *arvore);

TipoApontadorEstrela* teste1();
void teste2(TipoApontadorEstrela *arvore);
#endif //PESQUISAEXTERNA_ARVOREBESTRELA_H
