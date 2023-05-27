#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define max_direction(x, y) (((x) > (y)) ? (0) : (1))

int SubPalinRecursivo(char *s, int direita, int esquerda);
int SubPalinMemo(char *s, int esquerda, int direita, char **m);
int SubPalinItera(char *s, char **m, int n);
void printSubPalinItera(char **m, char *s, int i, int j);
/*
SUBESTRUTURA OTIMA

E(i,j) = 
Se s[i] e s[j] forem iguais = E(i+1, j-1) + 2
Se nao, max(E(i, j-1), E(i+1, j))
*/

int main(int argc, char *argv[]){

    if (argc != 3){
        printf("Quantidade incorreta de argumentos para executar o programa!\n");
        exit(0);
    }

    //Tamanho da maior subsequencia que eh um palindromo
    int maiorTamanho;
    int k = atoi(argv[2]);

    int SIZE = strlen(argv[1]); //Tamanho da string recebida como entrada

    char **matriz = malloc(SIZE * sizeof(char*)); //Matriz para armazenar os valores
    for (int i = 0; i < SIZE; i++){
        matriz[i] = malloc(SIZE * sizeof(char));
    }

    char *string = malloc(SIZE * sizeof(char)); //String recebida como entrada
    strcpy(string, argv[1]);

    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            matriz[i][j] = -1;
    }

    switch (k) {
    case 0:
        printf("Funcao Recursiva:\n");
        maiorTamanho = SubPalinRecursivo(string, 0, SIZE);
        break;
    
    case 1:
        printf("Funcao de Memorizacao:\n");
        maiorTamanho = SubPalinMemo(string, 0, SIZE-1, matriz);
        break;

    case 2:
        printf("Funcao Iterativa:\n");
        maiorTamanho = SubPalinItera(string, matriz, SIZE);
        printf("Subsequencia que eh um palindromo: \n");
        printSubPalinItera(matriz, string, 0, SIZE - 1);
        printf("\n\n");
        break;

    default:
        printf("Parametro que indentifica a funcao incorreto\n");
        exit(1);
        break;
    }

    printf("Tamanho da maior Subsequencia que eh um palindromo: \n%d\n\n", maiorTamanho);
 
    
    for (int i = 0; i < SIZE; i++){
        free(matriz[i]);
    }

    free(matriz);  
    free(string);

    return 0;
}

int SubPalinMemo(char *s, int esquerda, int direita, char **m) {
    if (esquerda == direita) {
        m[esquerda][direita] = 1;
        return m[esquerda][direita];
    }
    if(s[esquerda] == s[direita]) {        
        if (m[esquerda][direita] == -1) {
            if(direita - esquerda == 1) {
                m[esquerda][direita] = 2;
                return m[esquerda][direita];
            }
            m[esquerda][direita] = SubPalinMemo(s, esquerda+1, direita-1, m) + 2;
        }            
        return m[esquerda][direita];
    }
    else {
        if(m[esquerda][direita] == -1){
            m[esquerda][direita] = max(SubPalinMemo(s, esquerda, direita-1, m), SubPalinMemo(s, esquerda+1, direita, m));
            return m[esquerda][direita];
        }
    }
}

int SubPalinRecursivo(char *s, int esquerda, int direita){
    if (esquerda == direita)
        return 1;
    if(s[esquerda] == s[direita]) {
        if(direita - esquerda == 1)
            return 2;
        return SubPalinRecursivo(s, esquerda+1, direita-1) + 2;
    }
    else 
        return max(SubPalinRecursivo(s, esquerda, direita-1), SubPalinRecursivo(s, esquerda+1, direita));    
}

int SubPalinItera(char *s, char **m, int n){
    int j; //Contador da coluna
    //Iniciando a diagonal principal
    for (int i = 0; i < n; i++){
        m[i][i] = 1;
    }
    for (int l = 2; l <= n; l++){ //Tamanho da subsequencia
        for (int i = 0; i < n-l+1; i++){ //Percorrendo as linhas da matriz
            j = i + l - 1;
            //Se os caracteres das extremidades forem iguais e for a primeira iteracao, 
            //o tamanho do palindromo eh 2
            if (s[i] == s[j] && l == 2){ 
                m[i][j] = 2;
            }
            //Se os caracteres das extremidades forem iguais e nao for a primeira iteracao, 
            //o tamanho do palindromo eh o tamanho do maior palindromo dos caracetres internos mais 2 
            //por causa dos caracteres das extremidades
            else if (s[i] == s[j]){ 
                m[i][j] = m[i + 1][j-1] + 2;
            }
            //Se nao forem iguais, o tamanho eh igual ao tamanho da maior subsequencia 
            //que eh um palindromo nos caracteres internos
            else { 
                m[i][j] = max(m[i][j - 1], m[i + 1][j]);
            }
        }
    }
    return m[0][n - 1];
}

void printSubPalinItera(char **m, char *s, int i, int j){
    //Se os indices forem iguais printa o caractere e encerra a recursividade
    if (i == j){ 
        printf("%c", s[i]);
        return;
    }
    //Se os caracteres da extremidade forem iguais printa o da extrema esquerda, 
    //chama a funcao recursivamente atualizando os indices, e imprime o caractere da extrea direita
    if (s[i] == s[j]){ 
        printf("%c", s[i]);
        printSubPalinItera(m, s, i + 1, j - 1);
        printf("%c", s[j]);
    }
    //Se não verifica qual subsequencia possui o maior palindromo e chama funcao recursivamente 
    //para essa subsequencia
    else { 
        int x = max_direction(m[i][j - 1], m[i + 1][j]);

        if (x == 1){
            printSubPalinItera(m, s, i + 1, j);
        }
        else {
            printSubPalinItera(m, s, i, j - 1);
        }
    }
}