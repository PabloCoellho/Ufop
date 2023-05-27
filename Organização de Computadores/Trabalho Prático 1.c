#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void programaAleatorio(int*, int*);
void programaCriado(int*, int*);
void menuEscolhas(int*, int*);
void maquinaInterpretada(int*, int*);
void maquinaTraduzida(int*, int**, int*);
//MENU COM OS PROGRAMAS BÁSICOS
int soma(int*, int*, int, int);
int subtracao(int*, int*, int, int);
//PROGRAMAS POUCO MAIS AVANÇADOS
int multiplicacao(int*, int*, int, int);
int divisao(int*, int*, int, int);
int potencia(int*, int*, int, int);
int fatorial(int*, int*, int);
int raizQuadrada(int*, int*, int);
int areaQuadrado(int*, int*, int);
int areaCirculo(int*, int*, int);
int areaLosango(int*, int*, int, int);
int areaTrapezio(int*, int*, int, int, int);
int areaTriangulo(int*, int*, int, int);
int volumeCubo(int*, int*, int);
int volumeEsfera(int*, int*, int);
void velocidadeMedia(int*, int*, int, int, int, int);
int aceleracaoMedia(int*, int*, int, int, int, int);
int progressaoAritmetica(int*, int*, int, int, int);
int progressaoGeometrica(int*, int*, int, int, int);
void fibonacci(int*, int*, int);
void ehParOuImpar(int*, int*, int);
void divisaoFracionada(int*, int*, int, int);
void desalocaMatriz(int**, int);
int *alocaVetor(int);
int **alocaMatriz(int, int);

int main(){
    int tipoPrograma;
    int tamanhoInstrucao = 4;
    int tamanhoRAM = 100;
    int *umaInstrucao = alocaVetor(tamanhoInstrucao);
    int *RAM = alocaVetor(tamanhoRAM);
    //srand(time(NULL));

    printf("Deseja um programa aleatorio ou um programa criar um?\n(1)Aleatorio\n(2)Criar\n");
    scanf("%d", &tipoPrograma);

    switch (tipoPrograma){
        case 1:{
            programaAleatorio(umaInstrucao, RAM);
            break;
        }
        
        case 2:{
            menuEscolhas(umaInstrucao, RAM);
            break;
        }

        default:{
            printf("Opa, não existe essa opcao. Tente novamente :)\n");
            break;
        }
    }

    free(umaInstrucao);
    free(RAM);

    return 0;
}

