#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "lib_matriz.h"
#include "lib_sTri.h"

// funcoes da fatoracao LU
int triangulariza(double **entrada, int n, S_tri *L, int pivo, double **ident);
int encontraMax(double **A, int i, int n);
int fatoracaoLU(double **entrada, int n, S_tri *L, int pivo, FILE *saida);
