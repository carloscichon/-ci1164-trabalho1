#include "lib_lu.h"

// aloca uma matriz de double
double **alocaMatriz(int n){
    // aloca um vetor de n ponteiros para linhas
    double **matriz = malloc(n * sizeof(double*));
    // aloca um vetor com todos os elementos da matriz
    matriz[0] = malloc(n * n * sizeof(double));
    // ajusta os demais ponteiros de linhas
    for (int i = 1; i < n; i++)
        matriz[i] = matriz[0] + i * n;
    return matriz;
}

// libera a memória de uma matriz
void liberaMatriz(double **matriz){
    free(matriz[0]);
    free(matriz);
}

// realiza a leitura da matriz entrada
double **leMatriz(int n){
    double **matriz = alocaMatriz(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
    return matriz;
}

// printa a matriz de entrada (debug)
void printMatriz(double **m, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%lf ", m[i][j]);
        }
        printf("\n");
    }
    
}