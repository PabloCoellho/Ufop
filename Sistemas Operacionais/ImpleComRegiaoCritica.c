#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#define ITERACOES 100

void *aumenta(void *t);
void *diminui(void *t);
void *imprimi(void *t);

typedef struct {
    int saldo;
} tipoThread;

int main() {
  tipoThread *t = (tipoThread *)malloc(sizeof(tipoThread));
  t->saldo = 0;
  int n;

  do {
    printf("Digite o numero par de threads a ser criado: ");
    scanf("%d", &n);

  } while (n % 2 != 0);

  pthread_t tSoma, tSub, tImp;
  
  for (int i = 0; i < (n * ITERACOES); i++) {

    pthread_join(tSub, NULL);

    pthread_mutex_lock(&mutex);
    pthread_create(&tSoma, NULL, diminui, (void *)t);
    pthread_mutex_unlock(&mutex);

    pthread_join(tSoma, NULL);

    pthread_mutex_lock(&mutex);
    pthread_create(&tSub, NULL, aumenta, (void *)t);
    pthread_mutex_unlock(&mutex);

    pthread_mutex_lock(&mutex);
    pthread_create(&tImp, NULL, imprimi, (void *)t);
    pthread_mutex_unlock(&mutex);
  }

  //printf("\nSaldo Final: %d\n\n", t->saldo);
  return 0;
}

void *aumenta(void *t){
  tipoThread *aux = (tipoThread*)t;
  aux->saldo += 1;
  pthread_exit(0);
}

void *diminui(void *t){
  tipoThread *aux = (tipoThread*)t;
  aux->saldo -= 1;
  pthread_exit(0);
}

void *imprimi(void *t){
  tipoThread *aux = (tipoThread*)t;
  printf("id_T:%d, Saldo = %d\n", (int)pthread_self(), aux->saldo);
  pthread_exit(0);
}