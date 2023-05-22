#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

typedef struct
{
    int *palavras; 
    int endBloco;
    bool atualizado;
    int custo;
    int cacheHit;
    time_t segundos;
} BlocoMemoria;

typedef struct
{
    int endBloco;
    int endPalavra;
} Endereco;

typedef struct
{
    Endereco add1;
    Endereco add2;
    Endereco add3;
    int opcode;
} Instrucao;

int tamanhoRAM = 1000;
int qdePalavrasBloco = 4;
int tamanhoCache1 = 64;
int tamanhoCache2 = 128;
int tamanhoCache3 = 254;
int tamanhoPrograma = 1001;

Instrucao *memoriaInstrucoes;
BlocoMemoria *cache1;
BlocoMemoria *cache2;
BlocoMemoria *cache3;
BlocoMemoria *RAM;
FILE *arquivo;

time_t inicioPrograma;

//Operações
int soma(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3);
int subtracao (Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3);
double multiplicacao(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3);
double divisao(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3);
double potencia(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3);

//BlocoMemoria
void definiCustoMemoria(BlocoMemoria *aux, int custoAux);
void definiEndBlocoMemoria(BlocoMemoria *aux, int endBlocoAux);
void definiPalavrasMemoria(BlocoMemoria *aux, int * palavrasAux);
void definiCacheHitMemoria(BlocoMemoria *aux, int cacheHitAux);
void definiSegundosMemoria(BlocoMemoria *aux, int segundosAux);
void definiAtualizadoMemoria1(BlocoMemoria *aux);
void definiAtualizadoMemoria(BlocoMemoria *aux);
void definiDesatualizadoMemoria(BlocoMemoria *aux);
int obtemCustoMemoria(BlocoMemoria *aux);
int* obtemPalavrasMemoria(BlocoMemoria *aux);
int obtemEndBlocoMemoria(BlocoMemoria *aux);
bool isAtualizadoMemoria(BlocoMemoria *aux);


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
void definiEndBlocoCache(int endBlocoAux, int posicao, BlocoMemoria *qqCache);
void definiCustoCache(int custoAux, int posicao, BlocoMemoria *qqCache);
void definiCacheHitCache(int cacheHitAux, int posicao, BlocoMemoria *qqCache);
void definiAtualizadoCache(int posicao, BlocoMemoria *qqCache);
void definiDesatualizadoCache(int posicao, BlocoMemoria *qqCache);
void definiSegundosCache(int segundoAux, int posicao, BlocoMemoria *qqCache);
int obtemEndBlocoCache(int posicao, BlocoMemoria *qqCache);
int obtemCacheHitMemoria(BlocoMemoria *aux);
time_t obtemSegundosCache(int posicao, BlocoMemoria *qqCache);
bool isAtualizadoCache(int posicao, BlocoMemoria *qqCache);

//Funcoes
void menu();
void alocaMemorias();
void desalocaMemorias();
void montarRAM();
void montarCacheVazio(int tamanho, BlocoMemoria* qqCache);
void montarInstrucoesProgramaAleatorio();
void montarInstrucaoGerador(FILE *arquivo);
void maquina();
BlocoMemoria *buscarNasMemorias(Endereco *end);
int algoritmoSubstituicaoLRU(int tamanhoCache);
void guardarCaches(int posicaoCache, int tamanhoCache, Endereco *endAux);
void apagarCaches(int posicaoCacheX, int posicaoCacheY, int tamanhoCache);

int main(){
    FILE *arquivo = fopen("instrucoes.txt", "r");
    alocaMemorias();
    montarRAM();
    montarCacheVazio(tamanhoCache1, cache1);
    montarCacheVazio(tamanhoCache2, cache2);
    montarCacheVazio(tamanhoCache3, cache3);

    int opcao;

    do{
        menu();

        scanf("%d", &opcao);
		
		switch (opcao){
            case 1:
                montarInstrucoesProgramaAleatorio();
                maquina();
                break;
            
            case 2:
                montarInstrucaoGerador(arquivo);
                maquina();
                break;
        }

    }while (opcao != 0);

    desalocaMemorias();
    fclose(arquivo);
    return 0;
}

