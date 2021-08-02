#include <stdio.h>
#include <stdlib.h>

// funções de tratamento da matriz de entrada
double **alocaMatriz(int n, int m);
void liberaMatriz(double **matriz, unsigned int n);
double **leMatriz(int n, int m);
void printMatriz(double **m, int n, int lin, FILE *saida);
double *leValoresTab(int n);