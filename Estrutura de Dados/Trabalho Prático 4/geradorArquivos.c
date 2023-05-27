#include <time.h>
#include "arvoreBinaria.h"
#include <string.h>
#include <stdlib.h>

void lerGeradorArquivo(){
    FILE *arquivo ;//= fopen("geradorArquivoAleatorio.bin", "rb");
    TipoItem item;

    if((arquivo = fopen("geradorArquivo.bin", "rb")) == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    while(fread(&item, sizeof(item), 1, arquivo) == 1) {
        printf("chave: %lld\n", item.chave);
        printf("Dado1: %ld\n", item.dado1);
        printf("Dado2: %s\n", item.dado2);
        printf("Dado3: %s\n\n", item.dado3);
    }

    fclose(arquivo);
}

void criaGeradorArquivoCrescente(int quantidade_arquivo){
    FILE *arquivo = fopen("geradorArquivo.bin", "wb");
    TipoItem item;

    for(int i = 0; i < quantidade_arquivo; i++){
        item.chave = i;
        item.dado1 = i+1000;
        strcpy(item.dado2, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vel consequat velits");
        strcpy(item.dado3, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vel consequat velit. Etiam iaculis consectetur pulvinar. Mauris eros nisl, ultricies ac aliquam vel, condimentum nec nibh.");
        fwrite(&item, sizeof(item), 1, arquivo);
    }
    fclose(arquivo);
    //lerGeradorArquivo();
}

void criaGeradorArquivoDecrescente(int quantidade_arquivo){
    FILE *arquivo = fopen("geradorArquivo.bin", "wb");
    TipoItem item;

    for(int i = quantidade_arquivo; i >= 0; i--){
        item.chave = i;
        item.dado1 = i+1000;
        strcpy(item.dado2, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vel consequat velits");
        strcpy(item.dado3, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vel consequat velit. Etiam iaculis consectetur pulvinar. Mauris eros nisl, ultricies ac aliquam vel, condimentum nec nibh.");
        fwrite(&item, sizeof(item), 1, arquivo);
    }
    fclose(arquivo);
    lerGeradorArquivo();
}

//Funcao responsavel por ler um arquivo e verificar caso uma chave x esta presente no arquivo
//Retorna 0 caso nao, e 1 caso ja tenha
int pesquisaGerador(long long int troca){
    FILE *arquivo2 = fopen("geradorArquivo2.bin", "rb");
    TipoItem item;
    int achou = 0;

    if(arquivo2 == NULL) {
        fclose(arquivo2);
        return 0;
    }

    while(fread(&item, sizeof(item), 1, arquivo2) == 1){
        if(item.chave == troca){
            fclose(arquivo2);
            return 1;
        }
    }

    fclose(arquivo2);
    return achou;

}

//Funcao responsavel por criar um arquivo com dados aleatorios e sem repeticao de chaves
/*void criaGeradorArquivoAleatorio(int quantidade_arquivo){
    //cria um arquivo com dados crescentes que servira como base para a geracao dos dados aleatorios
    criaGeradorArquivoCrescente(quantidade_arquivo);

    FILE *arquivo = fopen("geradorArquivo.bin", "rb");
    TipoItem item, temporario, lixo_item;
    long long int troca, posicao_atual, desloca_ponteiro_arquivo, achou, lixo = quantidade_arquivo + 1, controle_repeticao = 0;
    FILE *arquivo2;

    while(fread(&item, sizeof(item), 1, arquivo) == 1) {
        posicao_atual = ftello64(arquivo);

        //while responsavel por gerar um numero aleatorio sem repeticao para o primeiro elemento
        do {
            troca = rand() % quantidade_arquivo;
            achou = pesquisaGerador(troca);
        } while (achou != 0);

        //Desloca no arquivo base crescente ate a posicao gerada aleatoria
        desloca_ponteiro_arquivo = troca * sizeof(TipoItem);
        fseeko64(arquivo, desloca_ponteiro_arquivo, SEEK_SET);
        fread(&temporario, sizeof(temporario), 1, arquivo);

        arquivo2 = fopen("geradorArquivo2.bin", "a+b");
        fwrite(&temporario, sizeof(temporario), 1, arquivo2);
        fclose(arquivo2);

        //Condicoes responsavel pelo controle das insercoes no arquivo
        //Nao acesar memoria indevida
        controle_repeticao++;
        if(controle_repeticao == quantidade_arquivo)
            break;

        //Condicao responsavel por tratar as chaves iguais do segundo elemento
        //Caso igual gerar um item "lixo" e colocar no arquivo
        if(!pesquisaGerador(item.chave)) {
            arquivo2 = fopen("geradorArquivo2.bin", "a+b");
            fwrite(&item, sizeof(item), 1, arquivo2);
            fclose(arquivo2);
        }else{
            arquivo2 = fopen("geradorArquivo2.bin", "a+b");

            lixo_item.chave = lixo;
            lixo_item.dado1 = (long) lixo + 100;
            strcpy(lixo_item.dado2, "LGBT - Levanta Gay Bora Trabalhar");
            strcpy(lixo_item.dado3, "Se Gostou bate palmas, se nao gostou paciencia!");
            fwrite(&lixo_item, sizeof(lixo_item), 1, arquivo2);

            fclose(arquivo2);
        }

        lixo += 2;
        fseeko64(arquivo, posicao_atual, SEEK_SET);

        controle_repeticao++;
        if(controle_repeticao == quantidade_arquivo)
            break;
    }

    fclose(arquivo);

    remove("C:\\Users\\anton\\CLionProjects\\PesquisaExterna\\cmake-build-debug\\geradorArquivo.bin");
    rename("C:\\Users\\anton\\CLionProjects\\PesquisaExterna\\cmake-build-debug\\geradorArquivo2.bin", "C:\\Users\\anton\\CLionProjects\\PesquisaExterna\\cmake-build-debug\\geradorArquivo.bin");

    //lerGeradorArquivo();
}*/

void criaGeradorArquivoAleatorio(long long int quantidade_arquivo) {
    FILE *arquivo = fopen("geradorArquivo.bin", "wb");

    TipoItem item;
    long long int *vetor = (long long int *) malloc (quantidade_arquivo * sizeof(long long int));
    srand(time(NULL));

    for (long long int i = 0; i < quantidade_arquivo; i++)
        vetor[i] = 0;

    for (long long int i = 0; i < quantidade_arquivo; i++){

        long long int aux = rand() % quantidade_arquivo;

        if (vetor[aux] == -1) {
            i--;
        }

        else {
            item.chave = aux+1;
            item.dado1 = aux+1001;
            strcpy(item.dado2, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vel consequat velits");
            strcpy(item.dado3, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut vel consequat velit. Etiam iaculis consectetur pulvinar. Mauris eros nisl, ultricies ac aliquam vel, condimentum nec nibh.");
            fwrite(&item, sizeof(item), 1, arquivo);
            vetor[aux] = -1;

        }
    }

    free(vetor);
    fclose(arquivo);
}

void buscaIguaisArquivo(){
    FILE *arquivo = fopen("geradorArquivoAleatorio.bin", "rb");
    TipoItem item;
    int x = 4;
    int quantidade_iguais_x = 0;

    if((arquivo = fopen("geradorArquivoAleatorio.bin", "rb")) == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    while(fread(&item, sizeof(item), 1, arquivo) == 1) {
        if(item.chave == x)
            quantidade_iguais_x++;
    }

    printf("\n*************** Quantidade de Iguais a %d = %d\n", x, quantidade_iguais_x);
    fclose(arquivo);
}

long long int* criaChavesAleatorias(long long int quantidade_arquivo){
    FILE *arquivo = fopen("geradorArquivo.bin", "rb");
    TipoItem item;
    long long int desloca_ponteiro_arquivo;
    long long int *vetor = (long long int *) malloc (10 * sizeof(long long int));

    for (long long int i = 0; i < 10; i++)
        vetor[i] = -1;

    //srand(time(NULL));

    bool para = true;
    bool insere = true;
    //int i = 0;
    int contador = 0;
    long long int aux;
    while(para){
        aux = rand() % quantidade_arquivo;
        desloca_ponteiro_arquivo = aux * sizeof(TipoItem);
        fseeko64(arquivo, desloca_ponteiro_arquivo, SEEK_SET);
        fread(&item, sizeof(item), 1, arquivo);

        for(long long int i = 0; i < 10; i++){
            if(vetor[i] == item.chave)
                insere = false;
        }

        if(insere) {
            vetor[contador] = item.chave;
            contador++;
        }

        if(contador == 10)
            para = false;

        insere = true;
    }

    fclose(arquivo);
    return vetor;
}

void lerVetor (long long int *vetor){
    for (long long int i = 0; i < 10; i++)
        printf("Vetor[%lld]: %lld\n", i, vetor[i]);
}