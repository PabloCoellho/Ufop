#include "arvoreBEstrela.h"

void InsereNaPaginaInterna(TipoApontadorEstrela apontador, TipoChave registro, TipoApontadorEstrela apontador_direita, Analise **analise){
    int k = apontador->UniaoInternaExterna.UniaoInterno.elemento_interno;

    while (k > 0 ){
        if(registro >= apontador->UniaoInternaExterna.UniaoInterno.indices_interno[k-1]) {
            (*analise)->comparacao_pre_processamento++;
            break;
        }

        apontador->UniaoInternaExterna.UniaoInterno.indices_interno[k] = apontador->UniaoInternaExterna.UniaoInterno.indices_interno[k-1];
        apontador->UniaoInternaExterna.UniaoInterno.apontador_interno[k+1] = apontador->UniaoInternaExterna.UniaoInterno.apontador_interno[k];
        k--;
    }

    apontador->UniaoInternaExterna.UniaoInterno.indices_interno[k] = registro;
    apontador->UniaoInternaExterna.UniaoInterno.apontador_interno[k+1] = apontador_direita;
    apontador->UniaoInternaExterna.UniaoInterno.elemento_interno++;
}

void InsereNaPaginaExterna(TipoApontadorEstrela apontador, TipoRegistro registro, Analise **analise){
    int k = apontador->UniaoInternaExterna.UniaoExterno.elemento_externo;

    while (k > 0 ){
        if(registro.chave >= apontador->UniaoInternaExterna.UniaoExterno.registro_externo[k-1].chave) {
            (*analise)->comparacao_pre_processamento++;
            break;
        }

        apontador->UniaoInternaExterna.UniaoExterno.registro_externo[k] = apontador->UniaoInternaExterna.UniaoExterno.registro_externo[k-1];
        k--;
    }

    apontador->UniaoInternaExterna.UniaoExterno.registro_externo[k] = registro;
    apontador->UniaoInternaExterna.UniaoExterno.elemento_externo++;
}

void ControlaInsercaoArvoreB(TipoRegistro registro, TipoApontadorEstrela apontador, short *cresceu, TipoRegistro *registro_retorno, TipoApontadorEstrela *apontador_retorno, Analise **analise){
    long i = 1, j;
    TipoApontadorEstrela apontador_temporario;

    if((*apontador).tipo_interna_externa == Interna){
        while (i < apontador->UniaoInternaExterna.UniaoInterno.elemento_interno && registro.chave > apontador->UniaoInternaExterna.UniaoInterno.indices_interno[i-1]) {
            i++;
            (*analise)->comparacao_pre_processamento++;
        }

        if(registro.chave < apontador->UniaoInternaExterna.UniaoInterno.indices_interno[i-1]) {
            i--;
            (*analise)->comparacao_pre_processamento++;
        }

        ControlaInsercaoArvoreB(registro, apontador->UniaoInternaExterna.UniaoInterno.apontador_interno[i], cresceu, registro_retorno, apontador_retorno, analise);

        if(!*cresceu)
            return;

        if(apontador->UniaoInternaExterna.UniaoInterno.elemento_interno < MM){ // Pagina tem espaco
            InsereNaPaginaInterna(apontador, apontador->UniaoInternaExterna.UniaoInterno.indices_interno[i-1], *apontador_retorno, analise);
            *cresceu = false;
            return;
        }

        // Overflow: Pagina tem que ser dividida
        apontador_temporario = (TipoApontadorEstrela)  malloc(sizeof(TipoPaginaEstrela));
        apontador_temporario->tipo_interna_externa = Interna;
        apontador_temporario->UniaoInternaExterna.UniaoInterno.elemento_interno = 0;
        apontador_temporario->UniaoInternaExterna.UniaoInterno.apontador_interno[0] = NULL;

        if(i < M + 1){//--- Conceito ERRADO Organizara elementos menores que do elemento do meio
            InsereNaPaginaInterna(apontador_temporario, apontador->UniaoInternaExterna.UniaoInterno.indices_interno[MM - 1], apontador->UniaoInternaExterna.UniaoInterno.apontador_interno[MM], analise);
            apontador->UniaoInternaExterna.UniaoInterno.elemento_interno--;
            InsereNaPaginaInterna(apontador, registro_retorno->chave, *apontador_retorno, analise);
        }else //Organizara elementos maiores que do elemento do meio
            InsereNaPaginaInterna(apontador_temporario, registro_retorno->chave, *apontador_retorno, analise);

        for(j = M+2; j <= MM; j++)
            InsereNaPaginaInterna(apontador_temporario, apontador->UniaoInternaExterna.UniaoInterno.indices_interno[j - 1], apontador->UniaoInternaExterna.UniaoInterno.apontador_interno[j], analise);

        apontador->UniaoInternaExterna.UniaoInterno.elemento_interno = M;
        apontador_temporario->UniaoInternaExterna.UniaoInterno.apontador_interno[0] = apontador->UniaoInternaExterna.UniaoInterno.apontador_interno[M + 1];
        registro_retorno->chave = apontador->UniaoInternaExterna.UniaoInterno.indices_interno[M];
        *apontador_retorno = apontador_temporario;
    }else{
        while(i < apontador->UniaoInternaExterna.UniaoExterno.elemento_externo && registro.chave > apontador->UniaoInternaExterna.UniaoExterno.registro_externo[i - 1].chave) {
            i++;
            (*analise)->comparacao_pre_processamento++;
        }

        if(registro.chave == apontador->UniaoInternaExterna.UniaoExterno.registro_externo[i - 1].chave){
            printf("Registro ja esta presente\n");
            *cresceu = false;
            (*analise)->comparacao_pre_processamento++;
            return;
        }

        if(apontador->UniaoInternaExterna.UniaoExterno.elemento_externo < MM){ // Pagina tem espaco
            InsereNaPaginaExterna(apontador, registro, analise);
            *cresceu = false;
            return;
        }

        // Overflow: Pagina tem que ser dividida
        apontador_temporario = (TipoApontadorEstrela)  malloc(sizeof(TipoPaginaEstrela));
        apontador_temporario->tipo_interna_externa = Externa;
        apontador_temporario->UniaoInternaExterna.UniaoExterno.elemento_externo = 0;

        if(i < M + 1){
            InsereNaPaginaExterna(apontador_temporario, apontador->UniaoInternaExterna.UniaoExterno.registro_externo[MM - 1], analise);
            apontador->UniaoInternaExterna.UniaoExterno.elemento_externo--;
            InsereNaPaginaExterna(apontador, registro, analise);
        }else
            InsereNaPaginaExterna(apontador_temporario, registro, analise);

        for(j = M+2; j <= MM; j++)
            InsereNaPaginaExterna(apontador_temporario, apontador->UniaoInternaExterna.UniaoExterno.registro_externo[j - 1], analise);

        apontador->UniaoInternaExterna.UniaoExterno.elemento_externo = M;
        *registro_retorno = apontador->UniaoInternaExterna.UniaoExterno.registro_externo[M];
        *apontador_retorno = apontador_temporario;
    }
    *cresceu = true;
}