void programaAleatorio(int *umaInstrucao, int *RAM){
    int qtdOperacoes = 1+rand()%5;
    int op, num1, num2;
    srand(time(NULL));

    while(qtdOperacoes > 0){
        op = 21;//+rand()%21;
        printf("\n"); 
        switch(op){
            //SOMA
            case 1:{
                num1 = rand()%11;
                num2 = rand()%11;
                int resultado = soma(umaInstrucao, RAM, num1, num2);
                printf("A soma de %d com %d e: %d\n", num1, num2, resultado);
                break;
            }
            //SUBTRAÇÃO
            case 2:{
                num1 = rand()%11;
                num2 = rand()%11;
                int resultado = subtracao(umaInstrucao, RAM, num1, num2);
                printf("A subtração de %d com %d e: %d\n", num1, num2, resultado);
                break;
            }
            //MULTIPLICAÇÃO
            case 3:{
                num1 = rand()%11;
                num2 = rand()%11;
                int resultado = multiplicacao(umaInstrucao, RAM, num1, num2);
                printf("A multiplicação de %d por %d e: %d\n", num1, num2, resultado);
                break;
            }
            //DIVISÃO
            case 4:{
                num1 = rand()%100;
                num2 = rand()%20;
                int resultado = divisao(umaInstrucao, RAM, num2, num1);
                printf("A divisão de %d por %d e: %d\n", num1, num2, resultado);
                break;
            }
            //POTÊNCIA
            case 5:{
                num1 = rand()%10;
                num2 = rand()%4;

                if(num1 == 0 && num2 == 0){
                    printf("A potencia de base 0 e expoente 0 não existe\n");
                }
                else if(num2 == 0){
                    printf("A potencia de base %d e expoente 0 e: 1\n", num1);
                }
                else if(num2 == 1){
                    printf("A potencia de base %d e expoente 1 e: %d\n", num1, num1);
                }
                else{
                    int resultado = potencia(umaInstrucao, RAM, num1, num2);
                    printf("A potencia de base %d e expoente %d e: %d\n", num1, num2, resultado);
                }
                break;
            }
            //FATORIAL
            case 6:{
                int num = rand()%11;
                int resultado = fatorial(umaInstrucao, RAM, num);
                printf("O fatorial do %d e = %d\n", num, resultado);
                break;
            }
            //FIBONACCI
            case 7:{
                int tamanho = 1+rand()%20;
                fibonacci(umaInstrucao, RAM, tamanho);
                break;
            }
            //RAIZ QUADRADA
            case 8:{
                int num = 9;
                int resultado = raizQuadrada(umaInstrucao, RAM, num);
                printf("A raiz quadrada de %d e: %d\n", num, resultado);
                break;
            }
            //ÁREA QUADRADO
            case 9:{
                int lado = rand()%20;
                int resultado = areaQuadrado(umaInstrucao, RAM, lado);
                printf("A area do quadrado de lado %d e: %d\n", lado, resultado);
                break;
            }
            //ÁREA CÍRCULO
            case 10:{
                int raio = rand()%20;
                int resultado = areaCirculo(umaInstrucao, RAM, raio);
                printf("A area do circulo de raio %d e aproximadamente: %d\n", raio, resultado);
                break;
            }
            //AREA LOSANGO
            case 11:{
                int diagonal1 = 1+rand()%10;
                int diagonal2 = 1+rand()%10;
                int resultado = areaLosango(umaInstrucao, RAM, diagonal1, diagonal2);

                if(diagonal1 > diagonal2)
                    printf("A area do losango de diagonal maior: %d e diagonal menor: %d e: %d\n", diagonal1, diagonal2, resultado);
                else if(diagonal2 > diagonal1)
                     printf("A area do losango de diagonal maior: %d e diagonal menor: %d e: %d\n", diagonal2, diagonal1, resultado);
                else
                    printf("Diagonais com valores iguais, rode novamente!\n");
                break;
            }
            //ÁREA TRAPÉZIO
            case 12:{
                int base1 = 1+rand()%10;
                int base2 = 1+rand()%10;
                int altura = 1+rand()%10;
                int resultado = areaTrapezio(umaInstrucao, RAM, base1, base2, altura);

                if(base1 > base2)
                    printf("A area do trapezio de base maior: %d, base menor: %d e altura: %d e: %d\n", base1, base2, altura, resultado);
                else if(base2 > base1)
                    printf("A area do trapezio de base maior: %d, base menor: %d e altura: %d e: %d\n", base2, base1, altura, resultado);
                else
                    printf("Bases com valores iguais, rode novamente!\n");    
                break;
            }
            //ÁREA TRIÂNGULO
            case 13:{
                int base = 1+rand()%10;
                int altura = 1+rand()%10;
                int resultado = areaTriangulo(umaInstrucao, RAM, base, altura);
                printf("A area do triangulo de base: %d e altura: %d e: %d\n", base, altura, resultado);
                break;
            }
            //PA
            case 14:{
                int primeiroTermo = rand()%5;
                int razao = 1+rand()%5;
                int enesimoTermo = 1+rand()%5;
                int resultado = progressaoAritmetica(umaInstrucao, RAM, primeiroTermo, razao, enesimoTermo);

                printf("O %dº termo da PA de primeiro termo %d e razão %d é: %d\n", enesimoTermo, primeiroTermo, razao, resultado);
                break;
            }
            //PG
            case 15:{
                int primeiroTermo = 1+rand()%5;
                int razao = 1+rand()%5;
                int enesimoTermo = 1+rand()%5;
                int resultado = progressaoGeometrica(umaInstrucao, RAM, primeiroTermo, razao, enesimoTermo);

                printf("O %d° termo da PG de primeiro termo %d e razão %d é: %d\n", enesimoTermo, primeiroTermo, razao, resultado);
                break;
            }
            //VOLUME CUBO
            case 16:{
                int lado = 1+rand()%10;
                int resultado = volumeCubo(umaInstrucao, RAM, lado);
                printf("O volume do cubo de lado %d é: %d\n", lado, resultado);
                break;
            }
            //VOLUME ESFERA
            case 17:{
                int raio = 1+rand()%10;
                int resultado = volumeEsfera(umaInstrucao, RAM, raio);
                printf("O volume da esfera de raio %d é: %d\n", raio, resultado);
                break;
            }
            //VELOCIDADE MÉDIA
            case 18:{
                int posicaoInicial = 1+rand()%5;
                int posicaoFinal = 6+rand()%30;
                int tempoInicial = 1+rand()%5;
                int tempoFinal = 6+rand()%10;
                velocidadeMedia(umaInstrucao, RAM, posicaoInicial, posicaoFinal, tempoInicial, tempoFinal);
                break;
            }
            //ACELERAÇÃO MÉDIA
            case 19:{
                int velocidadeInicial = 10;
                int velocidadeFinal = 20;
                int tempoInicial = 5;
                int tempoFinal = 10;
                int resultado = aceleracaoMedia(umaInstrucao, RAM, velocidadeInicial, velocidadeFinal, tempoInicial, tempoFinal);
                printf("Velocidade inicial = %dm/s\nVelocidade final = %dm/s\nTempo inicial = %ds\nTempo final = %ds\nAceleração Média = %dm/s²\n", velocidadeInicial, velocidadeFinal, tempoInicial, tempoFinal, resultado);
                break;
            }
            //PAR OU ÍMPAR
            case 20:{
                int num = rand()%100;
                ehParOuImpar(umaInstrucao, RAM, num);
                break;
            }
            //DIVISÃO FRACIONADA
            case 21:{
                int dividendo, divisor;
                dividendo = rand()%1000;
                divisor = rand()%1000;
                divisaoFracionada(umaInstrucao, RAM, dividendo, divisor);
                break;
            }
        }
        printf("\n");
        qtdOperacoes--;
    }
}

