#include "lib_interpolacao.h"

/*!
    \brief
*/
double **montaSistema(double *valoresTab, unsigned int n){
    double **saida = alocaMatriz(n, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            saida[i][j] = pow(valoresTab[i], j);
        }
    }

    return saida;
}

void interpolacao(double *valoresTab, double *func, unsigned int n, unsigned pivo, FILE *saida){
    double **sistema = montaSistema(valoresTab, n);
    S_tri *L = alocaLUPadrao(n);
    fatoracaoLU2(sistema, n, L, pivo, func, saida);
    liberaLU(L, n);
}