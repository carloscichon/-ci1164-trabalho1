#include <stdio.h>
#include <stdlib.h>

// funções de tratamento da matriz de entrada
double **alocaMatriz(int n);
void liberaMatriz(double **matriz, unsigned int n);
double **leMatriz(int n);
void printMatriz(double **m, int n, FILE *saida);