void menuEscolhas(int *umaInstrucao, int *RAM){
    int qtdOperacoes;
    int op, num1 = 0, num2 = 0;
    printf("Informe a quantidade de operações que deseja efetuar: ");
    scanf("%d", &qtdOperacoes);

    while(qtdOperacoes > 0){
        printf("Informe a operação que deseja efetuar: \n");
        printf("(1)Soma\n(2)Subtração\n(3)Multiplicação\n(4)Divisão\n(5)Potência\n(6)Fatorial\n(7)Fibonacci\n(8)Raiz Quadrada\n(9)Área Quadrado\n(10)Área Círculo\n(11)Área Losango\n(12)Área Trapézio\n(13)Área Triângulo\n(14)P.A\n(15)P.G\n(16)Volume Cubo\n(17)Volume Esfera\n(18)Velocidade Média\n(19)Aceleração Média\n(20)Par ou Ímpar\n(21)Divisão Fracionada\n");
        scanf("%d", &op);
        printf("\n"); 
        switch(op){
            //SOMA
            case 1:{
                int num1, num2, resultado;
                printf("Informe o primeiro número: ");
                scanf("%d", &num1);
                printf("Informe o segundo número: ");
                scanf("%d", &num2);
                resultado = soma(umaInstrucao, RAM, num1, num2);
                printf("A soma de %d com %d é: %d\n", num1, num2, resultado);
                break;
            }
            //SUBTRAÇÃO
            case 2:{
                int num1, num2, resultado;
                printf("Informe o primeiro número: ");
                scanf("%d", &num1);
                printf("Informe o segundo número: ");
                scanf("%d", &num2);
                resultado = subtracao(umaInstrucao, RAM, num1, num2);
                printf("A subtração de %d com %d é: %d\n", num1, num2, resultado);
                break;
            }
            //MULTIPLICAÇÃO
            case 3:{
                int num1, num2, resultado;
                printf("Informe o primeiro número: ");
                scanf("%d", &num1);
                printf("Informe o segundo número: ");
                scanf("%d", &num2);
                resultado = multiplicacao(umaInstrucao, RAM, num1, num2);
                printf("A multiplicação de %d por %d é: %d\n", num1, num2, resultado);
                break;
            }
            //DIVISÃO
            case 4:{
                int num1, num2, resultado;
                printf("Informe o primeiro número: ");
                scanf("%d", &num1);
                printf("Informe o segundo número: ");
                scanf("%d", &num2);
                resultado = divisao(umaInstrucao, RAM, num2, num1);
                printf("A divisão de %d por %d é: %d\n", num1, num2, resultado);
                break;
            }
            //POTÊNCIA
            case 5:{
                int num1, num2, resultado;
                printf("Informe a base: ");
                scanf("%d", &num1);
                printf("Informe o expoente: ");
                scanf("%d", &num2);

                if(num1 == 0 && num2 == 0){
                    printf("A potência de base 0 e expoente 0 não existe\n");
                }
                else if(num2 == 0){
                    printf("A potência de base %d e expoente 0 é: 1\n", num1);
                }
                else if(num2 == 1){
                    printf("A potência de base %d e expoente 1 é: %d\n", num1, num1);
                }
                else{
                    resultado = potencia(umaInstrucao, RAM, num1, num2);
                    printf("A potência de base %d e expoente %d é: %d\n", num1, num2, resultado);
                }
                break;
            }
            //FATORIAL
            case 6:{
                int num, resultado;
                printf("Informe o número: ");
                scanf("%d", &num);
                resultado = fatorial(umaInstrucao, RAM, num);
                printf("O fatorial de %d é = %d\n", num, resultado);
                break;
            }
            //FIBONACCI
            case 7:{
                int tamanho;
                printf("Informe o tamanho do Fibonacci: ");
                scanf("%d", &tamanho);
                fibonacci(umaInstrucao, RAM, tamanho);
                break;
            }
            //RAIZ QUADRADA
            case 8:{
                int num, resultado;
                printf("Informe qual número deseja saber a raiz quadrada: ");
                scanf("%d", &num);
                resultado = raizQuadrada(umaInstrucao, RAM, num);
                printf("A raiz quadrada de %d é: %d\n", num, resultado);
                break;
            }
            //ÁREA QUADRADO
            case 9:{
                int lado, resultado;
                printf("Informe o lado do quadrado: ");
                scanf("%d", &lado);
                resultado = areaQuadrado(umaInstrucao, RAM, lado);
                printf("A área do quadrado de lado %d é: %d\n", lado, resultado);
                break;
            }
            //ÁREA CÍRCULO
            case 10:{
                int raio, resultado;
                printf("Informe o tamanho do raio do círculo: ");
                scanf("%d", &raio);
                resultado = areaCirculo(umaInstrucao, RAM, raio);
                printf("A área do círculo de raio %d é aproximadamente: %d\n", raio, resultado);
                break;
            }
            //AREA LOSANGO
            case 11:{
                int diagonal1, diagonal2, resultado;
                printf("Informe o valor da primeira diagonal: ");
                scanf("%d", &diagonal1);
                printf("Informe o valor da segunda diagonal: ");
                scanf("%d", &diagonal2);
        
                resultado = areaLosango(umaInstrucao, RAM, diagonal1, diagonal2);

                if(diagonal1 > diagonal2)
                    printf("A área do losango de diagonal maior: %d e diagonal menor: %d é: %d\n", diagonal1, diagonal2, resultado);
                else if(diagonal2 > diagonal1)
                     printf("A área do losango de diagonal maior: %d e diagonal menor: %d é: %d\n", diagonal2, diagonal1, resultado);
                else
                    printf("Diagonais com valores iguais, rode novamente!\n");
                break;
            }
            //ÁREA TRAPÉZIO
            case 12:{
                int base1, base2, altura, resultado;
                printf("Informe o valor de uma base: ");
                scanf("%d", &base1);
                printf("Informe o valor da outra base: ");
                scanf("%d", &base2);
                printf("Informe a altura: ");
                scanf("%d", &altura);

                resultado = areaTrapezio(umaInstrucao, RAM, base1, base2, altura);

                if(base1 > base2)
                    printf("A área do trapézio de base maior: %d, base menor: %d e altura: %d é = %d\n", base1, base2, altura, resultado);
                else if(base2 > base1)
                    printf("A área do trapézio de base maior: %d, base menor: %d e altura: %d é = %d\n", base2, base1, altura, resultado);
                else
                    printf("Bases com valores iguais, rode novamente!\n");    
                break;
            }
            //ÁREA TRIÂNGULO
            case 13:{
                int base, altura, resultado;
                printf("Informe a base: ");
                scanf("%d", &base);
                printf("Informe a altura: ");
                scanf("%d", &altura);

                resultado = areaTriangulo(umaInstrucao, RAM, base, altura);
                printf("A área do triângulo de base: %d e altura: %d é: %d\n", base, altura, resultado);
                break;
            }
            //PA
            case 14:{
                int primeiroTermo, razao, enesimoTermo, resultado;
                printf("Informe o primeiro termo da sequência: ");
                scanf("%d", &primeiroTermo);
                printf("Informe a razão da sequência: ");
                scanf("%d", &razao);
                printf("Informe o enésimo termo: ");
                scanf("%d", &enesimoTermo);
                resultado = progressaoAritmetica(umaInstrucao, RAM, primeiroTermo, razao, enesimoTermo);

                printf("O %dº termo da PA de primeiro termo %d e razão %d é = %d\n", enesimoTermo, primeiroTermo, razao, resultado);
                break;
            }
            //PG
            case 15:{
                int primeiroTermo, razao, enesimoTermo, resultado;
                printf("Informe o primeiro termo da sequência: ");
                scanf("%d", &primeiroTermo);
                printf("Informe a razão da sequência: ");
                scanf("%d", &razao);
                printf("Informe o enésimo termo: ");
                scanf("%d", &enesimoTermo);
                resultado = progressaoGeometrica(umaInstrucao, RAM, primeiroTermo, razao, enesimoTermo);

                printf("O %d° termo da PG de primeiro termo %d e razão %d é: %d\n", enesimoTermo, primeiroTermo, razao, resultado);
                break;
            }
            //VOLUME CUBO
            case 16:{
                int lado, resultado;
                printf("Informe o lado do cubo: ");
                scanf("%d", &lado);
                resultado = volumeCubo(umaInstrucao, RAM, lado);
                printf("O volume do cubo de lado %d é = %d\n", lado, resultado);
                break;
            }
            //VOLUME ESFERA
            case 17:{
                int raio, resultado;
                printf("Informe o raio da esfera: ");
                scanf("%d", &raio);
                resultado = volumeEsfera(umaInstrucao, RAM, raio);
                printf("O volume da esfera de raio %d é = %d\n", raio, resultado);
                break;
            }
            //VELOCIDADE MÉDIA
            case 18:{
                int posicaoInicial, posicaoFinal, tempoInicial, tempoFinal, resultado = 0;
                printf("Informe a posição inicial: ");
                scanf("%d", &posicaoInicial);
                printf("Informe a posição final: ");
                scanf("%d", &posicaoFinal);
                printf("Informe o tempo inicial: ");
                scanf("%d", &tempoInicial);
                printf("Informe o tempo final: ");
                scanf("%d", &tempoFinal);

                velocidadeMedia(umaInstrucao, RAM, posicaoInicial, posicaoFinal, tempoInicial, tempoFinal);
                
                break;
            }
            //ACELERAÇÃO MÉDIA
            case 19:{
                int velocidadeInicial, velocidadeFinal, tempoInicial, tempoFinal, resultado;
                printf("Informe a velocidade inicial: ");
                scanf("%d", &velocidadeInicial);
                printf("Informe a velocidade final: ");
                scanf("%d", &velocidadeFinal);
                printf("Informe o tempo inicial: ");
                scanf("%d", &tempoInicial);
                printf("Informe o tempo final: ");
                scanf("%d", &tempoFinal);

                resultado = aceleracaoMedia(umaInstrucao, RAM, velocidadeInicial, velocidadeFinal, tempoInicial, tempoFinal);
                printf("Velocidade inicial = %dm/s\nVelocidade final = %dm/s\nTempo inicial = %ds\nTempo final = %ds\nAceleração Média = %dm/s²\n", velocidadeInicial, velocidadeFinal, tempoInicial, tempoFinal, resultado);
                break;
            }
            //PAR OU ÍMPAR
            case 20:{
                int num;
                printf("Informe o número: ");
                scanf("%d", &num);
                ehParOuImpar(umaInstrucao, RAM, num);
                break;
            }
            //DIVISÃO FRACIONADA
            case 21:{
                int dividendo, divisor;
                printf("Informe o dividendo: ");
                scanf("%d", &dividendo);
                printf("Inform o divisor: ");
                scanf("%d", &divisor);
                divisaoFracionada(umaInstrucao, RAM, dividendo, divisor);
                break;
            }
        }
        printf("\n");
        qtdOperacoes--;
    }
}

