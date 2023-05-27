#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "arvoreB.h"
#include "string.h"
#include "geradorArquivos.h"

//Retorna 0 caso pesquisa em sucesso, e 1 caso contrario
int  Pesquisa(TipoRegistro *x, TipoApontador apontador, Analise **analise){
    long i = 1;

    if(apontador == NULL)
        return 0;

    while(i < apontador->elemento && x->chave > apontador->registro[i-1].chave) {
        i++;
        (*analise)->transferencia_pos_processamento++;
    }

    if(x->chave == apontador->registro[i-1].chave){
        *x = apontador->registro[i-1];
        (*analise)->transferencia_pos_processamento++;
        return 1;
    }

    if(x->chave < apontador->registro[i-1].chave) {
        (*analise)->transferencia_pos_processamento++;
        return Pesquisa(x, apontador->apontadores[i - 1], analise);
    }
    else {
        (*analise)->transferencia_pos_processamento++;
        return Pesquisa(x, apontador->apontadores[i], analise);
    }
}

void InsereNaPagina(TipoApontador apontador, TipoRegistro registro, TipoApontador apontador_direita, Analise** analise){
    int k = apontador->elemento;
    while (k > 0 ){
        if(registro.chave >= apontador->registro[k-1].chave){
            (*analise)->comparacao_pre_processamento++;
            break;
        }

        apontador->registro[k] = apontador->registro[k-1];
        apontador->apontadores[k+1] = apontador->apontadores[k];
        k--;
    }

    apontador->registro[k] = registro;
    apontador->apontadores[k+1] = apontador_direita;
    apontador->elemento++;
}

void ControlaInsercao(TipoRegistro registro, TipoApontador apontador, short *cresceu, TipoRegistro *registro_retorno, TipoApontador *apontador_retorno, Analise **analise){
    long i = 1, j;
    TipoApontador  apontador_temporario;

    if(apontador == NULL){
        *cresceu = true;
        (*registro_retorno) = registro;
        (*apontador_retorno) = NULL;
        return;
    }

    while (i < apontador->elemento && registro.chave > apontador->registro[i-1].chave) {
        i++;
        (*analise)->comparacao_pre_processamento++;
    }

    if(registro.chave == apontador->registro[i-1].chave){
        printf("Erro: Registro ja esta presente\n");
        *cresceu = false;
        (*analise)->comparacao_pre_processamento++;
        return;
    }

    if(registro.chave < apontador->registro[i-1].chave){
        i--;
        (*analise)->comparacao_pre_processamento++;
    }

    ControlaInsercao(registro, apontador->apontadores[i], cresceu, registro_retorno, apontador_retorno, analise);

    if(!*cresceu)
        return;

    if(apontador->elemento < MM){ /* Pagina tem espaco */
        InsereNaPagina(apontador, *registro_retorno, *apontador_retorno, analise);
        *cresceu = false;
        return;
    }

    /* Overflow: Pagina tem que ser dividida */
    apontador_temporario = (TipoApontador)  malloc(sizeof(TipoPagina));
    apontador_temporario->elemento = 0;
    apontador_temporario->apontadores[0] = NULL;

    if(i < M + 1){
        InsereNaPagina(apontador_temporario, apontador->registro[MM - 1], apontador->apontadores[MM], analise);
        apontador->elemento--;
        InsereNaPagina(apontador, *registro_retorno, *apontador_retorno, analise);
    }else
        InsereNaPagina(apontador_temporario, *registro_retorno, *apontador_retorno, analise);

    for(j = M+2; j <= MM; j++)
        InsereNaPagina(apontador_temporario, apontador->registro[j - 1], apontador->apontadores[j], analise);

    apontador->elemento = M;
    apontador_temporario->apontadores[0] = apontador->apontadores[M + 1];
    *registro_retorno = apontador->registro[M];
    *apontador_retorno = apontador_temporario;
}

