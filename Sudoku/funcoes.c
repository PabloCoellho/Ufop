#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaracoes.h"

//A função lê a matriz que está dentro do arquivo indicado pelo usuário.
void lerMatriz(int **A, char arquivo[20]) {
	FILE *entrada = fopen(arquivo, "r");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				fscanf(entrada, "%d", &A[i][j]);
		}
	fclose(entrada);
}

//A função verifica se o usuário pode colocar o número passado nos locais indicados.
int verifica(int **A, char comando[20], Regiao x){  
	int *posicao, a = 0, b = 0;

	alocaVetor(&posicao); //Alocando memória para o vetor.

	for (int i = 0; i < 3; i++) 
		posicao[i] = comando[i] - 48;  //Convertendo caractere para número inteiro.

	
	if (A[posicao[0]-1] [posicao[1]-1] != 0) {  //Verificando se o local ja está ocupado.
		printf(RED ("ERRO! A celula %d,%d ja possui valor.\n"), posicao[0], posicao[1]);
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {  //Andando na linha informada a procura do número passado pelo usuário.
			if (A[posicao[0]-1] [i] == posicao[2])
				a++;
		}
			
		//Se a != 0, significa que entrou na condição acima, pois encontrou o número passado pelo usuário na linha informada.
		if (a != 0) {  
			printf(RED ("Erro! A linha %d ja possui o valor %d.\n"), posicao[0], posicao[2]);	
			return 0;
		}
		else {
			for (int j = 0; j < n; j++) {  //Andando na coluna informada a procura do número passado pelo usuário.
				if (A[j] [posicao[1]-1] == posicao[2])
					b++;
			}

			//Se b != 0, significa que entrou na condição acima, pois encontrou o número passado pelo usuário na coluna informada.
			if (b != 0) {  
				printf(RED ("Erro! A coluna %d ja possui o valor %d.\n"), posicao[1], posicao[2]);
				return 0;
			}
			else {
				int cont = 0;
				
				//Iniciando a estrutura região com os valores necessários para poder verificar as regiões do jogo.
				iniciaRegiao(&x);

				//Se a função retornar 0 é porque achou o número passado pelo usuário na região do local passado por ele.
				if (verifreg(A, &cont, posicao, x) == 0)
					printf(RED ("Erro! A regiao %d ja possui o valor %d.\n"), cont, posicao[2]);
				
				//Se não entrar na condição acima, a função retornou 1 e o local indicado pelo usuário está ok.
				else {

					//Colocando o valor passado no local informado pelo usuário.
					A[posicao[0]-1] [posicao[1]-1] = posicao[2]; 

					desalocaVetor(posicao); //Desalocando o vetor, caso o progragra passe pelo else e ja retorne 1.
					return 1;
				}
			}
		}
	}
	desalocaVetor(posicao); //Desalocando o vetor, caso o progragra não entre em nenhuma das condições acima.
	return 0;
}

//Função descobre em qual submatriz esta a posição digitada pelo usuário e verifica a região da posição.
int verifreg(int **A, int *cont, int *posicao, Regiao x) { 
	int u = 0, k = 0, w = 0; //Iniciando as variáveis com o valor 0.
	while (w < n) {
		/*As regiões 1, 2 e 3 têm o mesmo valor de linha inicial e final, portanto apenas as colunas variam.
		As regiões 4, 5 e 6 têm o mesmo valor de linha inicial e final, com isso, apenas as colunas variam.
		Mesmo caso para as regiões 7, 8 e 9.
		As colunas variam de 0 a 3, de 3 a 6 e de 6 a 9, após isso votam para o caso inicial e repete os valores mais duas vezes.
		As variáveis foram criadas para que as linhas, colunas e a repetição pudessem funcionam sem prejudicar umas a outras.*/

		(*cont)++; //Contador utilizado para retornar qual região já possui o número, caso alguma possuir.
		if (w == 3) { //Quando o w é igual a 3 é preciso aumentar a linha e zerar a coluna.
			u = 1;
			k = 0;
		}
		else if (w == 6) { //Quando w é igual a 6 novamente aumenta a linha e zera a coluna.
			u = 2;
			k = 0;
		}
		for (int i = x.li[u]; i < x.lf[u]; i++) {
			for (int j = x.ci[k]; j < x.cf[k]; j++) {   //Andando pelas posições da matriz. 
				
				
				//Verificando se a posição pertence a submatriz, se não volta ao loop até completar um total de 9 vezes.
				if (i == posicao[0]-1 && j == posicao[1]-1) {
						
					//Como entrou na condição acima a posição pertence a respectiva região.
					for (int y = x.li[u]; y < x.lf[u]; y++) {
						for (int l = x.ci[k]; l < x.cf[k]; l++) {

							//Verificando a região em busca do número passado pelo usuário, caso não tiver retorna 1.
							if (A[y] [l] == posicao[2])
								return 0; //Se ja conter o número na região, a função retornará 0.
						}
					}
				}  
			}
		}
		k++;
		w++;
	}
	return 1;
}

