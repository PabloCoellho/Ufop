# ifndef fib_h
# define fib_h

typedef struct{
  double resultado;
  double chamadas;
  
} TADfib;

double fibonacci(int i, TADfib *f);

# endif