int soma(int *umaInstrucao, int *RAM, int num1, int num2){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numLinhas = 5;
    int numColunas = 4;
    int **memoriaInstrucoes = alocaMatriz(numLinhas, numColunas);
    int resultado=0;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = num1;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;
    
    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = num2;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 2; 
    umaInstrucao[1] = 0; 
    umaInstrucao[2] = 1; 
    umaInstrucao[3] = 2;
    memoriaInstrucoes[2] = umaInstrucao;
    
    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;

    maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 2; 
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    resultado = umaInstrucao[1];

    desalocaMatriz(memoriaInstrucoes, numLinhas);
    return resultado;
}

int subtracao(int *umaInstrucao, int *RAM, int num1, int num2){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numLinhas = 4;
    int numColunas = 4; 
    int **memoriaInstrucoes = alocaMatriz(numLinhas, numColunas);
    int resultado=0;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = num1;
    umaInstrucao[2] = 0; 
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;
    
    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0; 
    umaInstrucao[1] = num2; 
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 3; 
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = 2;
    memoriaInstrucoes[2] = umaInstrucao;
    
    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;

    maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);
    
    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1; 
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    resultado = umaInstrucao[1];

    
    return resultado;
}

int multiplicacao(int *umaInstrucao, int *RAM, int multiplicador, int multiplicando){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numColunas = 4;
    int **memoriaInstrucoes = alocaMatriz(multiplicador+3, numColunas);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0; 
    umaInstrucao[1] = multiplicando; 
    umaInstrucao[2] = 0; 
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0; 
    umaInstrucao[1] = 0; 
    umaInstrucao[2] = 1; 
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    for(int i = 0; i<multiplicador; i++){
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 2;
        umaInstrucao[1] = 0;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = 1;
        memoriaInstrucoes[i+2] = umaInstrucao;
    }

	umaInstrucao = alocaVetor(numColunas);
	umaInstrucao[0] = -1;
	umaInstrucao[1] = -1;
	umaInstrucao[2] = -1;
	umaInstrucao[3] = -1;
	memoriaInstrucoes[multiplicador+2] = umaInstrucao;

	maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    int resultado = umaInstrucao[1];

    desalocaMatriz(memoriaInstrucoes, multiplicador+3);
    return resultado;
}