//Função que aloca as posições da matriz.
void alocaMatriz(int ***A) {
	*A = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) 
		(*A)[i] = malloc(n * sizeof(int));
}

//Função que imprime a matriz tirando o 0 e colocando '_' e adicionando algumas personalizaçoes.
void imprimir(int **A) {
	for (int i = 0; i <= 30; i++) {
		if(i == 0)
			printf(TAB_TL);
		else if ( i == 10 || i == 20)
			printf(TAB_TJ);
		else if (i == 30)
			printf(TAB_TR);
		else
			printf(TAB_HOR);
	}

	//Para imprimir as regiões da matriz dentro de quadrados foi necessário o uso de algumas condições, o que aumentou um pouco o código.
	for (int i = 0; i < n; i++) {     
		printf("\n");
		int k = 0;
		for (int j = 0; j <= 30; j++) { //Esse for percorre a coluna inteira, cada espaço ou caractere.
			if((i == 3 || i == 6) && (j == 10 || j == 20))
				printf(TAB_MJ); //Adiciona a cruz, para ligar as linhas horizontais do centro com as verticais também do centro.
			else if ((j == 0 && i == 3) || (j == 0 && i == 6))
				printf(TAB_ML); //Adiciona a ligação da linha vertical da primeira coluna com as linhas horizontais.
			else if ((j == 30 && i == 3) || (j == 30 && i == 6))
				printf(TAB_MR); //Adiciona a ligação da linha vertical da última coluna com as linhas horizontais.
			else if (i == 3 || i == 6)
				printf(TAB_HOR); //Adiciona a ultima linha vertical após a última coluna da matriz.
		}
		
		//Os locais onde estão escrito "BLUE", "YELLOW" e "RED" foram adicionados efeitos para a impressão sair personalizada.
		if (i == 3 || i == 6)
			printf("\n");
		for (int j = 0; j < n; j++) {
			if (k == 3 || k == 6)
				printf(TAB_VER); //Adiciona as linhas verticais de dentro da matriz.
			if (j == 0) {
				if (A[i][j] != 0)
					printf(TAB_VER BLUE ("%2d "), A[i][j]); //Adiciona a primeira linha vertical caso for impresso um número.				else
				else
					printf(TAB_VER RED (" _ ")); //Adiciona a primeira linha vertical caso for impresso ' _ '.
			}
			else if (j == 8) {
				if (A[i][j] != 0)
					printf(BLUE ("%2d ")TAB_VER, A[i][j]); //Adiciona a última linha vertical caso for impresso um número.
				else
					printf(RED (" _ ") TAB_VER); //Adiciona a última linha vertical caso for impresso ' _ '.
			}
			else if (A[i][j] != 0)
				printf(BLUE ("%2d "), A[i][j]); //Imprimi os números centrais de cada região.
			else
				printf(RED (" _ ")); //Imprimi ' _ ' em cada região, caso for um espaço vazio do jogo.
			k++;
		}
	}
	printf("\n");
	for (int i = 0; i <= 30; i++) {
		if(i == 0)
			printf(TAB_BL); //Adiciona a ligação da linha vertical da primeira coluna com a linha horizontal de baixo.
		else if ( i == 10 || i == 20)
			printf(TAB_BJ); //Adiciona a ligação das linhas das colunas com a linha horizontal da parte de baixo.
		else if (i == 30)
			printf(TAB_BR); //Adiciona a ligação da linha horizontal da parte de baixo  com a linha vertical da última coluna.
		else
			printf(TAB_HOR); //Adiciona a linha horizontal de baixo da matriz do jogo.
	}

	printf("\n");
}

//Função que inicia os valores necessários nos vetores.
void iniciaRegiao(Regiao *x) {
	int j = 0;
	for (int i = 0; i < 3; i++) {
		x->li[i] = j;
		x->ci[i] = j;
		x->lf[i] = j+3;
		x->cf[i] = j+3;
		j+=3;
	}
}

//Função que desaloca as posições da matriz, limpando a memória.
void desalocaMatriz(int **A) {
	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);
}

//Função que aloca o vetor na memória.
void alocaVetor(int **vetor) {
	*vetor = malloc(n * sizeof(int));
}

//Função que desaloca o vetor da memória.
void desalocaVetor(int *vetor) {
	free(vetor);
}

//Função que salva a matriz no arquivo indicado pelo usuário.
void salvaMatriz(int **A, char *arquivo) {
	FILE *entrada = fopen(arquivo, "w");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			fprintf(entrada, "%d ", A[i] [j]);
		fprintf(entrada, "\n");
	}
	fclose(entrada);
}