void menu(){
	printf("\n\nMaquina com Mapeamento Direto Aleatorio - Digite 1\n");
	printf("Maquina com Mapeamento Direto Arquivo - Digite 2\n");
	printf("Sair - Digite 0\n");
	printf("\n\nDigite um numero: ");
}

void alocaMemorias(){
    RAM = malloc(tamanhoRAM * sizeof(BlocoMemoria));
    memoriaInstrucoes = malloc(tamanhoPrograma * sizeof(Instrucao));
    cache1 = malloc(tamanhoCache1 * sizeof(BlocoMemoria));
    cache2 = malloc(tamanhoCache2 * sizeof(BlocoMemoria));
    cache3 = malloc(tamanhoCache3 * sizeof(BlocoMemoria));
}

void desalocaMemorias(){
    free(RAM);
    free(cache1);
    free(cache2);
    free(cache3);
    free(memoriaInstrucoes); 
}

void montarRAM()
{
    srand(time(NULL));
    int r;
    BlocoMemoria *aux = NULL;
    int *palavrasAux = NULL;

    for (int i = 0; i < tamanhoRAM; i++)
    {
        aux = malloc(sizeof(BlocoMemoria));

        palavrasAux = malloc(qdePalavrasBloco * sizeof(int));

        for(int j = 0; j < qdePalavrasBloco; j++){
            r = rand() % 1000000; //Restringi os numeros
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

        definiEndBlocoMemoria(aux, INT_MIN);
        definiSegundosMemoria(aux, segundoEntradoCache);

        qqCache[i] = *aux;
    }
}

void montarInstrucoesProgramaAleatorio() {
    Instrucao *umaInstrucao = NULL;

    srand(time(NULL));
    int r;

    for(int i = 0; i < tamanhoPrograma -1; i++){
        umaInstrucao = malloc(sizeof(Instrucao));

        r = rand() % 6;
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

void montarInstrucaoGerador(FILE *arquivo){
    int opcodeAux, endBlocoAux1, endPalavraAux1, endBlocoAux2, endPalavraAux2, endBlocoAux3, endPalavraAux3;

    Instrucao *umaInstrucao = NULL;

	for(int i = 0; i < tamanhoPrograma -1; i++){
		umaInstrucao = malloc(sizeof(Instrucao));

        fscanf(arquivo, "%d %d %d %d %d %d %d\n", &opcodeAux, &endBlocoAux1, &endPalavraAux1, &endBlocoAux2, &endPalavraAux2, &endBlocoAux3, &endPalavraAux3);
        
        definiOpcodeInstrucao(umaInstrucao, opcodeAux);

        Endereco *add1 = malloc(sizeof(Endereco));
        add1->endBloco = endBlocoAux1;
        add1->endPalavra = endPalavraAux1;
        definiAdd1Instrucao(umaInstrucao, add1);

        Endereco *add2 = malloc(sizeof(Endereco));
        add2->endBloco = endBlocoAux2;
        add2->endPalavra = endPalavraAux2;
        definiAdd2Instrucao(umaInstrucao, add2); 

        Endereco *add3 = malloc(sizeof(Endereco));
        add3->endBloco = endBlocoAux3;
        add3->endPalavra = endPalavraAux3;
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
    int conteudo1, conteudo2;
    double resultado;
    
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

            custo += obtemCustoMemoria(dadoMemoriaAdd1);
            custo += obtemCustoMemoria(dadoMemoriaAdd2);
            custo += obtemCustoMemoria(dadoMemoriaAdd3);

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
                case 0: 
                    printf("Nao ha demanda por levar dados externos para as memorias\n");
                    break;
                
                //SOMA
                case 1:
                    conteudo1 = obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra];
                    conteudo2 = obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra];
                    resultado = soma(umaInstrucao, conteudo1, conteudo2, dadoMemoriaAdd3);
                    printf("Somando %d com %d e gerando %.0lf\n", conteudo1, conteudo2, resultado);  
                    break;

                //SUBTRAÇÃO
                case 2:
                    conteudo1 = obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra];
                    conteudo2 = obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra];
                    resultado = subtracao(umaInstrucao, conteudo1, conteudo2, dadoMemoriaAdd3);

                    printf("Subtraindo %d com %d e gerando %.0lf\n", conteudo1, conteudo2, resultado);
                    break;

                //MULTIPLICAÇÃO
                case 3:
                    obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra] = 9;
                    obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra] = 9;

                    conteudo1 = obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra];
                    conteudo2 = obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra];
                    resultado = multiplicacao(umaInstrucao, conteudo1, conteudo2, dadoMemoriaAdd3);

                    printf("Multiplicando %d com %d e gerando %.0lf\n", conteudo1, conteudo2, resultado);
                    break;

                //DIVISÃO
                case 4:
                    obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra] = 9;
                    obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra] = 3;

                    conteudo1 = obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra];
                    conteudo2 = obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra];
                    resultado = divisao(umaInstrucao, conteudo1, conteudo2, dadoMemoriaAdd3);

                    printf("Dividindo %d com %d e gerando %.0lf\n", conteudo1, conteudo2, resultado);
                    break;


                //POTENCIA
                case 5:
                    obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra] = 8;
                    obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra] = 2;

                    conteudo1 = obtemPalavrasMemoria(dadoMemoriaAdd1)[umaInstrucao->add1.endPalavra];
                    conteudo2 = obtemPalavrasMemoria(dadoMemoriaAdd2)[umaInstrucao->add2.endPalavra];
                    
                    
                    if(conteudo1 == 0 && conteudo2 == 0)
                        printf("A potencia de base 0 e expoente 0 nao existe\n");
                    else if(conteudo2 == 0)
                        printf("A potencia de base %d e expoente 0 e: 1\n", conteudo1);
                    else if(conteudo2 == 1)
                        printf("A potencia de base %d e expoente 1 e: %d\n", conteudo1, conteudo1);
                    else {
                        resultado = potencia(umaInstrucao, conteudo2, conteudo1, dadoMemoriaAdd3);
                        printf("A potencia de base %d e expoente %d e: %.0lf\n", conteudo1, conteudo2, resultado);
                    }
               
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
    printf("\n\n\n");
    printf("Custo C1: %.2f\n", total1);
    printf("Custo C2: %.2f\n", total2);
    printf("Custo C3: %.2f\n", total3);
    printf("Custo RAM: %.2f\n", total4);
}

