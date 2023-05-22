#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
   alunos = (TipoAluno *) malloc (n * sizeof(TipoAluno));
   return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
  free(alunos);
  return alunos;
}

void ordena(TipoAluno *alunos, int n){
  char aux[20];
  int a, min;
  
  for (int i = 0; i < n; i++) {
    min = i;
    for (int j = i+1; j < n; j++) {
      a = strcmp(alunos[j].nome, alunos[min].nome);
      if(a < 0)
        min = j;
    }
    strcpy(aux, alunos[i].nome);
    strcpy(alunos[i].nome, alunos[min].nome);
    strcpy(alunos[min].nome, aux);    
  }  
}
