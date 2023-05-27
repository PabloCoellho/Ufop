#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

typedef struct{
    int palavras[4];
    int endBloco;
    int atualizado;
    int numAcessos;
    int custo;
    int cacheHit;
} BlocoMemoria;

typedef struct{
    int endBloco;
    int endPalavra;
} Endereco;

typedef struct{
    Endereco add1;
    Endereco add2;
    Endereco add3;
    int opcode;
} Instrucao;

typedef struct{
    int hitC1;
    int hitC2;
    int hitC3;
    int hitRAM;
    int hitHD;
    int missC1;
    int missC2;
    int missC3;
    int missRAM;
    int custo;
}  Taxas;

void montarHD();
void montarMemoriaVazia(BlocoMemoria*, int);
void maquina(Instrucao*, BlocoMemoria*, BlocoMemoria*, BlocoMemoria*, BlocoMemoria*, char*, int, Taxas*);
void montarInstrucaoGerador(Instrucao*, char*, int);
BlocoMemoria trocaHD(BlocoMemoria*, int, int);
BlocoMemoria MMU(Endereco, BlocoMemoria*, BlocoMemoria*, BlocoMemoria*, BlocoMemoria*);
BlocoMemoria trocaMemoria(int, int, BlocoMemoria*, BlocoMemoria*, int);
int procuraEndereco(BlocoMemoria*, Endereco, int);
int LFU(int, BlocoMemoria*);
BlocoMemoria *alocarVetorMemoria(int tamanho);
Instrucao *alocarVetorInstrucao(int tamanho);
Endereco *alocarVetorEndereco(int tamanho);
Taxas* criarTaxas();

#define tamanhoHD 30000
#define tamanhoRAM 1000
#define tamanhoCache1 16
#define tamanhoCache2 32
#define tamanhoCache3 64
#define tamanhoPrograma 10001 
#define tamanhoProgramaTI 101 
#define qntPalavrasBloco 4


int main(){
    srand(time(NULL));

    char nome[30] = "programa.txt";
    int PC = 0;
    Taxas* taxas = malloc(sizeof(Taxas));
    Instrucao* memoriaInstrucoes = malloc(tamanhoPrograma * sizeof(Instrucao));

    BlocoMemoria* RAM = malloc(tamanhoRAM * sizeof(BlocoMemoria));
    BlocoMemoria* cache1 = malloc(tamanhoCache1 * sizeof(BlocoMemoria));
    BlocoMemoria* cache2 = malloc(tamanhoCache2 * sizeof(BlocoMemoria));
    BlocoMemoria* cache3 = malloc(tamanhoCache3 * sizeof(BlocoMemoria));

    montarHD();

    montarMemoriaVazia(RAM, tamanhoRAM);
    montarMemoriaVazia(cache1, tamanhoCache1);
    montarMemoriaVazia(cache2, tamanhoCache2);
    montarMemoriaVazia(cache3, tamanhoCache3);

    taxas = criarTaxas();

    montarInstrucaoGerador(memoriaInstrucoes, nome, tamanhoPrograma);
    maquina(memoriaInstrucoes, RAM, cache1, cache2, cache3, nome, PC, taxas);
    
    free(memoriaInstrucoes);
    free(RAM);
    free(cache1);
    free(cache2);
    free(cache3);
    free(taxas);

    return 0;
}

void montarMemoriaVazia(BlocoMemoria* cache, int tamanho){ 
    for(int i=0; i<tamanho; i++){
        cache[i].endBloco = -1;
        cache[i].numAcessos = 0; 
        cache[i].atualizado = 0;
    }
}