BlocoMemoria* buscarNasMemorias(Endereco* end){
    int custo = 0;
    int cacheHit = 0;
    time_t momentoAdicionadoCache;
    time(&momentoAdicionadoCache);

    for(int i = 0; i < tamanhoCache1; i++){
        if(obtemEndBlocoCache(i, cache1) == obtemEndBlocoEndereco(end)){
            custo = 10;
            cacheHit = 1;

            definiCustoCache(custo, i, cache1);
            definiCacheHitCache(cacheHit, i, cache1);
            definiSegundosCache(momentoAdicionadoCache, i, cache1);

            return &cache1[i];
        }

        
    }

    for(int i = 0; i < tamanhoCache2; i++){
        if(obtemEndBlocoCache(i, cache2) == obtemEndBlocoEndereco(end)){
            custo = 110;
            cacheHit = 2;

            definiCustoCache(custo, i, cache2);
            definiCacheHitCache(cacheHit, i, cache2);
            definiSegundosCache(momentoAdicionadoCache, i, cache2);

            return &cache2[i];
        }
    }

    for(int i = 0; i < tamanhoCache3; i++){
        if(obtemEndBlocoCache(i, cache3) == obtemEndBlocoEndereco(end)){
            custo = 1110;
            cacheHit = 3;

            definiCustoCache(custo, i, cache3);
            definiCacheHitCache(cacheHit, i, cache3);
            definiSegundosCache(momentoAdicionadoCache, i, cache3);

            return &cache3[i];
        }
    }

    for(int i = 0; i < tamanhoCache3; i++){
        if(!isAtualizadoCache(i, cache3)){
            custo = 11110;
            cacheHit = 4;
            cache3[i] = RAM[obtemEndBlocoEndereco(end)];

            definiCustoCache(custo, i, cache3);
            definiCacheHitCache(cacheHit, i, cache3);
            definiSegundosCache(momentoAdicionadoCache, i, cache3);

            int posicaoCache2 = algoritmoSubstituicaoLRU(tamanhoCache2);
            guardarCaches(posicaoCache2, tamanhoCache2, end);

            apagarCaches(posicaoCache2, i, tamanhoCache2);
            cache2[posicaoCache2] = cache3[i];

            return &cache3[i];
        }
    }

    for(int i = 0; i < tamanhoCache2; i++){
        if(!isAtualizadoCache(i, cache2)){ 
            custo = 11110;
            cacheHit = 4;
            cache2[i] = RAM[obtemEndBlocoEndereco(end)];

            definiCustoCache(custo, i, cache2);
            definiCacheHitCache(cacheHit, i, cache2);
            definiSegundosCache(momentoAdicionadoCache, i, cache2);

            int posicaoCache1 = algoritmoSubstituicaoLRU(tamanhoCache1);
            guardarCaches(posicaoCache1, tamanhoCache1, end);
            
            apagarCaches(posicaoCache1, i, tamanhoCache2);
            cache1[posicaoCache1] = cache2[i];

            return &cache2[i];
        }
    }

    custo = 11100;
    cacheHit = 4;

    int posicaoCache3 = algoritmoSubstituicaoLRU(tamanhoCache3);
    guardarCaches(posicaoCache3, tamanhoCache3, end);

    cache3[posicaoCache3] = RAM[obtemEndBlocoEndereco(end)];
    definiCustoCache(custo, posicaoCache3, cache3);
    definiCacheHitCache(cacheHit, posicaoCache3, cache3);
    definiSegundosCache(momentoAdicionadoCache, posicaoCache3, cache3);

    int posicaoCache2 = algoritmoSubstituicaoLRU(tamanhoCache2);
    guardarCaches(posicaoCache2, tamanhoCache2, end);

    apagarCaches(posicaoCache2, posicaoCache3, tamanhoCache3);
    cache2[posicaoCache2] = cache3[posicaoCache3];
    
    return &cache2[posicaoCache2];
}

