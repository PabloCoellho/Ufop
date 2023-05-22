# ifndef ordenacao_h
# define ordenacao_h

void ordenacao(int *vetor, int n, int *movimentos);
//Manter como especificado
int *alocaVetor(int *vetor, int n);
//Manter como especificado
int *desalocaVetor(int *vetor);
//Duas funções adicionais 
void MERGESORT(int *vetor, int l, int r, int *movimentos);
void MERGE(int *vetor, int l, int m, int r, int *movimentos);
# endif