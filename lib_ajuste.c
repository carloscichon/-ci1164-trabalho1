#include "lib_ajuste.h"
#include <likwid.h>
#include <likwid-marker.h>

double somatorio(unsigned int j, unsigned int i, unsigned int n, double *valoresTab){
    double soma = 0.0;
    for (int k = 0; k < n; k++){
        soma += pow(valoresTab[k], j) * pow(valoresTab[k], i);
    }
    return soma;
}

double **montaSistemaAC(double *valoresTab, unsigned int n){
    double soma;
    double **saida = alocaMatriz(n, n);

    // for de colunas da primeira linha
    for (int i = 0; i < n; i++){
        soma = 0.0;
        for (int j = 0; j < n; j++){
            // primeira linha multiplica sempre por 1
            soma += pow(valoresTab[j], i);
        }
        saida[0][i] = soma;
        //printf("saida: %lf\n", saida[0][i]);
    }
    // demais linhas
    for (int i = 1; i < n; i++){
        // copia linha anterior na linha atual
        // a linha seguinte é a anterior mais um termo, por isso j < n-1
        for (int j = 0; j < n-1; j++){
            saida[i][j] = saida[i-1][j+1];
        }
        soma = 0.0;
        for (int k = 0; k < n; k++){
            soma += pow(valoresTab[k], n-1) * pow(valoresTab[k], i);
        }
        saida[i][n-1] = soma;   
    }
    return saida;
}

double *geraTermosIndependentes(double *func, double *valoresTab, unsigned int n){
    double *tIndependentes = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            tIndependentes[i] += func[j] * pow(valoresTab[j], i);
        }
    }
    return tIndependentes;
    
}

void ajusteCurvas(double *valoresTab, double *func, unsigned int n, unsigned pivo, FILE *saida){
    //LIKWID_MARKER_START("GeraCoeficientes");
    double **sistema = montaSistemaAC(valoresTab, n);
    //LIKWID_MARKER_STOP("GeraCoeficientes");
    double *tIndependentes = geraTermosIndependentes(func, valoresTab, n);
    //printMatriz(sistema, n, n, saida);
    //printVetor(tIndependentes, n, saida);
    //printf("Tudo gerado\n");
    S_tri *L = alocaLUPadrao(n);
    fatoracaoLU2(sistema, n, L, pivo, tIndependentes, saida);
    liberaLU(L, n);
}