void guardarCaches(int posicaoCache, int tamanhoCache, Endereco *endAux){
    if(tamanhoCache == tamanhoCache1){
        int posicaoCache2 = algoritmoSubstituicaoLRU(tamanhoCache2);
        int posicaoCache3 = algoritmoSubstituicaoLRU(tamanhoCache3);
        
        if(obtemEndBlocoCache(posicaoCache3, cache3) == obtemEndBlocoEndereco(endAux)){
            definiDesatualizadoCache(posicaoCache3, cache3);
            RAM[obtemEndBlocoCache(posicaoCache3, cache3)] = cache3[posicaoCache3];
            cache3[posicaoCache3] = cache2[posicaoCache2];
            cache2[posicaoCache2] = cache1[posicaoCache];
        }
    }else if(tamanhoCache == tamanhoCache2){
        int posicaoCache3 = algoritmoSubstituicaoLRU(tamanhoCache3);
        if(obtemEndBlocoCache(posicaoCache3, cache3) == obtemEndBlocoEndereco(endAux)){
            definiDesatualizadoCache(posicaoCache3, cache3);
            RAM[obtemEndBlocoCache(posicaoCache3, cache3)] = cache3[posicaoCache3];
            cache3[posicaoCache3] = cache2[posicaoCache];
        }
    }else if(tamanhoCache == tamanhoCache3){
        if(obtemEndBlocoCache(tamanhoCache, cache3) == obtemEndBlocoEndereco(endAux)){
            definiDesatualizadoCache(tamanhoCache, cache3);
            RAM[obtemEndBlocoCache(posicaoCache, cache3)] = cache3[posicaoCache];
        }
    }
}

void apagarCaches(int posicaoCacheX, int posicaoCacheY, int tamanhoCache){
    time_t tempoMaisVelha;
    time(&tempoMaisVelha);
    tempoMaisVelha = tempoMaisVelha - 2100;

    if(tamanhoCache == tamanhoCache1){
        if(obtemEndBlocoCache(posicaoCacheX, cache1) == obtemEndBlocoCache(posicaoCacheY, cache2)){
            definiDesatualizadoCache(posicaoCacheY, cache2);
            definiSegundosCache(tempoMaisVelha, posicaoCacheY, cache2);
        }    
    }else if(tamanhoCache == tamanhoCache2){
        if(obtemEndBlocoCache(posicaoCacheX, cache2) == obtemEndBlocoCache(posicaoCacheY, cache3)){
            definiDesatualizadoCache(posicaoCacheY, cache3);
            definiSegundosCache(tempoMaisVelha, posicaoCacheY, cache2);
        }    
    }
}