void InsereArvoreBEstrela(TipoRegistro registro, TipoApontadorEstrela *apontador, Analise **analise){
    short cresceu;
    TipoRegistro  registro_retorno;
    TipoPaginaEstrela *apontador_retorno, *apontador_temporario;

    if((*apontador)->UniaoInternaExterna.UniaoInterno.elemento_interno == 0){
        apontador_temporario = (TipoPaginaEstrela *) malloc(sizeof(TipoPaginaEstrela));
        apontador_temporario->tipo_interna_externa = Externa;
        apontador_temporario->UniaoInternaExterna.UniaoExterno.elemento_externo = 1;
        apontador_temporario->UniaoInternaExterna.UniaoExterno.registro_externo[0] = registro;
        *apontador = apontador_temporario;
        return;
    }

    ControlaInsercaoArvoreB(registro, *apontador, &cresceu, &registro_retorno, &apontador_retorno, analise);

    if (cresceu) {
        apontador_temporario = (TipoPaginaEstrela *) malloc(sizeof(TipoPaginaEstrela));
        apontador_temporario->tipo_interna_externa = Interna;
        apontador_temporario->UniaoInternaExterna.UniaoInterno.elemento_interno = 1;
        apontador_temporario->UniaoInternaExterna.UniaoInterno.indices_interno[0] = registro_retorno.chave;
        apontador_temporario->UniaoInternaExterna.UniaoInterno.apontador_interno[1] = apontador_retorno;
        apontador_temporario->UniaoInternaExterna.UniaoInterno.apontador_interno[0] = *apontador;
        *apontador = apontador_temporario;
    }
}

void InicializaArvoreEstrela(TipoApontadorEstrela *arvore){
    *arvore = malloc(sizeof(TipoApontadorEstrela*));
    (*arvore)->UniaoInternaExterna.UniaoInterno.elemento_interno = 0;
    (*arvore)->UniaoInternaExterna.UniaoInterno.apontador_interno[0] = NULL;
}

