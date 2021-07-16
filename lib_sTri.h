#include <stdlib.h>
#include <stdio.h>
typedef struct S_tri{
    double **coef;
    unsigned int n;
} S_tri;

// funções de tratamento dos sitemas triangulares
S_tri *alocaLU(int n);
S_tri *alocaLUPadrao(int n);
void liberaLU(S_tri *L, int n);
void printTri(S_tri *sistema);