int algoritmoSubstituicaoLRU(int tamanhoCache){
    time_t posicaoMaisVelha;
    time(&posicaoMaisVelha);

    int posicaoCacheAux = 0;

    if(tamanhoCache == tamanhoCache1){
        for(int i = 0; i < tamanhoCache1; i++){
            if(cache1[i].segundos <= posicaoMaisVelha){
                posicaoMaisVelha = cache1[i].segundos;
                posicaoCacheAux = i;
            }
        }
    }else if(tamanhoCache == tamanhoCache2){
        for(int i = 0; i < tamanhoCache2; i++){
            if(cache2[i].segundos <= posicaoMaisVelha){
                posicaoMaisVelha = cache2[i].segundos;
                posicaoCacheAux = i;
            }
        }
    }else if(tamanhoCache == tamanhoCache3){
        for(int i = 0; i < tamanhoCache3; i++){
            if(cache3[i].segundos <= posicaoMaisVelha){
                posicaoMaisVelha = cache3[i].segundos;
                posicaoCacheAux = i;
            }
        }
    }

    return posicaoCacheAux;
}

//Operações
int soma(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3) {
    int soma = conteudo1 + conteudo2;

    obtemPalavrasMemoria(dadoMemoriaAdd3)[umaInstrucao->add2.endPalavra] = soma; //envia o resultado para memória

    definiAtualizadoMemoria(dadoMemoriaAdd3); //atualiza o endereço 3

    return soma;
}        

int subtracao (Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3)  {
    int sub = conteudo1 - conteudo2;

    obtemPalavrasMemoria(dadoMemoriaAdd3)[umaInstrucao->add2.endPalavra] = sub;

    definiAtualizadoMemoria(dadoMemoriaAdd3);  

    return sub;
}

double multiplicacao(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3) {
    double mult = 0;
    for (int i = 0; i < conteudo1; i++) { 
        mult = soma(umaInstrucao, mult, conteudo2, dadoMemoriaAdd3);
    }

    obtemPalavrasMemoria(dadoMemoriaAdd3)[umaInstrucao->add2.endPalavra] = mult;

    definiAtualizadoMemoria(dadoMemoriaAdd3);  

    return mult;
}

double divisao(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3){
    double cont = 1; 
    int divi;
    if (conteudo1 < conteudo2)
        cont = 0;

    divi = subtracao(umaInstrucao, conteudo1, conteudo2, dadoMemoriaAdd3);
    

    while (divi >= conteudo2) {
        divi = subtracao(umaInstrucao, divi, conteudo2, dadoMemoriaAdd3);
        cont = soma(umaInstrucao, cont, 1, dadoMemoriaAdd3);        
      
    }

    obtemPalavrasMemoria(dadoMemoriaAdd3)[umaInstrucao->add2.endPalavra] = divi;

    definiAtualizadoMemoria(dadoMemoriaAdd3);  

    return cont;
}

double potencia(Instrucao *umaInstrucao, int conteudo1, int conteudo2, BlocoMemoria *dadoMemoriaAdd3) {
    double pot = conteudo2;
    for (int i = 0; i < conteudo1-1; i++)
        pot = multiplicacao(umaInstrucao, pot, conteudo2, dadoMemoriaAdd3);
    
    obtemPalavrasMemoria(dadoMemoriaAdd3)[umaInstrucao->add2.endPalavra] = pot;

    definiAtualizadoMemoria(dadoMemoriaAdd3);  

    return pot;
}

//BlocoMemoria
void definiCustoMemoria(BlocoMemoria *aux, int custoAux)
{
    aux->custo = custoAux;
}

void definiEndBlocoMemoria(BlocoMemoria *aux, int endBlocoAux)
{
    aux->endBloco = endBlocoAux;
}