int divisao(int *umaInstrucao, int *RAM, int divisor, int dividendo){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numColunas = 4;
    int **memoriaInstrucoes = alocaMatriz(divisor+5, numColunas);
    int contador = 1;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0; 
    umaInstrucao[1] = divisor;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = dividendo;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[2] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = -1; 
    umaInstrucao[1] = -1; 
    umaInstrucao[2] = -1; 
    umaInstrucao[3] = -1; 
    memoriaInstrucoes[4] = umaInstrucao;

    maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

	umaInstrucao = alocaVetor(numColunas);
	umaInstrucao[0] = 1;
	umaInstrucao[1] = -1;
	umaInstrucao[2] = 0;
	umaInstrucao[3] = -1;		
	maquinaInterpretada(umaInstrucao, RAM);
	int ram0 = umaInstrucao[1];
		
	umaInstrucao = alocaVetor(numColunas);
	umaInstrucao[0] = 1;
	umaInstrucao[1] = -1;
	umaInstrucao[2] = 1;
	umaInstrucao[3] = -1;		
	maquinaInterpretada(umaInstrucao, RAM);
	int ram1 = umaInstrucao[1];
		
	while(ram1>=ram0){
		umaInstrucao = alocaVetor(numColunas);
		umaInstrucao[0] = 3;
		umaInstrucao[1] = 1;
		umaInstrucao[2] = 0;
		umaInstrucao[3] = 1;		
		maquinaInterpretada(umaInstrucao, RAM);
			
		umaInstrucao = alocaVetor(numColunas);
		umaInstrucao[0] = 2;
		umaInstrucao[1] = 2;
		umaInstrucao[2] = 3;
		umaInstrucao[3] = 3;		
		maquinaInterpretada(umaInstrucao, RAM);
		
		umaInstrucao = alocaVetor(numColunas);
		umaInstrucao[0] = 1;
		umaInstrucao[1] = -1;
		umaInstrucao[2] = 1;
		umaInstrucao[3] = -1;		
		maquinaInterpretada(umaInstrucao, RAM);
		ram1 = umaInstrucao[1];
 
	}
    //BUSCANDO O CONTADOR NA RAM[3]
    umaInstrucao = alocaVetor(numColunas);
	umaInstrucao[0] = 1;
	umaInstrucao[1] = -1;
	umaInstrucao[2] = 3;
	umaInstrucao[3] = -1;

	maquinaInterpretada(umaInstrucao, RAM);

	contador = umaInstrucao[1];
    return contador;
}

int potencia(int *umaInstrucao, int *RAM, int base, int expoente){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numColunas = 4;
    int **memoriaInstrucoes = alocaMatriz(expoente+1, numColunas);
    int auxiliar;

    auxiliar = multiplicacao(umaInstrucao, RAM, base, base);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = auxiliar;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);

    for(int i = 0; i < expoente-2; i++){
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        auxiliar = umaInstrucao[1];

        auxiliar = multiplicacao(umaInstrucao, RAM, auxiliar, base);

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = auxiliar;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
    }
    return auxiliar;
}