void maquina(Instrucao* memoriaInstrucoes, BlocoMemoria* RAM, BlocoMemoria* cache1, BlocoMemoria* cache2, BlocoMemoria* cache3, char* nome, int PC, Taxas* taxas){
    int opCode = INT_MAX;

    while(opCode!=-1){
        Instrucao umaInstrucao = memoriaInstrucoes[PC];
        opCode = umaInstrucao.opcode;
        
        if(opCode!=-1){
            BlocoMemoria dadoMemoriaAdd1 = MMU(umaInstrucao.add1, RAM, cache1, cache2, cache3); 
            BlocoMemoria dadoMemoriaAdd2 = MMU(umaInstrucao.add2, RAM, cache1, cache2, cache3);
            BlocoMemoria dadoMemoriaAdd3 = MMU(umaInstrucao.add3, RAM, cache1, cache2, cache3);

            taxas->custo += dadoMemoriaAdd1.custo; 
            taxas->custo += dadoMemoriaAdd2.custo;
            taxas->custo += dadoMemoriaAdd3.custo;


            if(dadoMemoriaAdd1.cacheHit == 1){ 
                taxas->hitC1++;
            }
            else if(dadoMemoriaAdd1.cacheHit == 2){
                taxas->hitC2++;
                taxas->missC1++;
            }
            else if(dadoMemoriaAdd1.cacheHit == 3){
                taxas->hitC3++;
                taxas->missC1++;
                taxas->missC2++;
            }
            else if(dadoMemoriaAdd1.cacheHit == 4){
                taxas->hitRAM++;
                taxas->missC1++;
                taxas->missC2++;
                taxas->missC3++;
            }
            else if(dadoMemoriaAdd1.cacheHit == 5){
                taxas->hitHD++;
                taxas->missC1++;
                taxas->missC2++;
                taxas->missC3++;
                taxas->missRAM++;
            }
            if(dadoMemoriaAdd2.cacheHit == 1){
                taxas->hitC1++;
            }
            else if(dadoMemoriaAdd2.cacheHit == 2){
                taxas->hitC2++;
                taxas->missC1++;
            }
            else if(dadoMemoriaAdd2.cacheHit == 3){
                taxas->hitC3++;
                taxas->missC1++;
                taxas->missC2++;
            }
            else if(dadoMemoriaAdd2.cacheHit == 4){
                taxas->hitRAM++;
                taxas->missC1++;
                taxas->missC2++;
                taxas->missC3++;
            }
            else if(dadoMemoriaAdd2.cacheHit == 5){
                taxas->hitHD++;
                taxas->missC1++;
                taxas->missC2++;
                taxas->missC3++;
                taxas->missRAM++;
            }
            if(dadoMemoriaAdd3.cacheHit == 1){
                taxas->hitC1++;
            }
            else if(dadoMemoriaAdd3.cacheHit == 2){
                taxas->hitC2++;
                taxas->missC1++;
            }
            else if(dadoMemoriaAdd3.cacheHit == 3){
                taxas->hitC3++;
                taxas->missC1++;
                taxas->missC2++;
            }
            else if(dadoMemoriaAdd3.cacheHit == 4){
                taxas->hitRAM++;
                taxas->missC1++;
                taxas->missC2++;
                taxas->missC3++;
            }
            else if(dadoMemoriaAdd3.cacheHit == 5){
                taxas->hitHD++;
                taxas->missC1++;
                taxas->missC2++;
                taxas->missC3++;
                taxas->missRAM++;
            }

            printf("Custo até o momento do programa em execução: %d\n", taxas->custo);
            printf("Hits e Misses até o momento:\nC1 hit: %d | C1 miss: %d | C2 hit: %d | C2 miss: %d | C3 hit: %d | C3 miss: %d | RAM hit: %d | RAM miss: %d |  HD hit: %d |\n", taxas->hitC1, taxas->missC1, taxas->hitC2, taxas->missC2, taxas->hitC3, taxas->missC3, taxas->hitRAM, taxas->missRAM, taxas->hitHD);

            switch(opCode){
                case 0:{
                    printf("Não há demanda por levar dados externos para as memórias\n");
                    if(strcmp(nome, "programa.txt") == 0){
                        int chance = rand()%6;
                        if(chance == 0){
                            printf("Interrupção aleatória\n");
                            char nome[30] = "tratador.txt";
                            montarInstrucaoGerador(memoriaInstrucoes, nome, tamanhoProgramaTI);
                            maquina(memoriaInstrucoes, RAM, cache1, cache2, cache3, nome, 0, taxas);
                            printf("Fim da interrupção\n");
                            char nome2[30] = "programa.txt";
                            montarInstrucaoGerador(memoriaInstrucoes, nome2, tamanhoPrograma);
                        }
                        else if(chance == 1){
                            printf("Ocorreu uma ação no mouse\n");
                            char nome[30] = "mouse.txt"; 
                            montarInstrucaoGerador(memoriaInstrucoes, nome, tamanhoProgramaTI);
                            maquina(memoriaInstrucoes, RAM, cache1, cache2, cache3, nome, 0, taxas);
                            printf("Fim da interrupção no mouse\n");
                            char nome2[30] = "programa.txt";
                            montarInstrucaoGerador(memoriaInstrucoes, nome2, tamanhoPrograma);
                        }
                        else if(chance == 2){
                            printf("Ocorreu uma ação no teclado\n");
                            char nome[30] = "teclado.txt";
                            montarInstrucaoGerador(memoriaInstrucoes, nome, tamanhoProgramaTI);
                            maquina(memoriaInstrucoes, RAM, cache1, cache2, cache3, nome, 0, taxas);
                            printf("Fim da interrupção no teclado\n");
                            char nome2[30] = "programa.txt";
                            montarInstrucaoGerador(memoriaInstrucoes, nome2, tamanhoPrograma);
                        }
                    }
                    break; 
                }
                case 1:{
                    int conteudo1 = dadoMemoriaAdd1.palavras[umaInstrucao.add1.endPalavra];
                    int conteudo2 = dadoMemoriaAdd2.palavras[umaInstrucao.add2.endPalavra];
                    int  soma = conteudo1+conteudo2;

                    dadoMemoriaAdd3.palavras[umaInstrucao.add3.endPalavra] = soma;
                    dadoMemoriaAdd3.atualizado = 1;

                    printf("Somando %d com %d e gerando: %d\n", conteudo1, conteudo2, soma);
                    break;
                }
                case 2:{
                    int conteudo1 = dadoMemoriaAdd1.palavras[umaInstrucao.add1.endPalavra];
                    int conteudo2 = dadoMemoriaAdd2.palavras[umaInstrucao.add2.endPalavra];
                    int  sub = conteudo1-conteudo2;

                    dadoMemoriaAdd3.palavras[umaInstrucao.add3.endPalavra] = sub;
                    dadoMemoriaAdd3.atualizado = 1;

                    printf("Subtraindo %d com %d e gerando: %d\n", conteudo1, conteudo2, sub);
                    break;
                }
            }
        }
        PC++;
    }
   
    
    float somaHit = taxas->hitC1 + taxas->hitC2 + taxas->hitC3 + taxas->hitRAM + taxas->hitHD;
    float somaMiss = taxas->missC1 + taxas->missC2 + taxas->missC3 + taxas->missRAM;
    float MissHit = somaHit + somaMiss;

    float C1 = taxas->hitC1 * 100;
    float total1 = C1/MissHit;

    float C2 = taxas->hitC2 * 100;
    float total2 = C2/MissHit;
    
    float C3 = taxas->hitC3 * 100;
    float total3 = C3/MissHit;

    float C4 = taxas->hitRAM * 100;
    float totalram = C4/MissHit;
    
    float HD = somaMiss * 100;
    float total4 = HD/MissHit;

    
    printf("\n\n");
    printf("Custo C1: %.2f\n", total1);
    printf("Custo C2: %.2f\n", total2);
    printf("Custo C3: %.2f\n", total3);
    printf("Custo RAM: %.2f\n", total4);
    printf("Custo HD: %.2f\n", totalram);
}

