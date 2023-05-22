#include "hash.h"
#include <stdio.h>

int main(){
	int i = 0, nro_listas, n;
	//criar variavel para tabela hash
	THash tabela;
	TItem x;
	
	//ler tamanho da tabela hash e a quantidade de chaves
	scanf("%d %d", &nro_listas, &n);
	
	//inicializar a tabela hash
	THash_Inicia(&tabela, nro_listas);

	for(int k = 0; k < n; k++) {
		scanf("%d", &x.chave);
		THash_Insere(&tabela, x);
	}

	while (i < nro_listas) {	
		//imprimir a tabela hash de acordo com a especificacao da saida	
		
		printf("%d -> ", i);
		
		if(TLista_EhVazia(&tabela.v[i])) {
			printf("\\\n");
			
			
		}

		else {	
			TCelula *aux;
			aux = tabela.v[i].pPrimeiro->pProx;

			while (tabela.v[i].pUltimo != aux)	{
				printf("%d -> ", aux->item.chave);
				aux = aux->pProx;
			}

			printf("%d -> \\\n", aux->item.chave);
		}

					
		i++;
	}
		
   	return 0;
}
