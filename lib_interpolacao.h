#include "lib_matriz.h"
#include "lib_lu.h"
#include <math.h>

double **montaSistema(double *valoresTab, unsigned int n);

void interpolacao(double *valoresTab, double *func, unsigned int n, unsigned pivo, FILE *saida);