void criaArvoreBEstrela(int quantidade_arquivo, Analise **analise){
    TipoApontadorEstrela arvore;
    InicializaArvoreEstrela(&arvore);
    FILE *arquivo = fopen("geradorArquivo.bin", "rb");
    TipoItem item;
    TipoRegistro *auxiliar = malloc(sizeof(TipoRegistro));
    TipoRegistro x;

    (*analise)->tempo_inicial_pre_processamento = clock();

    for(int i = 0; i < quantidade_arquivo; i++){
        fread(&item, sizeof(item), 1, arquivo);
        auxiliar->chave = item.chave;
        auxiliar->item.chave = item.chave;
        auxiliar->item.dado1 = item.dado1;
        strcpy(auxiliar->item.dado2, item.dado2);
        strcpy(auxiliar->item.dado3, item.dado3);
        InsereArvoreBEstrela(*auxiliar, &arvore, analise);
        (*analise)->transferencia_pre_processamento++;
    }

    (*analise)->tempo_final_pos_processamento = clock() - (*analise)->tempo_inicial_pos_processamento;

    fclose(arquivo);

    //ImprimeArvoreBEstrela(&arvore);

    (*analise)->tempo_inicial_pos_processamento = clock();

    long long int x_registro;
    //scanf("%lld", &x_registro);
    x.chave = (*analise)->chave.chave;
    x_registro = (*analise)->chave.chave;

    (*analise)->vetor = criaChavesAleatorias(quantidade_arquivo);

    if((*analise)->chave.chave != -1){
        scanf("%lld", &x_registro);
        PesquisaBEstrela(&x_registro, &x, &arvore, analise);
        if(x.item.chave == x.chave)
            printf("A chave %lld foi encontrada com sucesso\n", x.chave);
        else
            printf("A chave nao foi encontrada\n");
    }else{
        for(int i = 0; i < 10; i++){
            PesquisaBEstrela(&x_registro, &x, &arvore, analise);

            if(x.item.chave == x.chave)
                printf("A chave %lld foi encontrada com sucesso\n", x.chave);
            else
                printf("A chave nao foi encontrada\n");
        }
    }

    (*analise)->tempo_final_pos_processamento = clock() - (*analise)->tempo_inicial_pos_processamento;
}

void ImprimeArvoreBEstrela(TipoApontadorEstrela *arvore){
    //int i = 0;

    if((*arvore)->tipo_interna_externa == Interna){
        //printf("Interna: ");
        for(int i = 0; i < (*arvore)->UniaoInternaExterna.UniaoInterno.elemento_interno; i++)
            continue;
        //printf("%lld \n", (*arvore)->UniaoInternaExterna.UniaoInterno.indices_interno[i]);

        for(int i = 0; i <= (*arvore)->UniaoInternaExterna.UniaoInterno.elemento_interno; i++){
            ImprimeArvoreBEstrela(&(*arvore)->UniaoInternaExterna.UniaoInterno.apontador_interno[i]);
        }
    }else{
        for(int i = 0; i < (*arvore)->UniaoInternaExterna.UniaoExterno.elemento_externo; i++)
            printf("%lld\n", (*arvore)->UniaoInternaExterna.UniaoExterno.registro_externo[i].chave);
    }
}

void PesquisaBEstrela(long long int *x_chave, TipoRegistro *x, TipoApontadorEstrela *apontador, Analise **analise){
    int i;
    TipoApontadorEstrela pagina;
    pagina = *apontador;

    if((*apontador)->tipo_interna_externa == Interna){
        i = 1;

        while (i < pagina->UniaoInternaExterna.UniaoInterno.elemento_interno && x->chave > pagina->UniaoInternaExterna.UniaoInterno.indices_interno[i-1]) {
            i++;
            (*analise)->comparacao_pos_processamento++;
        }

        if(x->chave  < pagina->UniaoInternaExterna.UniaoInterno.indices_interno[i-1]) {
            (*analise)->comparacao_pos_processamento++;
            PesquisaBEstrela(x_chave, x, &pagina->UniaoInternaExterna.UniaoInterno.apontador_interno[i - 1], analise);
        }
        else {
            (*analise)->comparacao_pos_processamento++;
            PesquisaBEstrela(x_chave, x, &pagina->UniaoInternaExterna.UniaoInterno.apontador_interno[i], analise);
        }

    }

    i = 1;

    if((*apontador)->tipo_interna_externa == Externa){
        while (i < pagina->UniaoInternaExterna.UniaoExterno.elemento_externo && x->chave > pagina->UniaoInternaExterna.UniaoExterno.registro_externo[i-1].chave){
            i++;
            (*analise)->comparacao_pos_processamento++;
        }

        if(x->chave  == pagina->UniaoInternaExterna.UniaoExterno.registro_externo[i-1].chave) {
            *x = pagina->UniaoInternaExterna.UniaoExterno.registro_externo[i - 1];
            (*analise)->comparacao_pos_processamento++;
            return;
        }
    }
}