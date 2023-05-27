#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define N 5 //Quantidade de Filósofos
#define PENSAR 0
#define FOME 1
#define COMER 2
#define ESQUERDA (nfilosofo + 4) % N //Pegar o garfo da esquerda
#define DIREITA (nfilosofo + 1) % N  //Pegar o garfo da direita

void *filosofo(void *num);
void pegaGarfo(int);
void soltaGarfo(int);
void testar(int);

sem_t mutex;
sem_t S[N]; // Inicializacao do semáforo
int estado[N]; // Estado do filósofo -> utilizado para garfos
int nfilosofo[N] = {0, 1, 2, 3, 4};

// sem_wait(sem_t *sem) -> Aguarda semáforo ter valor superior a zero e decrementa quando tiver valor > 0 (Down).
// sem_post(sem_t *sem) -> Libera um semáforo incrementando 1 unidade (Up).
// (sem_t *sem, int pshared, unsigned int value) -> Inicia um semáforo `sem` com valor `value` e 
// compartilhamento em diferentes threads de um processo ou um processo `pshared`.
// Quando `pshared` recebe 0, é permitido compartilhamento do semáforo entre diferentes threads de um processo.
// Quando `pshared` recebe != 0, é permitido compartilhamento do semáforo entre diferentes processos.

//Cria o Filósofo (thread)
void *filosofo(void *num) {
    while (1) {
        int *i = num;
        sleep(1);
        pegaGarfo(*i);
        sleep(1);
        soltaGarfo(*i);
    }
}

//Aguarda permissão para comer
void pegaGarfo(int nfilosofo) {
    sem_wait(&mutex);
    estado[nfilosofo] = FOME;
    printf("Filosofo %d esta com fome.\n", nfilosofo + 1); //+1 para imprimir filosofo 1 e nao filosofo 0
    testar(nfilosofo);
    sem_post(&mutex);
    sem_wait(&S[nfilosofo]);
    sleep(1);
}

// Quando terminou de comer, analisa filósofos à esquerda e direita.
void soltaGarfo(int nfilosofo) {
    sem_wait(&mutex);
    estado[nfilosofo] = PENSAR;
    printf("Filosofo %d deixou os garfos %d e %d.\n", nfilosofo + 1, ESQUERDA + 1, nfilosofo + 1);
    printf("Filosofo %d esta pensando.\n", nfilosofo + 1);
    testar(ESQUERDA);
    testar(DIREITA);
    sem_post(&mutex);
}

//Teste para ver se o filosofo pode pegar os garfos para comer
void testar(int nfilosofo) {
    if (estado[nfilosofo] == FOME && estado[ESQUERDA] != COMER && estado[DIREITA] != COMER) {
        estado[nfilosofo] = COMER;
        sleep(2);
        printf("Filosofo %d pegou os garfos %d e %d.\n", nfilosofo + 1, ESQUERDA + 1, nfilosofo + 1);
        printf("Filosofo %d esta comendo.\n", nfilosofo + 1);
        sem_post(&S[nfilosofo]);
    }
}

int main() {
    int i;
    pthread_t thread_id[N]; //identificadores das threads

    sem_init(&mutex, 0, 1); //inicia semaforo mutex com valor 1 e permitindo compartilhamento entre thread (0)

    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0); //inicia semaforo S[i] com valor 0 e permitindo compartilhamento entre thread (0)

    for (i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, filosofo, &nfilosofo[i]); //cria as threads
        printf("Filosofo %d esta pensando.\n", i + 1);
    }

    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL); //para fazer a junção das threads

    return (0);
}