void Insere(TipoRegistro registro, TipoApontador *apontador, Analise **analise){
    short cresceu;
    TipoRegistro  registro_retorno;
    TipoPagina *apontador_retorno, *apontador_temporario;

    ControlaInsercao(registro, *apontador, &cresceu, &registro_retorno, &apontador_retorno, analise);

    if(cresceu){
        apontador_temporario = (TipoPagina*) malloc(sizeof(TipoPagina));
        apontador_temporario->elemento = 1;
        apontador_temporario->registro[0] = registro_retorno;
        apontador_temporario->apontadores[1] = apontador_retorno;
        apontador_temporario->apontadores[0] = *apontador;
        *apontador = apontador_temporario;
    }
}

void Inicializa(TipoApontador *arvore){
    *arvore = NULL;
}

TipoApontador criaArvoreB(int quantidade_arquivo, Analise **analise){
    TipoApontador arvore;
    Inicializa(&arvore);
    FILE *arquivo = fopen("geradorArquivo.bin", "rb");
    TipoItem item;
    TipoRegistro auxiliar;
    TipoRegistro x;

    (*analise)->tempo_inicial_pre_processamento = clock();
    for(int i = 0; i < quantidade_arquivo; i++){
        fread(&item, sizeof(item), 1, arquivo);
        (*analise)->transferencia_pre_processamento++;
        auxiliar.chave = item.chave;
        auxiliar.item.chave = item.chave;
        auxiliar.item.dado1 = item.dado1;
        strcpy(auxiliar.item.dado2, item.dado2);
        strcpy(auxiliar.item.dado3, item.dado3);
        Insere(auxiliar, &arvore, analise);
    }

    (*analise)->tempo_final_pre_processamento = clock() - (*analise)->tempo_inicial_pre_processamento;

    fclose(arquivo);

    //ImprimeArvoreB(arvore);

    //printf("Chave de Pesquisa: ");
    //scanf("%lld", &x.chave);
    (*analise)->tempo_inicial_pos_processamento = clock();
    x.chave = (*analise)->chave.chave;

    long long int *vetor = criaChavesAleatorias(quantidade_arquivo);
    (*analise)->vetor = vetor;


    if ((*analise)->chave.chave != -1) {
        x.chave = (*analise)->chave.chave;
        if (Pesquisa(&x, arvore, analise))
            printf("chave %lld foi encontrada!\n", x.chave);
        else
            printf("chave %lld nao foi encontrada!\n", x.chave);
    }
    else {
        for(int i = 0; i < 10; i++){
            x.chave = vetor[i];
            if (Pesquisa(&x, arvore, analise))
                printf("chave %lld foi encontrada!\n", x.chave);
            else
                printf("chave %lld nao foi encontrada!\n", x.chave);
        }
    }


    (*analise)->tempo_final_pos_processamento = clock() - (*analise)->tempo_inicial_pos_processamento;
    return arvore;
}

void ImprimeArvoreB(TipoApontador arvore){
    int i = 0;

    if(arvore == NULL)
        return;

    while (i <= arvore->elemento){
        ImprimeArvoreB(arvore->apontadores[i]);
        if(i != arvore->elemento)
            printf("%lld \n", arvore->registro[i].chave);
        i++;
    }
}


/*void Pesquisa(TipoRegistro *x, TipoApontador *apontador){
    int i;
    TipoApontador  pagina;
    pagina = *apontador;

    if((*apontador)->Pt == Interna){
        i = 1;

        while (i < pagina->UU.U0.elementoInterno && x->chave > pagina->UU.U0.registroInterno[i-1])
            i++;

        if(x->chave  < pagina->UU.U0.registroInterno[i-1])
            Pesquisa(x, &pagina->UU.U0.apontadorInterno[i-1]);
        else
            Pesquisa(x, &pagina->UU.U0.apontadorInterno[i]);

        return;
    }

    i = 1;

    while (i < pagina->UU.U1.elementoExterno && x->chave > pagina->UU.U1.registroExterno[i-1])
        i++;

    if(x->chave  == pagina->UU.U1.registroExterno[i-1].chave)
        *x = pagina->UU.U1.registroExterno[i-1];
}*/