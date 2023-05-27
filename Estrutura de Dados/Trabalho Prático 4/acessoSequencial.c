#include <stdlib.h>
#include <time.h>
#include "acessoSequencial.h"
#include "geradorArquivos.h"

//Inicializa os valores das analises
void inicializaAnalise(Analise **analise){
    //analise = malloc(sizeof(Analise));
    (*analise)->comparacao_pos_processamento = 0;
    (*analise)->comparacao_pre_processamento = 0;
    (*analise)->transferencia_pos_processamento = 0;
    (*analise)->transferencia_pre_processamento = 0;
    (*analise)->chave.chave = -1;
}

//Funcao responsavel por
int pesquisaAcessoSequencial(TipoIndice tabela[], int tamanho, TipoItem *item, FILE *arquivo, Analise **analise){
    TipoItem pagina[ITENSPAGINA];

    int a = sizeof(TipoItem);
    int i = 0;
    unsigned long long int quantidade_itens ;
    unsigned long long int deslocamento;

    //Pesquisa sequencial responvel po identificar se o registro da pesquisa esta na tabela de indice
    if((*analise)->situacao == 1) {
        while (i < tamanho && tabela[i].chave <= item->chave) {
            i++;
            (*analise)->comparacao_pos_processamento++;
        }
    }else if((*analise)->situacao == 2){
        while (i < tamanho && tabela[i].chave >= item->chave) {
            i++;
            (*analise)->comparacao_pos_processamento++;
        }
    }

    if (i == 0)
        return 0;
    else{
        fseeko64(arquivo, 0, SEEK_END);
        //Verifica a quantidade de itens da pagina
        quantidade_itens = (ftello64(arquivo) / sizeof(TipoItem)) % ITENSPAGINA;
        if(i < tamanho || quantidade_itens == 0)
            quantidade_itens = ITENSPAGINA;
    }

    deslocamento = (i - 1) * ITENSPAGINA * sizeof(TipoItem);
    fseeko64(arquivo, deslocamento, SEEK_SET);
    fread(&pagina, sizeof(TipoItem), quantidade_itens, arquivo);
    //printf("%lld\n", *item);
    (*analise)->transferencia_pos_processamento++;

    //Pesquisa sequencial caso o registro esteja na pagina
    for(i = 0; i < quantidade_itens; i++){
        if(pagina[i].chave == item->chave){
            *item = pagina[i];
            return 1;
        }
        (*analise)->comparacao_pos_processamento++;
    }
    return 0;
}

//Funcao Responsavel por  controlar a insercao na tabela de indice e a pesquisa de  um registro (ou 10 registros)
void acessoSequencial(int quantidade_dados, Analise **analise){
    TipoIndice *tabela = malloc(((quantidade_dados + 100) / ITENSPAGINA) * sizeof(TipoIndice));
    FILE *arquivo;
    TipoItem x;
    TipoItem *memoria_principal = malloc(ITENSPAGINA * sizeof(TipoItem));
    int posicao = 0;

    if((arquivo = fopen("geradorArquivo.bin", "rb")) == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }
    (*analise)->tempo_inicial_pre_processamento = clock();

    //Cria a tabela de pagina
    while(fread(memoria_principal, sizeof(TipoItem), 4, arquivo) == 4){
        tabela[posicao].chave = memoria_principal[0].chave;
        posicao++;
        (*analise)->transferencia_pre_processamento++;
    }

    fflush(stdout);

    long long int *vetor = criaChavesAleatorias(quantidade_dados);
    (*analise)->vetor = vetor;

    (*analise)->tempo_final_pre_processamento = clock() - (*analise)->tempo_inicial_pre_processamento;

    (*analise)->tempo_inicial_pos_processamento = clock();

    if ((*analise)->chave.chave != -1) {
        x.chave = (*analise)->chave.chave;
        if (pesquisaAcessoSequencial(tabela, posicao, &x, arquivo, analise))
            printf("chave %lld foi encontrada!\n", x.chave);
        else
            printf("chave %lld nao foi encontrada!\n", x.chave);
    }
    else {
        for(int i = 0; i < 10; i++){
            x.chave = vetor[i];
            if (pesquisaAcessoSequencial(tabela, posicao, &x, arquivo, analise))
                printf("chave %lld foi encontrada!\n", x.chave);
            else
                printf("chave %lld nao foi encontrada!\n", x.chave);
        }
    }

    (*analise)->tempo_final_pos_processamento = clock() - (*analise)->tempo_inicial_pos_processamento;
    free(memoria_principal);
    free(tabela);
    fclose(arquivo);
}