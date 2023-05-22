#include <stdio.h>

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"

// macros para facilitar o uso
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET

// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)

#define n 9

typedef struct {
	int li[3];
	int lf[3];
	int ci[3];
	int cf[3];
} Regiao;

void alocaMatriz(int ***A);

void lerMatriz(int **A, char arquivo[20]);

int verifica(int **A, char comando[20], Regiao x);

void imprimir(int **A);

void iniciaRegiao(Regiao *x);

void desalocaMatriz(int **A);

void alocaVetor(int **vetor);

void desalocaVetor(int *vetor);

int verifreg(int **A, int *cont, int *posicao, Regiao x);

void salvaMatriz(int **A, char arquivo[20]);