int fatorial(int *umaInstrucao, int *RAM, int num){
    int resultado = 1;
    int numColunas = 4;

    for(int i=num; i>0; i--)
        resultado = multiplicacao(umaInstrucao, RAM, resultado, i);

    return resultado;
}

int raizQuadrada(int *umaInstrucao, int *RAM, int num){
    for(int i = 1; ; i++){
        int resultado = potencia(umaInstrucao, RAM, i, 2);
        if(resultado == num){
            return i;
        }
    }
}

int areaQuadrado(int *umaInstrucao, int *RAM, int lado){
    int resultado = multiplicacao(umaInstrucao, RAM, lado, lado);
    return resultado;
}

int areaCirculo(int *umaInstrucao, int *RAM, int raio){
    //A = pi*r²
    int pi;
    int numColunas = 4;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 3;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    pi = umaInstrucao[1];

    int resultadoPotencia = potencia(umaInstrucao, RAM, raio, 2);
    int resultadoFinal = multiplicacao(umaInstrucao, RAM, pi, resultadoPotencia);

    return resultadoFinal;
}

int areaLosango(int *umaInstrucao, int *RAM, int diagonalMaior, int diagonalMenor){
    //A = (D*d)/2

    int multiplicandoDiagonais = multiplicacao(umaInstrucao, RAM, diagonalMaior, diagonalMenor);
    int resultado = divisao(umaInstrucao, RAM, 2, multiplicandoDiagonais);

    return resultado;
}

int areaTrapezio(int *umaInstrucao, int *RAM, int base1, int base2, int altura){
    //A = ((B+b)/2)*h
    //Somando a base maior com a base menor, reaproveitando esta função
    int somaBases = soma(umaInstrucao, RAM, base1, base2);
    int multiplicacaoBH = multiplicacao(umaInstrucao, RAM, somaBases, altura);
    int resultado = divisao(umaInstrucao, RAM, 2, multiplicacaoBH);

    return resultado;
}

int areaTriangulo(int *umaInstrucao, int *RAM, int base, int altura){
    //A = (B*h)/2
    int baseAltura = multiplicacao(umaInstrucao, RAM, base, altura);
    int resultado = divisao(umaInstrucao, RAM, 2, baseAltura);
    return resultado;
}

int volumeCubo(int *umaInstrucao, int *RAM, int lado){
    int resultado = multiplicacao(umaInstrucao, RAM, lado, lado);
    resultado = multiplicacao(umaInstrucao, RAM, resultado, lado);
    return resultado;
}

int volumeEsfera(int *umaInstrucao, int *RAM, int raio){
    //V = (4*PI*R³)/3
    int pi = 3;
    int potenciaRaio = potencia(umaInstrucao, RAM, raio, 3);
    int resultado = multiplicacao(umaInstrucao, RAM, 4, pi);
    resultado = multiplicacao(umaInstrucao, RAM, resultado, potenciaRaio);
    resultado = divisao(umaInstrucao, RAM, 3, resultado);
    return resultado;
}

void velocidadeMedia(int *umaInstrucao, int *RAM, int posicaoInicial, int posicaoFinal, int tempoInicial, int tempoFinal){
    int posicao = subtracao(umaInstrucao, RAM, posicaoFinal, posicaoInicial);
    int tempo = subtracao(umaInstrucao, RAM, tempoFinal, tempoInicial);
    int resultado = divisao(umaInstrucao, RAM, tempo, posicao);
    printf("Distância = %dm\nTempo = %ds\nVelocidade Média = %dm/s\n", posicao, tempo, resultado);
}

int aceleracaoMedia(int *umaInstrucao, int *RAM, int velocidadeInicial, int velocidadeFinal, int tempoInicial, int tempoFinal){
    int numLinhas = 7;
    int numColunas = 4;
    int **memoriaInstrucoes = alocaMatriz(numLinhas, numColunas);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = velocidadeInicial;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = velocidadeFinal;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 3;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = 2;
    memoriaInstrucoes[2] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = tempoInicial;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = tempoFinal;
    umaInstrucao[2] = 4;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[4] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 3;
    umaInstrucao[1] = 4;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = 5;    
    memoriaInstrucoes[5] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;    
    memoriaInstrucoes[6] = umaInstrucao;

    maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;    
    maquinaInterpretada(umaInstrucao, RAM);
    int subVelocidade = umaInstrucao[1];

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 5;
    umaInstrucao[3] = -1;    
    maquinaInterpretada(umaInstrucao, RAM);
    int subTempo = umaInstrucao[1];
    
    int resultado = divisao(umaInstrucao, RAM, subTempo, subVelocidade);
    
    return resultado;
}

