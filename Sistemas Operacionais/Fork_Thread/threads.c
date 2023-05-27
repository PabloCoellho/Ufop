#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

int saldo = 0;

void * aumentar();
void * diminuir();
void * imprimir();


int main() {

	int argumento = 0; //argumento criado para preencher a criação dos threads
	pthread_t incremento, decremento, impressao; 
		
	pthread_create(&incremento, NULL, aumentar, (void *)(&argumento)); //Local onde os threads são criadas
	pthread_create(&decremento, NULL, diminuir, (void *)(&argumento));
	pthread_create(&impressao, NULL, imprimir, (void *)(&argumento));
	
	pthread_join(incremento, NULL); //O join que faz com que um threads seja executado por vez, primeiro
	pthread_join(decremento, NULL); //um começa e termina para a outro poder começar e também terminar,
	pthread_join(impressao, NULL); //so quando todao terminarem que o programa retorna a sua execução normal

	return 0;
}

void * aumentar () { //Função de incremento no saldo
	
	for (int i = 0; i < 1000; i++) 
		saldo += 100;

	printf("TID da incrementacao: %ld\n", pthread_self());
	//printf("Saldo = %d\n", saldo);
	pthread_exit(NULL);
}

void * diminuir() { //Função de decremento no saldo

	for (int i = 0; i < 1000; i++) 
		saldo -= 100;

	printf("TID da decrementacao: %ld\n", pthread_self());
	//printf("Saldo = %d\n", saldo);
	pthread_exit(NULL);

}

void * imprimir() { //Função de impressão do saldo
	printf("TID da impressao do saldo: %ld\n", pthread_self());
	printf("Saldo = %d\n", saldo);
	pthread_exit(NULL);
}