BlocoMemoria MMU(Endereco endereco, BlocoMemoria* RAM, BlocoMemoria* cache1, BlocoMemoria* cache2, BlocoMemoria* cache3){
    

    int posicaoCache1, posicaoCache2, posicaoCache3, posicaoRAM, custo = 0;

    posicaoCache1 = procuraEndereco(cache1, endereco, tamanhoCache1);

    if(posicaoCache1!=-1){
        custo+=10;
        cache1[posicaoCache1].custo = custo;
        cache1[posicaoCache1].cacheHit = 1;

        return cache1[posicaoCache1];
    }
    else{
        posicaoCache2 = procuraEndereco(cache2, endereco, tamanhoCache2);

        if(posicaoCache2!=-1){
            custo+=110;
            posicaoCache1 = LFU(tamanhoCache1, cache1);
            
            cache1[posicaoCache1] = trocaMemoria(posicaoCache1, posicaoCache2, cache1, cache2, custo);
    
            cache1[posicaoCache1].cacheHit = 2;

            return cache1[posicaoCache1];
        }
        else{
            posicaoCache3 = procuraEndereco(cache3, endereco, tamanhoCache3);

            if(posicaoCache3!=-1){
                custo+=310;
                posicaoCache2 = LFU(tamanhoCache2, cache2);
                cache2[posicaoCache2] = trocaMemoria(posicaoCache2, posicaoCache3, cache2, cache3, custo);

                posicaoCache1 = LFU(tamanhoCache1, cache1);
                cache1[posicaoCache1] = trocaMemoria(posicaoCache1, posicaoCache2, cache1, cache2, custo);
 
                cache1[posicaoCache1].cacheHit = 3;

                return cache1[posicaoCache1]; 
            }
            else{
                custo+=1310;
                posicaoRAM = procuraEndereco(RAM, endereco, tamanhoRAM);

                if(posicaoRAM!=-1){
                    posicaoCache3 = LFU(tamanhoCache3, cache3);
                    cache3[posicaoCache3] = trocaMemoria(posicaoCache3, posicaoRAM, cache3, RAM, custo);
                    posicaoCache2 = LFU(tamanhoCache2, cache2);
                    cache2[posicaoCache2] = trocaMemoria(posicaoCache2, posicaoCache3, cache2, cache3, custo);
                        
                    posicaoCache1 = LFU(tamanhoCache1, cache1);
                    cache1[posicaoCache1] = trocaMemoria(posicaoCache1, posicaoCache2, cache1, cache2, custo);
                    cache1[posicaoCache1].cacheHit = 4;

                    return cache1[posicaoCache1];
                }
                else{
                    custo+=11310;
                    
                    posicaoRAM = LFU(tamanhoRAM, RAM);
                    RAM[posicaoRAM] = trocaHD(RAM, endereco.endBloco, posicaoRAM);

                    posicaoCache3 = LFU(tamanhoCache3, cache3);
                    cache3[posicaoCache3] = trocaMemoria(posicaoCache3, posicaoRAM, cache3, RAM, custo);
                    
                    posicaoCache2 = LFU(tamanhoCache2, cache2);
                    cache2[posicaoCache2] = trocaMemoria(posicaoCache2, posicaoCache3, cache2, cache3, custo);
                    
                    posicaoCache1 = LFU(tamanhoCache1, cache1);
                    cache1[posicaoCache1] = trocaMemoria(posicaoCache1, posicaoCache2, cache1, cache2, custo);

                    cache1[posicaoCache1].cacheHit = 5;   
                    return cache1[posicaoCache1];
                }    
            }
        }
    }
}

