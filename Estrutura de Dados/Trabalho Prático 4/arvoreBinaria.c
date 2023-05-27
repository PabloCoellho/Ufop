#include <stdio.h>
#include <time.h>
#include "arvoreBinaria.h"


int InsereArvoreBinaria(FILE *arv, TipoItem *item, int posicao, Analise **analise){
    if (posicao == 0){
        //Arvore vazia
        No no;
        no = CriaNoArvoreBinaria(item);
        fseek(arv, 0, SEEK_SET);
        fwrite(&no, sizeof(No), 1, arv);
        (*analise)->transferencia_pre_processamento++;
        return 1;
    }else{
        No no;
        No raiz;
        long deslocamento;
        int posicao_no_pai = 0;

        no = CriaNoArvoreBinaria(item); //Cria o novo nó a ser inserido

        fseek(arv, 0, SEEK_SET);                //Retorna para o inicio
        fread(&raiz, sizeof(No), 1, arv); //Lê a raiz
        (*analise)->transferencia_pre_processamento++;

        bool controlaLaco = true;

        while (controlaLaco){
            //Procurar o item pai
            if (item->chave < raiz.item.chave){
                (*analise)->comparacao_pre_processamento++;
                //Insere à esquerda
                if (raiz.esq != -1){
                    //O node contem filho a esquerda
                    posicao_no_pai = raiz.esq;
                    deslocamento = raiz.esq * sizeof(No);

                    fseek(arv, deslocamento, SEEK_SET); //Desaloca o ponteiro do arquivo para o filho a esquerda
                    fread(&raiz, sizeof(No), 1, arv); //Lê o node a esquerda para retornar o loop
                    (*analise)->transferencia_pre_processamento++;
                }else{
                    raiz.esq = posicao;
                    deslocamento = posicao_no_pai * sizeof(No);
                    fseek(arv, deslocamento, SEEK_SET);            //Volta para a posicao do item pai
                    fwrite(&raiz, sizeof(No), 1, arv); //Reescreve a linha do item pai
                    (*analise)->transferencia_pre_processamento++;

                    deslocamento = posicao * sizeof(No);
                    fseek(arv, deslocamento, SEEK_SET);
                    fwrite(&no, sizeof(No), 1, arv); //Registra o nó no arquivo
                    (*analise)->transferencia_pre_processamento++;
                    return 1;
                }
            }else if (item->chave > raiz.item.chave){
                (*analise)->comparacao_pre_processamento++;
                //Insere à direita, não consisera itens iguais
                if (raiz.dir != -1){
                    //O node contem filho a esquerda
                    posicao_no_pai = raiz.dir;
                    deslocamento = raiz.dir * sizeof(No);
                    fseek(arv, deslocamento, SEEK_SET);           //Desaloca o ponteiro do arquivo para o filho a esquerda
                    fread(&raiz, sizeof(No), 1, arv); //Lê o node a esquerda para retornar o
                    (*analise)->transferencia_pre_processamento++;
                }else{
                    raiz.dir = posicao;
                    deslocamento = posicao_no_pai * sizeof(No);
                    fseek(arv, deslocamento, SEEK_SET);            //Volta para a posicao do item pai
                    fwrite(&raiz, sizeof(No), 1, arv); //Reescreve a linha do item
                    (*analise)->transferencia_pre_processamento++;

                    deslocamento = posicao * sizeof(No);
                    fseek(arv, deslocamento, SEEK_SET);
                    fwrite(&no, sizeof(No), 1, arv); //Registra o nó no arquivo
                    (*analise)->transferencia_pre_processamento++;
                    return 1;
                }
            }else // itens iguais
                return 0;
        }
    }
}

