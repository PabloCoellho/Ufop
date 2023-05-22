#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
    int *palavras;
    int endBloco;
    int atualizado;
    int custo;
    int cacheHit;
    time_t segundos;
} BlocoMemoria;

typedef struct {
    int endBloco;
    int endPalavra;
} Endereco;

typedef struct {
    Endereco add1;
    Endereco add2;
    Endereco add3;
    int opcode;
} Instrucao;

int tamanhoRAM = 1000;
int qdePalavrasBloco = 4;
int tamanhoCache1 = 16;
int tamanhoCache2 = 32;
int tamanhoCache3 = 64;
int tamanhoPrograma = 101;

Instrucao *memoriaInstrucoes;
BlocoMemoria *cache1;
BlocoMemoria *cache2;
BlocoMemoria *cache3;
BlocoMemoria *RAM;

//BlocoMemoria
void definiCustoMemoria(BlocoMemoria *aux, int custoAux);
void definiEndBlocoMemoria(BlocoMemoria *aux, int endBlocoAux);
void definiPalavrasMemoria(BlocoMemoria *aux, int * palavrasAux);
void definiCacheHitMemoria(BlocoMemoria *aux, int cacheHitAux);
void definiSegundosMemoria(BlocoMemoria *aux, int segundosAux);
void definiAtualizadoMemoria1(BlocoMemoria *aux);
void definiAtualizadoMemoria(BlocoMemoria *aux);
int obtemCustoMemoria(BlocoMemoria *aux);
int *obtemPalavrasMemoria(BlocoMemoria *aux);
int isAtualizadoMemoria(BlocoMemoria *aux);
void definiDesatualizadoMemoria(BlocoMemoria *aux);


//Instrucao
void definiOpcodeInstrucao(Instrucao *umaInstrucao, int opcodeAux);
void definiAdd1Instrucao(Instrucao *umaInstrucao, Endereco *add1Aux);
void definiAdd2Instrucao(Instrucao *umaInstrucao, Endereco *add2Aux);
void definiAdd3Instrucao(Instrucao *umaInstrucao, Endereco *add3Aux);
int obtemOpcodeInstrucao(Instrucao *umaInstrucao);
Endereco* obtemAdd1Instrucao(Instrucao *umaInstrucao);
Endereco* obtemAdd2Instrucao(Instrucao *umaInstrucao);
Endereco* obtemAdd3Instrucao(Instrucao *umaInstrucao);

//Endereco
void definiEndBlocoEndereco(Endereco *end, int endBlocoAux);
void definiEndPalavraEndereco(Endereco *end, int endPalavraAux);
int obtemEndBlocoEndereco(Endereco *end);
int obtemEndPalavraEndereco(Endereco *end);

//Caches - MMU
void definiCustoCache(int custoAux, int posicao, BlocoMemoria *qqCache);
void definiCacheHitCache(int cacheHitAux, int posicao, BlocoMemoria *qqCache);
void definiAtualizadoCache(int posicao, BlocoMemoria *qqCache);
void definiDesatualizadoCache(int posicao, BlocoMemoria *qqCache);
void definiSegundosCache(int segundoAux, int posicao, BlocoMemoria *qqCache);
int obtemEndBlocoCache(int posicao, BlocoMemoria *qqCache);
int obtemCacheHitMemoria(BlocoMemoria *aux);
time_t obtemSegundosCache(int posicao, BlocoMemoria *qqCache);
int isAtualizadoCache(int posicao, BlocoMemoria *qqCache);

//Funcoes
void alocaMemorias();
void desalocaMemorias();
void montarRAM();
void montarCacheVazio(int tamanho, BlocoMemoria* qqCache);
void montarInstrucoesProgramaAleatorio();
void maquina();
BlocoMemoria *buscarNasMemorias(Endereco *end);
BlocoMemoria *testaCache1Cache2(int posicaoCache1, int posicaoCache2, int posicaoCache3, int custo, int cacheHit);
int algoritmoSubstituicaoLRU(int tamanhoCache);

int main(){
    
    alocaMemorias();
    montarRAM();
    montarCacheVazio(tamanhoCache1, cache1);
    montarCacheVazio(tamanhoCache2, cache2);
    montarCacheVazio(tamanhoCache3, cache3);

    montarInstrucoesProgramaAleatorio();
    maquina();
 
    desalocaMemorias();
    
    return 0;
}