void definiPalavrasMemoria(BlocoMemoria *aux, int* palavrasAux)
{
    aux->palavras = palavrasAux;
}

void definiCacheHitMemoria(BlocoMemoria *aux, int cacheHitAux)
{
    aux->cacheHit = cacheHitAux;
}

void definiAtualizadoMemoria1(BlocoMemoria *aux){
    aux->atualizado = false;
}

void definiAtualizadoMemoria(BlocoMemoria *aux)
{
    aux->atualizado = true;
}

void definiDesatualizadoMemoria(BlocoMemoria *aux)
{
    aux->atualizado = false;
}

void definiSegundosMemoria(BlocoMemoria *aux, int segundosAux)
{
    aux->segundos = segundosAux;
}

int obtemCustoMemoria(BlocoMemoria *aux)
{
    return aux->custo;
}

int obtemCacheHitMemoria(BlocoMemoria *aux)
{
    return aux->cacheHit;
}

int* obtemPalavrasMemoria(BlocoMemoria *aux)
{
    return aux->palavras;
}

int obtemEndBlocoMemoria(BlocoMemoria *aux)
{
    return aux->endBloco;
}

bool isAtualizadoMemoria(BlocoMemoria *aux)
{
    return aux->atualizado;
}

//Instrucao
void definiOpcodeInstrucao(Instrucao *umaInstrucao, int opcodeAux)
{
    umaInstrucao->opcode = opcodeAux;
}

void definiAdd1Instrucao(Instrucao *umaInstrucao, Endereco *add1Aux)
{
    umaInstrucao->add1 = *add1Aux;
}

void definiAdd2Instrucao(Instrucao *umaInstrucao, Endereco *add2Aux)
{
    umaInstrucao->add2 = *add2Aux;
}

void definiAdd3Instrucao(Instrucao *umaInstrucao, Endereco *add3Aux)
{
    umaInstrucao->add3 = *add3Aux;
}

Endereco* obtemAdd1Instrucao(Instrucao *umaInstrucao)
{
    return &umaInstrucao->add1;
}

Endereco* obtemAdd2Instrucao(Instrucao *umaInstrucao)
{
    return &umaInstrucao->add2;
}

Endereco* obtemAdd3Instrucao(Instrucao *umaInstrucao)
{
    return &umaInstrucao->add3;
}

int obtemOpcodeInstrucao(Instrucao *umaInstrucao){
    return umaInstrucao->opcode;
}

//Endereco
void definiEndBlocoEndereco(Endereco *end, int endBlocoAux)
{
    end->endBloco = endBlocoAux;
}

void definiEndPalavraEndereco(Endereco *end, int endPalavraAux)
{
    end->endPalavra = endPalavraAux;
}

int obtemEndBlocoEndereco(Endereco *end)
{
    return end->endBloco;
}

int obtemEndPalavraEndereco(Endereco *end)
{
    return end->endPalavra;
}

//Cache --- MMU
void definiEndBlocoCache(int endBlocoAux, int posicao, BlocoMemoria *qqCache){
    qqCache[posicao].endBloco = endBlocoAux;
}

void definiCustoCache(int custoAux, int posicao, BlocoMemoria *qqCache)
{
    qqCache[posicao].custo = custoAux;
}

void definiSegundosCache(int segundoAux, int posicao, BlocoMemoria *qqCache)
{
    qqCache[posicao].segundos = segundoAux;
}

void definiCacheHitCache(int cacheHitAux, int posicao, BlocoMemoria *qqCache)
{
    qqCache[posicao].cacheHit = cacheHitAux;
}

void definiAtualizadoCache(int posicao, BlocoMemoria *qqCache)
{
    qqCache[posicao].atualizado = true;
}

void definiDesatualizadoCache(int posicao, BlocoMemoria *qqCache){
    qqCache[posicao].atualizado = false;
}

int obtemEndBlocoCache(int posicao, BlocoMemoria *qqCache){
    return qqCache[posicao].endBloco;
}

time_t obtemSegundosCache(int posicao, BlocoMemoria *qqCache){
    return qqCache[posicao].segundos;
}

bool isAtualizadoCache(int posicao, BlocoMemoria *qqCache)
{
    return qqCache[posicao].atualizado;
}
