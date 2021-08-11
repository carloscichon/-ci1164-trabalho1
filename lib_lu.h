#ifndef LIB_LU_H
#define LIB_LU_H

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "lib_matriz.h"
#include "lib_sTri.h"

// funcoes da fatoracao LU
int triangulariza(double **entrada, int n, S_tri *L, int pivo, double *func);
int encontraMax(double **A, int i, int n);
int fatoracaoLU(double **entrada, int n, S_tri *L, int pivo, FILE *saida);
int fatoracaoLU2(double **sistema, int n, S_tri *L, int pivo, double *func, FILE *saida);
void printVetor(double *v, int n, FILE *saida);

#endif