void alocaMemorias() {
    RAM = malloc(tamanhoRAM * sizeof(BlocoMemoria));
    memoriaInstrucoes = malloc(tamanhoPrograma * sizeof(Instrucao));
    cache1 = malloc(tamanhoCache1 * sizeof(BlocoMemoria));
    cache2 = malloc(tamanhoCache2 * sizeof(BlocoMemoria));
    cache3 = malloc(tamanhoCache3 * sizeof(BlocoMemoria));
}

void desalocaMemorias() {
    free(RAM);
    free(cache1);
    free(cache2);
    free(cache3);
    free(memoriaInstrucoes); 
}

void montarRAM() {
    srand(time(NULL));
    int r;
    BlocoMemoria *aux = NULL;
    int *palavrasAux = NULL;

    for (int i = 0; i < tamanhoRAM; i++)
    {
        aux = malloc(sizeof(BlocoMemoria));

        palavrasAux = malloc(qdePalavrasBloco * sizeof(int));

        for(int j = 0; j < qdePalavrasBloco; j++){
            r = rand() % 1000000; 
            palavrasAux[j] = r;
        }

        definiPalavrasMemoria(aux, palavrasAux);
        definiEndBlocoMemoria(aux, i);
    
        RAM[i] = *aux;
    }
}

void montarCacheVazio(int tamanho, BlocoMemoria *qqCache){
    time_t segundoEntradoCache;
    time(&segundoEntradoCache);
    segundoEntradoCache = segundoEntradoCache - 10;

    for(int i = 0; i < tamanho; i++){
        BlocoMemoria *aux = malloc(sizeof(BlocoMemoria));

        //Forcando cache estar vazia
        definiEndBlocoMemoria(aux, INT_MIN);
        definiSegundosMemoria(aux, segundoEntradoCache);

        qqCache[i] = *aux;
    }
}

void montarInstrucoesProgramaAleatorio(){
    Instrucao *umaInstrucao = NULL;

    srand(time(NULL));
    int r;

    for(int i = 0; i < tamanhoPrograma -1; i++){
        umaInstrucao = malloc(sizeof(Instrucao));

        r = rand() % 3;
        definiOpcodeInstrucao(umaInstrucao, r);

        Endereco *add1 = malloc(sizeof(Endereco));
        r = rand() % tamanhoRAM;
        add1->endBloco = r;
        umaInstrucao->add1.endBloco = r;
        r = rand() % qdePalavrasBloco;
        add1->endPalavra = r;
        definiAdd1Instrucao(umaInstrucao, add1);
        
        Endereco *add2 = malloc(sizeof(Endereco));
        r = rand() % tamanhoRAM;
        add2->endBloco = r;
        r = rand() % qdePalavrasBloco;
        add2->endPalavra = r;
        definiAdd2Instrucao(umaInstrucao, add2);

        Endereco *add3 = malloc(sizeof(Endereco));
        r = rand() % tamanhoRAM;
        add3->endBloco = r;
        r = rand() % qdePalavrasBloco;
        add3->endPalavra = r;
        definiAdd3Instrucao(umaInstrucao, add3);

        memoriaInstrucoes[i] = *umaInstrucao;
    }

    umaInstrucao = malloc(sizeof(Instrucao));
    definiOpcodeInstrucao(umaInstrucao, -1);

    memoriaInstrucoes[tamanhoPrograma - 1] = *umaInstrucao;
}

