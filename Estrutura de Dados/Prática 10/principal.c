#include "prioridade.h"
#include <stdio.h>

int main ()
{
	int n, m, produtos, tempomax = 0;
	TipoCaixa *heap = NULL;

	//ler n e m
	scanf("%d %d", &n, &m);

	//alocar o vetor para o heap com tamanho n
	heap = alocaVetor(heap, n);

	
	//ler o tempo de atendimento de cada caixa
	for (int i = 0; i < n; i++){
		scanf("%d", &heap[i].tempo);
		heap[i].id = i + 1;
		heap[i].tempoaten = 0;
	}

	//criar a fila de prioridades
	Heap_Constroi(heap, n);
	
		
	while (m--) {
		//para cada cliente, ler a quantidade de produtos
		scanf("%d", &produtos);

		//verificar qual caixa estara disponivel primeiro
		heap[0].tempoaten += produtos * heap[0].tempo;
						
		//armazenar qual o tempo maximo para atender todos clientes ate agora
		if (heap[0].tempoaten > tempomax)
			tempomax = heap[0].tempoaten;

		//alterar a disponibilidade do caixa selecionado
		Heap_Constroi(heap, n);
		
	}
	
	//desalocar o vetor do heap
	heap = desalocaVetor(heap);

	//imprimir a resposta
	printf("%d\n", tempomax);

	return 0;
}
