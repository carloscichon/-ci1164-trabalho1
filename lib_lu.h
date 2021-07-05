#include <stdlib.h>
#include <stdio.h>

typedef struct S_tri{
    double **coef;
    unsigned int n;
} S_tri;

// funções de tratamento da matriz de entrada
double **alocaMatriz(int n);
void liberaMatriz(double **matriz);
double **leMatriz(int n);
void printMatriz(double **m, int n);

// funções de tratamento dos sitemas triangulares
S_tri *alocaLU(int n);