# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
	char nome[65];
    int ouro;
    int prata;
    int bronze;
} paises;

paises *alocarpaises(paises *pais, int n);

paises *lerpaises (paises *pais, int n);

void ordenarpaises (paises *pais, int n);

void impressao (paises *pais, int n);

paises *desalocarpaises (paises *pais);

# endif