int progressaoAritmetica(int *umaInstrucao, int *RAM, int primeiroTermo, int razao, int enesimoTermo){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numLinhas = 5;
    int numColunas = 4;
    int **memoriaInstrucoes = alocaMatriz(numLinhas, numColunas);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = razao;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = primeiroTermo;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = enesimoTermo;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[2] = umaInstrucao;

    //FAZENDO O CONTADOR
    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = -1; 
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1; 
    umaInstrucao[3] = -1;
    memoriaInstrucoes[4] = umaInstrucao;

    maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

    while(enesimoTermo > 1){
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 2;
        umaInstrucao[1] = 0;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = 1;
        maquinaInterpretada(umaInstrucao, RAM);

        //CONTADOR
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 3;
        umaInstrucao[1] = 2;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = 2;
        maquinaInterpretada(umaInstrucao, RAM);

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 2;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        enesimoTermo = umaInstrucao[1];
    }

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    int resultado = umaInstrucao[1];
    
    return resultado;
}

int progressaoGeometrica(int *umaInstrucao, int *RAM, int primeiroTermo, int razao, int enesimoTermo){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numLinhas = 5;
    int numColunas = 4;
    int resultado;
    int **memoriaInstrucoes = alocaMatriz(numLinhas, numColunas);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = razao;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = primeiroTermo;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = enesimoTermo;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[2] = umaInstrucao;

    //FAZENDO O CONTADOR
    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1; 
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = -1; 
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1; 
    umaInstrucao[3] = -1;
    memoriaInstrucoes[4] = umaInstrucao;

    maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

    while(enesimoTermo > 1){
        resultado = multiplicacao(umaInstrucao, RAM, primeiroTermo, razao);
        
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = resultado;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        primeiroTermo = umaInstrucao[1];

        //CONTADOR
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 3;
        umaInstrucao[1] = 2;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = 2;
        maquinaInterpretada(umaInstrucao, RAM);

        //BUSCANDO O CONTADOR NA RAM
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 2;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        enesimoTermo = umaInstrucao[1];
    }

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    resultado = umaInstrucao[1];
    
    return resultado;
}

void fibonacci(int *umaInstrucao, int *RAM, int termo){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    //0, 1, 1, 2, 3, 5, 8, 13...2584
    int numLinhas = 5;
    int numColunas = 4;
    int ant = 0;
    int aux = 1;
    int fib = 1;
    int **memoriaInstrucoes = alocaMatriz(numLinhas, numColunas);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = ant;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = aux;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = termo;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[2] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 4;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[4] = umaInstrucao;

    maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    fib = umaInstrucao[1];
    printf("%d, ", fib);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    fib = umaInstrucao[1];
    printf("%d, ", fib);

    while(termo > 1){
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 2;
        umaInstrucao[1] = 0;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = 2;
        maquinaInterpretada(umaInstrucao, RAM);

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 2;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        fib = umaInstrucao[1];
        printf("%d, ", fib);
        
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        aux = umaInstrucao[1];

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = aux;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = fib;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);


        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 3;
        umaInstrucao[1] = 3;
        umaInstrucao[2] = 4;
        umaInstrucao[3] = 3;
        maquinaInterpretada(umaInstrucao, RAM);

        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        termo = umaInstrucao[1];
    } 

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 2;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = 2;
    maquinaInterpretada(umaInstrucao, RAM);

    umaInstrucao = alocaVetor(numColunas);
    umaInstrucao[0] = 1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    maquinaInterpretada(umaInstrucao, RAM);
    fib = umaInstrucao[1];
    printf("%d...", fib); 
}

void ehParOuImpar(int *umaInstrucao, int *RAM, int num){
    int numFinal = num;
    int aux = 0;
    while(aux!=10){
        numFinal = subtracao(umaInstrucao, RAM, numFinal, 2);
        
        if(numFinal == -1){
            printf("O número %d é ímpar\n", num);
            aux = 10;
        }
        
        else if(numFinal == -2){
            printf("O número %d é par\n", num);
            aux = 10;
        }

        else if(numFinal == 0){
            printf("O número %d é par\n", num);
            aux = 10;
        }
        else if(numFinal == 1){
            printf("O número %d é ímpar\n", num);
            aux = 10;
        }
    }       
}

void montarRAM(int *RAM, int tamanho){
    srand(time(NULL));
    int numAleatorio;
    for(int i=0; i<tamanho; i++){
        numAleatorio = rand()%100;
        RAM[i] = numAleatorio;
    }
}

void maquinaTraduzida(int *umaInstrucao, int **memoriaInstrucoes, int *RAM){
	int PC =0;
	int opcode = 99999;

	while(opcode!=-1){
        opcode = memoriaInstrucoes[PC][0];
	    umaInstrucao = memoriaInstrucoes[PC];	
	    maquinaInterpretada(umaInstrucao, RAM);
		PC++;
	}		
}

void maquinaInterpretada(int *umaInstrucao, int *RAM){
	int opcode = umaInstrucao[0];
	switch (opcode){
	    //levar para RAM
	    case 0:{
			RAM[umaInstrucao[2]] = umaInstrucao[1]; 
			break;
		}
		//trazer da RAM
		case 1:{
			umaInstrucao[1] = RAM[umaInstrucao[2]]; 
			break;
		}
        //somar
		case 2:{
			int end1 = umaInstrucao[1];
			int end2 = umaInstrucao[2];
			int soma = RAM[end1]+RAM[end2];
			//salvando resultado na RAM
			int end3 = umaInstrucao[3];
			RAM[end3] = soma;
			break;
		}
        //subtrair
		case 3:{
			int end1 = umaInstrucao[1];
			int end2 = umaInstrucao[2];

			int sub = RAM[end1]-RAM[end2];
			//salvando resultado na RAM
			int end3 = umaInstrucao[3];
			RAM[end3] = sub;
            //printf("SUBTRACAO: %d\n", sub);
			break;
		}
	}
}