int PesquisaArvoreBinaria(FILE *arv, TipoItem *x, Analise **analise){
    No no;
    if (!fread(&no, sizeof(No), 1, arv))
    {
        (*analise)->transferencia_pos_processamento++;
        return 0;
    }

    long int deslocamento;
    int filho_esquerda = 1, filho_direita = 1;

    while (1)
    {
        if (x->chave < no.item.chave && filho_esquerda != -1)
        {
            (*analise)->comparacao_pos_processamento++;
            deslocamento = no.esq * sizeof(No);
            fseek(arv, deslocamento, SEEK_SET);
            fread(&no, sizeof(No), 1, arv); //Lê o filho a esquerda
            (*analise)->transferencia_pos_processamento++;
            filho_esquerda = no.esq;
            filho_direita = no.dir;
        }else if (x->chave > no.item.chave && filho_direita != -1){
            (*analise)->comparacao_pos_processamento++;
            deslocamento = no.dir * sizeof(No);
            fseek(arv, deslocamento, SEEK_SET);
            fread(&no, sizeof(No), 1, arv); //Lê o filho a direita
            (*analise)->transferencia_pos_processamento++;
            filho_esquerda = no.esq;
            filho_direita = no.dir;
        }else if (x->chave == no.item.chave){
            (*analise)->comparacao_pos_processamento++;
            // Analisando folhas
            *x = no.item;
            return 1;
        }else{
            (*analise)->comparacao_pos_processamento++;
            return 0;
        }
    }
}

No CriaNoArvoreBinaria(TipoItem *item){
    No aux;
    aux.item = *item;
    aux.esq = -1;
    aux.dir = -1;
    return aux;
}

int CriaArvoreBinariaExterna(int quantidade, Analise **analise) {
    //TipoItem *item = dados_cria_array(QTD_DADOS);
    TipoItem *item = malloc(QUANTIDADE_ITEM_ARVORE_BINARIA * sizeof(TipoItem));
    FILE *arvore = fopen("arquivoBinarioExterno.bin", "w+b");
    FILE *arquivo = fopen("geradorArquivo.bin", "rb");

    if (arvore == NULL || arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    //Cria a arvore no aquivo
    int contador = 0;
    int inseriu;

    (*analise)->tempo_inicial_pre_processamento = clock();

    while (fread(item, sizeof(TipoItem), QUANTIDADE_ITEM_ARVORE_BINARIA, arquivo)) { //Pega n itens do arquivo
        (*analise)->transferencia_pre_processamento++;
        for (int i = 0; i < 15; i++) { //Percorre o array de n itens para inserir na arvore
            inseriu = InsereArvoreBinaria(arvore, &item[i], contador, analise);
            if (!inseriu)
                contador--; //não foi possivel inserir, a posição no arvore nn fica vazia
            contador++;
        }
    }

    (*analise)->tempo_final_pre_processamento = clock() - (*analise)->tempo_inicial_pre_processamento;

    fclose(arvore);
    fclose(arquivo);

    //Pesquisa
    TipoItem x;
    arvore = fopen("arquivoBinarioExterno.bin", "rb");
    //printf("Digite a chave de pesquisa: ");
    //scanf("%lld", &x);
    TipoItem x_registro;
    x_registro.chave = (*analise)->chave.chave;
    clock_t tempo_final_pre_processamento;
    clock_t tempo_inicial_pos_processamento;
    long long int *vetor = criaChavesAleatorias(quantidade);
    int pesquisa;
    if ((*analise)->chave.chave != -1) {
        x.chave = (*analise)->chave.chave;
        pesquisa = PesquisaArvoreBinaria(arvore, &x_registro, analise);
        if (pesquisa == 1)
            printf("Chave %lld encontrada com sucesso\n", x_registro.chave);
        else
            printf("Chave nao encontrada\n");
    } else {
        for (int i = 0; i < 10; i++) {
            x.chave = vetor[i];
            pesquisa = PesquisaArvoreBinaria(arvore, &x_registro, analise);
            if (pesquisa == 1)
                printf("Chave %lld encontrada com sucesso\n", x_registro.chave);
            else
                printf("Chave nao encontrada\n");
        }
        fclose(arvore);
        (*analise)->tempo_final_pos_processamento = clock() - (*analise)->tempo_inicial_pos_processamento;
        return pesquisa;
    }
    return pesquisa;
}