int procuraEndereco(BlocoMemoria* cache, Endereco endereco, int tamanhoMemoria){ 
    for(int i=0; i<tamanhoMemoria; i++){
        if(cache[i].endBloco == endereco.endBloco){
            cache[i].numAcessos++;
            return i;
        }
    }
    return -1;
}

BlocoMemoria trocaMemoria(int posicaoDestino, int posicaoRaiz, BlocoMemoria* cacheDestino, BlocoMemoria* cacheRaiz, int custo){
    BlocoMemoria aux = cacheDestino[posicaoDestino]; 
    cacheDestino[posicaoDestino] = cacheRaiz[posicaoRaiz];
    cacheRaiz[posicaoRaiz] = aux;

    cacheDestino[posicaoDestino].custo = custo;

    cacheDestino[posicaoDestino].numAcessos++;
    cacheRaiz[posicaoRaiz].numAcessos++;

    return cacheDestino[posicaoDestino];
}

int LFU(int tamanho, BlocoMemoria* cache){ 
    int aux = INT_MAX, posicaoCache;

    for(int i=0; i<tamanho; i++){
        if(cache[i].endBloco == -1)
            return i;
        else{
            if(cache[i].numAcessos < aux){
                aux = cache[i].numAcessos;
                posicaoCache = i;
            }
        }
    }
    cache[posicaoCache].numAcessos++;

    return posicaoCache;
}

void programaInstrucoesTxt(Instrucao* memoriaInstrucoes){
    FILE* arquivo = fopen("instrucoes.txt", "r");
    for(int i = 0; i < tamanhoPrograma-1; i++){
        Instrucao umaInstrucao;
        fscanf(arquivo, "%d", &umaInstrucao.opcode);
        fscanf(arquivo, "%d", &umaInstrucao.add1.endBloco);
        fscanf(arquivo, "%d", &umaInstrucao.add1.endPalavra);
        fscanf(arquivo, "%d", &umaInstrucao.add2.endBloco);
        fscanf(arquivo, "%d", &umaInstrucao.add2.endPalavra);
        fscanf(arquivo, "%d", &umaInstrucao.add3.endBloco);
        fscanf(arquivo, "%d", &umaInstrucao.add3.endPalavra);

        memoriaInstrucoes[i] = umaInstrucao;
    }

    Instrucao umaInstrucao;

    fscanf(arquivo, "%d", &umaInstrucao.opcode);

    memoriaInstrucoes[tamanhoPrograma-1] = umaInstrucao;
    fclose(arquivo);
}