void divisaoFracionada(int *umaInstrucao, int *RAM, int dividendo, int divisor){
    //opCode 0 = levar pra memória
    //opCode 1 = buscar da memória
    //opCode 2 = somar
    //opCode 3 = subtrair

    int numColunas = 4;
    int numLinhas = 5;
    int dividendoAUX, parteInteira;
    int **memoriaInstrucoes = alocaMatriz(numLinhas, numColunas);
    int dividendo10x;
    int dividendo100x;
    if(divisor > dividendo){
        // 4 - 100
        // 3 - x
        // X = 300/4
        dividendo10x = multiplicacao(umaInstrucao, RAM, dividendo, 10);
        dividendo100x = multiplicacao(umaInstrucao, RAM, dividendo, 100);
        if(dividendo100x < divisor){
            int novoDividendo = multiplicacao(umaInstrucao, RAM, dividendo, 1000);
            int resultadoFinal = divisao(umaInstrucao, RAM, divisor, novoDividendo);
            printf("%d/%d = 0,00%d\n", dividendo, divisor, resultadoFinal);
        }
        else if(dividendo10x < divisor){
            int novoDividendo = multiplicacao(umaInstrucao, RAM, dividendo, 100);
            int resultadoFinal = divisao(umaInstrucao, RAM, divisor, novoDividendo);
            printf("%d/%d = 0,0%d\n", dividendo, divisor, resultadoFinal);
        }
        else{
            int novoDividendo = multiplicacao(umaInstrucao, RAM, dividendo, 100);
            int resultadoFinal = divisao(umaInstrucao, RAM, divisor, novoDividendo);
            printf("%d/%d = 0,%d\n", dividendo, divisor, resultadoFinal);
        }
    }
    else{
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = dividendo;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = -1;
        memoriaInstrucoes[0] = umaInstrucao;

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = divisor;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;
        memoriaInstrucoes[1] = umaInstrucao;

        //CONTADOR
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = 1;
        umaInstrucao[2] = 3;
        umaInstrucao[3] = -1;
        memoriaInstrucoes[2] = umaInstrucao;

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 0;
        umaInstrucao[1] = 1; //contador começa em 1
        umaInstrucao[2] = 4;
        umaInstrucao[3] = -1;
        memoriaInstrucoes[3] = umaInstrucao;

        //HALT
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = -1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = -1;
        umaInstrucao[3] = -1;
        memoriaInstrucoes[4] = umaInstrucao;

        maquinaTraduzida(umaInstrucao, memoriaInstrucoes, RAM);

        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 3;
        umaInstrucao[1] = 0;
        umaInstrucao[2] = 1;
        umaInstrucao[3] = 2;
        maquinaInterpretada(umaInstrucao, RAM);
        
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 2;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        dividendoAUX = umaInstrucao[1];

        while(dividendoAUX >= divisor){
            
            umaInstrucao = alocaVetor(numColunas);
            umaInstrucao[0] = 3;
            umaInstrucao[1] = 2;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = 2;
            maquinaInterpretada(umaInstrucao, RAM);

            umaInstrucao = alocaVetor(numColunas);
            umaInstrucao[0] = 1;
            umaInstrucao[1] = -1;
            umaInstrucao[2] = 2;
            umaInstrucao[3] = -1;
            maquinaInterpretada(umaInstrucao, RAM);
            dividendoAUX = umaInstrucao[1];

            //CONTADOR
            umaInstrucao = alocaVetor(numColunas);
            umaInstrucao[0] = 2;
            umaInstrucao[1] = 3;
            umaInstrucao[2] = 4;
            umaInstrucao[3] = 4;
            maquinaInterpretada(umaInstrucao, RAM);
        }
        umaInstrucao = alocaVetor(numColunas);
        umaInstrucao[0] = 1;
        umaInstrucao[1] = -1;
        umaInstrucao[2] = 4;
        umaInstrucao[3] = -1;
        maquinaInterpretada(umaInstrucao, RAM);
        parteInteira = umaInstrucao[1];
        
        // PARTE FRACIONADA
        // 3 - 100
        // 1 - X 
        // X = 100/3

        int novoDividendo = multiplicacao(umaInstrucao, RAM, dividendoAUX, 100);
        int resultadoFracionado = divisao(umaInstrucao, RAM, divisor, novoDividendo);
        // printf("%d\n", resultadoFracionado);
        printf("%d/%d = %d,%d\n", dividendo, divisor, parteInteira, resultadoFracionado);
    }

}

int *alocaVetor(int tamanho){
    int *vetor = (int*) (malloc(tamanho * sizeof(int)));
    return vetor;
}

int **alocaMatriz(int numLinhas, int numColunas){
    int i;
    int **matriz = malloc(numLinhas * sizeof(int*));
    for (i = 0; i < numColunas; i++){
        matriz[i] = malloc(numColunas * (sizeof(int)));
    }
    return matriz;
}

void desalocaMatriz(int **matriz, int numLinhas){
    for(int i=0; i<numLinhas; i++)
        free(matriz[i]);
    free(matriz);
}