void maquina(){
    //Registradores
    int PC = 0;
    int opcode = INT_MAX;
    int custo = 0;
    //caches 1 e 2 Hit e miss
    int missC1 = 0;
    int hitC1 = 0;
    int missC2 = 0;
    int hitC2 = 0;
    int missC3 = 0;
    int hitC3 = 0;
    int conteudo1, conteudo2, sub, soma;
    
    while(opcode != -1){
        Instrucao *umaInstrucao = malloc(sizeof(Instrucao));
        *umaInstrucao = memoriaInstrucoes[PC];
        opcode = obtemOpcodeInstrucao(umaInstrucao);
        
        if(opcode != -1){        
            BlocoMemoria *dadoMemoriaAdd1 = malloc(sizeof(BlocoMemoria));
            dadoMemoriaAdd1 = buscarNasMemorias(obtemAdd1Instrucao(umaInstrucao));
            
            BlocoMemoria *dadoMemoriaAdd2 = malloc(sizeof(BlocoMemoria));
            dadoMemoriaAdd2 = buscarNasMemorias(obtemAdd2Instrucao(umaInstrucao));
            
            BlocoMemoria *dadoMemoriaAdd3 = malloc(sizeof(BlocoMemoria));
            dadoMemoriaAdd3 = buscarNasMemorias(obtemAdd3Instrucao(umaInstrucao));

            //incremento custos
            custo += obtemCustoMemoria(dadoMemoriaAdd1);
            custo += obtemCustoMemoria(dadoMemoriaAdd2);
            custo += obtemCustoMemoria(dadoMemoriaAdd3);

            //printf("%d\n", obtemCacheHitMemoria(dadoMemoriaAdd1));
            //printf("%d\n", obtemCacheHitMemoria(dadoMemoriaAdd2));
            //printf("%d\n", obtemCacheHitMemoria(dadoMemoriaAdd3));

            //Validando hits e misses
            if(obtemCacheHitMemoria(dadoMemoriaAdd1) == 1){
                hitC1++;
            }
            else if(obtemCacheHitMemoria(dadoMemoriaAdd1) == 2){
                missC1++;
				hitC2++;
            }else if(obtemCacheHitMemoria(dadoMemoriaAdd1) == 3){
                missC1++;
				missC2++;
                hitC3++;	
            }else if(obtemCacheHitMemoria(dadoMemoriaAdd1) == 4){
                missC1++;
				missC2++;
                missC3++;	
            }

            if(obtemCacheHitMemoria(dadoMemoriaAdd2) == 1){
                hitC1++;
            }
            else if(obtemCacheHitMemoria(dadoMemoriaAdd2) == 2){
                missC1++;
			    hitC2++;
            }else if(obtemCacheHitMemoria(dadoMemoriaAdd2) == 3){
                missC1++;
				missC2++;
                hitC3++;	
            }else if(obtemCacheHitMemoria(dadoMemoriaAdd2) == 4){
                missC1++;
				missC2++;
                missC3++;	
            }

            if(obtemCacheHitMemoria(dadoMemoriaAdd3) == 1){
                hitC1++;
            }
            else if(obtemCacheHitMemoria(dadoMemoriaAdd3) == 2){
                missC1++;
				hitC2++;
            }else if(obtemCacheHitMemoria(dadoMemoriaAdd3) == 3){
                missC1++;
				missC2++;
                hitC3++;	
            }else if(obtemCacheHitMemoria(dadoMemoriaAdd3) == 4){
                missC1++;
				missC2++;
                missC3++;	
            }

            printf("Custo ate o momento do programa em execucao: %d\n", custo);
            printf("Hits e Misses ate o momento - C1 hit: %d | C1 miss: %d | C2 hit: %d | C2 miss: %d | C3 hit: %d | C3 miss: %d\n", hitC1 , missC1, hitC2, missC2, hitC3, missC3);
            printf("-------------------- %d ---------------------\n", PC+1);

            switch (opcode)
            {   
                //Levar para cache1 dados externos
                case 0:
                    printf("Nao ha demanda por levar dados externos para as memorias\n");
                    break;
                
                case 1:
                    conteudo1 = obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra];
                    conteudo2 = obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra];
                    soma = conteudo1 + conteudo2;

                    obtemPalavrasMemoria(dadoMemoriaAdd3)[umaInstrucao->add2.endPalavra] = soma;

                    definiAtualizadoMemoria(dadoMemoriaAdd3);

                    printf("Somando %d com %d e gerando %d\n", conteudo1, conteudo2, soma);                      
                    break;

                case 2:
                    conteudo1 = obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra];
                    conteudo2 = obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra];
                    sub = conteudo1 - conteudo2;

                    obtemPalavrasMemoria(dadoMemoriaAdd3)[umaInstrucao->add2.endPalavra] = sub;

                    definiAtualizadoMemoria(dadoMemoriaAdd3);

                    printf("Subtraindo %d com %d e gerando %d\n", conteudo1, conteudo2, sub);
                    break;
            }

            PC++;
        }
    }

    float somaHit = hitC1 + hitC2 + hitC3;
    float somaMiss = missC1 + missC2 + missC3;
    float MissHit = somaHit + somaMiss;

    float C1 = hitC1 * 100;
    float total1 = C1/MissHit;

    float C2 = hitC2 * 100;
    float total2 = C2/MissHit;
    
    float C3 = hitC3 * 100;
    float total3 = C3/MissHit;
    
    float RAM4 = somaMiss * 100;
    float total4 = RAM4/MissHit;

    printf("Custo total do programa: %d\n", custo);
    printf("Hits e Misses do programa - C1 hit: %d | C1 miss: %d | C2 hit: %d | C2 miss: %d | C3 hit: %d | C3 miss: %d \n", hitC1 , missC1, hitC2, missC2, hitC3, missC3);
    printf("\n---------------------------------------------\n\n");
    printf("Custo C1: %.2f\n", total1);
    printf("Custo C2: %.2f\n", total2);
    printf("Custo C3: %.2f\n", total3);
    printf("Custo RAM: %.2f\n", total4);
}

