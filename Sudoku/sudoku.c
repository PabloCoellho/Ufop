#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

int main() {
	int **A;
	char arquivo[20], comando[20];
	Regiao x;

	//Lendo o nome do arquivo texto que contem a matriz do jogo.
	printf("Indique o arquivo texto contendo o jogo: ");
	scanf("%s", arquivo);	

	//Alocando memória para a matriz.
	alocaMatriz(&A);

	//Lendo a matriz contida no arquivo digitado pelo usuário.
	lerMatriz(A, arquivo);

	//Imprimindo a matriz lida.
	imprimir(A);
	printf("Digite um comando ou indique a celula a alterar: ");
	scanf("%s", comando);

	//Comando de repetição para trabalhar com a entrada do usuário.
	while (strcmp(comando, "sair") != 0) {
		int f = 0;
		if (strcmp(comando, "salvar") == 0) { 

			//Salvando a matriz a pedido do usuário.
			salvaMatriz(A, arquivo);
			printf(YELLOW ("Jogo foi salvo em %s\n"), arquivo);
		}	
		
		//Confirmando se o usuário digitou uma entrada correta.
		else if (strlen(comando) == 3) { 
			int c = 0;
			for (int i = 0; i < 3; i++) {

				//Verificando se o usuário entrou com números válidos para o jogo.
				if (comando[i] >= '1' && comando [i] <= '9') 
					c++;
			}

			//Se c < 3, não foram digitados 3 números válidos pelo usuário.
			if (c < 3)
				printf(RED ("Erro! A posicao ou o valor digitado e invalido.\n"));

			//Verificando o local indicado pelo usuário de acordo com as regras do jogo.
			else if (c == 3 && verifica(A, comando, x) == 1) 
				imprimir(A);
		}

		else 
			printf(RED ("ERRO! A posicao ou o valor digitado e invalido.\n"));

		//Verificando se as posicões estão todas completas, ou seja, sem nenhum 0.
		for (int i = 0; i < n; i++) { 
			for (int j = 0; j < n; j++) {
				if (A[i] [j] == 0)
					f++;
			}
		}

		//Se não tiver entrado na condição acima o f será igual a 0 e a matriz não terá mais posições vazias.
		if (f == 0) {
			printf(YELLOW ("\nParabens! Voce terminou o jogo.\n\n")); 
			printf("Digite um comando: ");
			scanf("%s", comando);
		}
	
		else {
			printf("Digite um comando ou indique a celula a alterar: ");
			scanf("%s", comando);
		}
	} 

	//Desalocando a matriz alocada inicialmente.
	desalocaMatriz(A);

	return 0;
}
