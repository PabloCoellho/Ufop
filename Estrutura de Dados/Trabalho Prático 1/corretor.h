# ifndef sub_h
# define sub_h

typedef struct sub TADsub;

void lerqtd(int *n);

TADsub *alocartad(TADsub *S, int n);

void lersubs (TADsub *S, int n);

void julgamento(TADsub *S, int n, int *s, int *p);

void imprimirresul(int s, int p);

TADsub *desalocartad(TADsub *S);

# endif