BlocoMemoria *buscarNasMemorias(Endereco *end){
    int posicaoCache1 = obtemEndBlocoEndereco(end) % tamanhoCache1;
    int posicaoCache2 = obtemEndBlocoEndereco(end) % tamanhoCache2;
    int posicaoCache3 = obtemEndBlocoEndereco(end) % tamanhoCache3;
    int custo = 0;
    int cacheHit = 0;

    if(obtemEndBlocoCache(posicaoCache1, cache1) == obtemEndBlocoEndereco(end)){
        custo = 10;
        cacheHit = 1;

        definiCustoCache(custo, posicaoCache1, cache1);
        definiCacheHitCache(cacheHit, posicaoCache1, cache1);

        printf("Cache1\n");
        return &cache1[posicaoCache1];
    }
    else{
        if(obtemEndBlocoCache(posicaoCache2, cache2) == obtemEndBlocoEndereco(end)){
            custo = 110;
            cacheHit = 2;
            
            printf("Cache2\n");

            return testaCache1Cache2(posicaoCache1, posicaoCache2, posicaoCache3, custo, cacheHit);
        }
        else{
            if(obtemEndBlocoCache(posicaoCache3, cache3) == obtemEndBlocoEndereco(end)){
                custo = 1110;
                cacheHit = 3;

                printf("Cache3\n");

                return testaCache1Cache2(posicaoCache1, posicaoCache2, posicaoCache3, custo, cacheHit);
            }else{
                //buscar na RAM e o repassa a cache2 e depois a cache1
                custo = 11100;
                cacheHit = 4;

                if(!isAtualizadoCache(posicaoCache3, cache3)){
                    cache3[posicaoCache3] = RAM[obtemEndBlocoEndereco(end)];

                    return testaCache1Cache2(posicaoCache1, posicaoCache2, posicaoCache3, custo, cacheHit);
                }else{
                    if(!isAtualizadoCache(posicaoCache2, cache2)){
                        cache2[posicaoCache2] = RAM[obtemEndBlocoEndereco(end)];

                        return testaCache1Cache2(posicaoCache1, posicaoCache2, posicaoCache3, custo, cacheHit);
                    }else{
                        definiDesatualizadoCache(posicaoCache3, cache3);
                        RAM[obtemEndBlocoCache(posicaoCache3, cache3)] = cache3[posicaoCache3];

                        cache3[posicaoCache3] = RAM[obtemEndBlocoEndereco(end)];

                        return testaCache1Cache2(posicaoCache1, posicaoCache2, posicaoCache3, custo, cacheHit);
                    }
                }
            }
        }
    }
}

BlocoMemoria *testaCache1Cache2(int posicaoCache1, int posicaoCache2, int posicaoCache3, int custo, int cacheHit){
    if(!isAtualizadoCache(posicaoCache2, cache2)){
        if(cache2[posicaoCache2].endBloco == cache3[posicaoCache3].endBloco){
            definiDesatualizadoCache(posicaoCache3, cache3);
        }

        cache2[posicaoCache2] = cache3[posicaoCache3];

        definiCacheHitCache(cacheHit, posicaoCache2, cache2);
        definiCustoCache(custo, posicaoCache2, cache2);

        return &cache2[posicaoCache2];
    }else{
        if(!isAtualizadoCache(posicaoCache1, cache1)){
            if(cache2[posicaoCache2].endBloco == cache3[posicaoCache3].endBloco){
                definiDesatualizadoCache(posicaoCache2, cache2);
            }

            cache1[posicaoCache1] = cache2[posicaoCache2];

            definiCacheHitCache(cacheHit, posicaoCache1, cache1);
            definiCustoCache(custo, posicaoCache1, cache1);



            return &cache1[posicaoCache1];
        }
        else{
            BlocoMemoria *aux = malloc(sizeof(BlocoMemoria));
            definiDesatualizadoMemoria(aux);
            *aux = cache3[posicaoCache3];
            cache2[posicaoCache2] = cache3[posicaoCache3];
            cache3[posicaoCache2] = *aux;
        }
    }

    definiCustoCache(custo, posicaoCache2, cache2);
    definiCacheHitCache(cacheHit, posicaoCache2, cache2);

    return &cache2[posicaoCache2];
}

