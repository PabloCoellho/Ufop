#include <stdio.h>
#include <stdlib.h>

void imprimeOperacoes(int **z, int n, int m);

int main() {
    int **z, n, m;
    n = 9;
    m = 9;

    //Alocando a Matriz
    z = (int **) malloc ((n+2) * sizeof(sizeof(int *)));
    for (int a = 0; a < (m+2); a++) 
        z[a] = (int *) malloc((m+2) * sizeof(int));
    
    //Iniciando as posições da matriz com o valor 0
    for (int a = 0; a < (n+2); a++) 
        for (int b = 0; b < (m+2); b++)
            z[a][b] = 0;
    
    //Colocando cada posição da matriz de acordo com a tabela do exercício anterior
    z[1][1] = 0; z[1][2] = 1; z[1][3] = 2; z[1][4] = 3; z[1][5] = 4; 
    z[1][6] = 5; z[1][7] = 6; z[1][8] = 7; z[1][9] = 8; z[1][10] = 9; 

    z[2][1] = 1; z[2][2] = 1; z[2][3] = 2; z[2][4] = 3; z[2][5] = 3; 
    z[2][6] = 4; z[2][7] = 5; z[2][8] = 6; z[2][9] = 7; z[2][10] = 8; 

    z[3][1] = 2; z[3][2] = 1; z[3][3] = 2; z[3][4] = 3; z[3][5] = 4; 
    z[3][6] = 4; z[3][7] = 5; z[3][8] = 6; z[3][9] = 7; z[3][10] = 8;

    z[4][1] = 3; z[4][2] = 2; z[4][3] = 2; z[4][4] = 2; z[4][5] = 3; 
    z[4][6] = 4; z[4][7] = 5; z[4][8] = 6; z[4][9] = 7; z[4][10] = 8;

    z[5][1] = 4; z[5][2] = 3; z[5][3] = 2; z[5][4] = 3; z[5][5] = 3; 
    z[5][6] = 4; z[5][7] = 5; z[5][8] = 6; z[5][9] = 7; z[5][10] = 7;

    z[6][1] = 5; z[6][2] = 4; z[6][3] = 3; z[6][4] = 3; z[6][5] = 4; 
    z[6][6] = 3; z[6][7] = 4; z[6][8] = 5; z[6][9] = 6; z[6][10] = 7;

    z[7][1] = 6; z[7][2] = 5; z[7][3] = 4; z[7][4] = 4; z[7][5] = 4; 
    z[7][6] = 4; z[7][7] = 3; z[7][8] = 4; z[7][9] = 5; z[7][10] = 6;

    z[8][1] = 7; z[8][2] = 6; z[8][3] = 5; z[8][4] = 5; z[8][5] = 5; 
    z[8][6] = 5; z[8][7] = 4; z[8][8] = 3; z[8][9] = 4; z[8][10] = 5;

    z[9][1] = 8; z[9][2] = 7; z[9][3] = 6; z[9][4] = 6; z[9][5] = 6; 
    z[9][6] = 6; z[9][7] = 5; z[9][8] = 4; z[9][9] = 3; z[9][10] = 4;

    z[10][1] = 9; z[10][2] = 8; z[10][3] = 6; z[10][4] = 7; z[10][5] = 7; 
    z[10][6] = 7; z[10][7] = 6; z[10][8] = 5; z[10][9] = 4; z[10][10] = 3;

    imprimeOperacoes(z, n, m);

    return 0;

}

void imprimeOperacoes(int **z, int n, int m) {
    int custo = -1;
    int i = n + 1;
    int j = m + 1;
    while (custo != 0) {
        custo = z[i][j];
        //Verifica se foi um casamento de caracteres
        if (custo == z[i-1][j-1]){
            printf("Casamento de caracteres\n");
            custo = z[i-1][j-1];
            i--;
            j--;
        }
        //Verifica se foi uma substituição de caracteres
        else if (custo == z[i-1][j-1] + 1){
            printf("Substituicao de caracteres\n");
            custo = z[i-1][j-1];
            i--;
            j--;
        }
        //Verifica se foi uma inserção de caracteres
        else if (custo == z[i][j-1] + 1){
            printf("Insercao de caracteres\n");
            custo = z[i][j-1];
            j--;
        }
        //Verifica se foi uma remoção de caracteres
        else if (custo == z[i-1][j] + 1){
            printf("Remocao de caracteres\n");
            custo = z[i-1][j];
            i--;
        }      
    }
    return;
}