void montarInstrucaoGerador(Instrucao* memoriaInstrucoes, char* nome, int tamanho){
    FILE* arquivo = fopen(nome, "r");
    for(int i = 0; i < tamanho-1; i++){
        Instrucao umaInstrucao;
        fscanf(arquivo, "%d", &umaInstrucao.opcode);
        fscanf(arquivo, "%d", &umaInstrucao.add1.endBloco);
        fscanf(arquivo, "%d", &umaInstrucao.add1.endPalavra);
        fscanf(arquivo, "%d", &umaInstrucao.add2.endBloco);
        fscanf(arquivo, "%d", &umaInstrucao.add2.endPalavra);
        fscanf(arquivo, "%d", &umaInstrucao.add3.endBloco);
        fscanf(arquivo, "%d", &umaInstrucao.add3.endPalavra);

        memoriaInstrucoes[i] = umaInstrucao;
    }

    Instrucao umaInstrucao;

    fscanf(arquivo, "%d", &umaInstrucao.opcode);

    memoriaInstrucoes[tamanho-1] = umaInstrucao;
    fclose(arquivo);
}

BlocoMemoria trocaHD(BlocoMemoria* RAM, int endBloco, int posicaoRAM){
    int p0, p1, p2, p3, ram0, ram1, ram2, ram3;
    long deslocamento = endBloco * sizeof(BlocoMemoria);
    
    FILE* HD = fopen("HD.bin", "rb");

    fseek(HD, deslocamento, SEEK_SET); 
    fread(&p0, sizeof(int), 1, HD); 
    fread(&p1, sizeof(int), 1, HD);
    fread(&p2, sizeof(int), 1, HD);
    fread(&p3, sizeof(int), 1, HD); 

    rewind(HD); 
    fclose(HD); 

    if(RAM[posicaoRAM].atualizado == 1){
        RAM[posicaoRAM].atualizado = 0;
        
        ram0 = RAM[posicaoRAM].palavras[0];
        ram1 = RAM[posicaoRAM].palavras[1];
        ram2 = RAM[posicaoRAM].palavras[2];
        ram3 = RAM[posicaoRAM].palavras[3];
        
        deslocamento = RAM[posicaoRAM].endBloco * sizeof(BlocoMemoria);
        HD = fopen("HD.bin", "wb");
        fseek(HD, deslocamento, SEEK_SET);
        fwrite(&ram0, sizeof(int), 1, HD); 
        fwrite(&ram1, sizeof(int), 1, HD);
        fwrite(&ram2, sizeof(int), 1, HD);
        fwrite(&ram3, sizeof(int), 1, HD);

        RAM[posicaoRAM].endBloco = endBloco;
        RAM[posicaoRAM].palavras[0] = p0;
        RAM[posicaoRAM].palavras[1] = p1;
        RAM[posicaoRAM].palavras[2] = p2;
        RAM[posicaoRAM].palavras[3] = p3;

        rewind(HD); 
        fclose(HD); 
    }
    else{
        RAM[posicaoRAM].endBloco = endBloco;
        RAM[posicaoRAM].palavras[0] = p0;
        RAM[posicaoRAM].palavras[1] = p1;
        RAM[posicaoRAM].palavras[2] = p2;
        RAM[posicaoRAM].palavras[3] = p3;
    }

    return RAM[posicaoRAM];
}

Taxas* criarTaxas(){ 
    Taxas* taxas = malloc(sizeof(Taxas));
    taxas->custo = 0;
    taxas->hitC1 = 0;
    taxas->hitC2 = 0;
    taxas->hitC3 = 0;
    taxas->hitHD = 0;
    taxas->hitRAM = 0;
    taxas->missC1 = 0;
    taxas->missC2 = 0;
    taxas->missC3 = 0;
    taxas->missRAM = 0;

    return taxas;
}

void montarHD(){ 
    BlocoMemoria HD;
    FILE* arqv = fopen("HD.bin", "wb");

    for(int i=0; i<tamanhoHD; i++){
        HD.endBloco = i;
        for(int j=0; j<qntPalavrasBloco; j++){
            HD.palavras[j] = rand()%1000; 
        }
        HD.numAcessos = 0;
        HD.atualizado = 0;
        HD.cacheHit = -1;
        HD.custo = 0;

        fwrite(&HD, sizeof(BlocoMemoria), 1, arqv); 
    }

    fclose(arqv);
}