//BlocoMemoria
void definiCustoMemoria(BlocoMemoria *aux, int custoAux) {
    aux->custo = custoAux;
}

void definiEndBlocoMemoria(BlocoMemoria *aux, int endBlocoAux) {
    aux->endBloco = endBlocoAux;
}

void definiPalavrasMemoria(BlocoMemoria *aux, int* palavrasAux) {
    aux->palavras = palavrasAux;
}

void definiCacheHitMemoria(BlocoMemoria *aux, int cacheHitAux) {
    aux->cacheHit = cacheHitAux;
}

void definiAtualizadoMemoria1(BlocoMemoria *aux){
    aux->atualizado = 0;
}

void definiAtualizadoMemoria(BlocoMemoria *aux) {
    aux->atualizado = 1;
}

void definiDesatualizadoMemoria(BlocoMemoria *aux) {
    aux->atualizado = 0;
}

void definiSegundosMemoria(BlocoMemoria *aux, int segundosAux) {
    aux->segundos = segundosAux;
}

int obtemCustoMemoria(BlocoMemoria *aux) {
    return aux->custo;
}

int obtemCacheHitMemoria(BlocoMemoria *aux) {
    return aux->cacheHit;
}

int* obtemPalavrasMemoria(BlocoMemoria *aux) {
    return aux->palavras;
}

int obtemEndBlocoMemoria(BlocoMemoria *aux) {
    return aux->endBloco;
}

int isAtualizadoMemoria(BlocoMemoria *aux) {
    return aux->atualizado;
}

//Instrucao
void definiOpcodeInstrucao(Instrucao *umaInstrucao, int opcodeAux) {
    umaInstrucao->opcode = opcodeAux;
}

void definiAdd1Instrucao(Instrucao *umaInstrucao, Endereco *add1Aux) {
    umaInstrucao->add1 = *add1Aux;
}

void definiAdd2Instrucao(Instrucao *umaInstrucao, Endereco *add2Aux) {
    umaInstrucao->add2 = *add2Aux;
}

void definiAdd3Instrucao(Instrucao *umaInstrucao, Endereco *add3Aux) {
    umaInstrucao->add3 = *add3Aux;
}

Endereco* obtemAdd1Instrucao(Instrucao *umaInstrucao) {
    return &umaInstrucao->add1;
}

Endereco* obtemAdd2Instrucao(Instrucao *umaInstrucao) {
    return &umaInstrucao->add2;
}

Endereco* obtemAdd3Instrucao(Instrucao *umaInstrucao) {
    return &umaInstrucao->add3;
}

int obtemOpcodeInstrucao(Instrucao *umaInstrucao){
    return umaInstrucao->opcode;
}

//Endereco
void definiEndBlocoEndereco(Endereco *end, int endBlocoAux) {
    end->endBloco = endBlocoAux;
}

void definiEndPalavraEndereco(Endereco *end, int endPalavraAux) {
    end->endPalavra = endPalavraAux;
}

int obtemEndBlocoEndereco(Endereco *end) {
    return end->endBloco;
}

int obtemEndPalavraEndereco(Endereco *end) {
    return end->endPalavra;
}

//Cache --- MMU
void definiCustoCache(int custoAux, int posicao, BlocoMemoria *qqCache) {
    qqCache[posicao].custo = custoAux;
}

void definiSegundosCache(int segundoAux, int posicao, BlocoMemoria *qqCache) {
    qqCache[posicao].segundos = segundoAux;
}

void definiCacheHitCache(int cacheHitAux, int posicao, BlocoMemoria *qqCache) {
    qqCache[posicao].cacheHit = cacheHitAux;
}

void definiAtualizadoCache(int posicao, BlocoMemoria *qqCache) {
    qqCache[posicao].atualizado = 1;
}

void definiDesatualizadoCache(int posicao, BlocoMemoria *qqCache){
    qqCache[posicao].atualizado = 0;
}

int obtemEndBlocoCache(int posicao, BlocoMemoria *qqCache){
    return qqCache[posicao].endBloco;
}

time_t obtemSegundosCache(int posicao, BlocoMemoria *qqCache){
    return qqCache[posicao].segundos;
}

int isAtualizadoCache(int posicao, BlocoMemoria *qqCache) {
    return qqCache[posicao].atualizado;
}