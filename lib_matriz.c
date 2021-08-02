#include "lib_matriz.h"

/*!
  \brief Alocação de uma matriz quadrada.
  \param n Número de colunas da matriz nxn.
  \param m Número de linhas da matriz nxn.
  \return Retorna a matriz alocada dinamicamente.
*/
double **alocaMatriz(int n, int m){
    // aloca um vetor de n ponteiros para linhas
    double **matriz = malloc(m * sizeof(double*));
    /*if(matriz = NULL)
        return NULL;*/
    // aloca um vetor com todos os elementos da matriz
    matriz[0] = malloc(m * n * sizeof(double));
    
    /*if(matriz[0] = NULL)
        return NULL;*/
    // ajusta os demais ponteiros de linhas
    for (int i = 1; i < m; i++)
        matriz[i] = matriz[0] + i * n;
    return matriz;
}

/*!
  \brief Liberação da memória alocada para uma matriz quadrada.
  \param matriz A matriz a ser liberada
  \return - se a liberação funcionou. 1 se não.
*/
void liberaMatriz(double **matriz, unsigned int n){
    free(matriz);
}

/*!
  \brief Leitura de uma matriz quadrada.
  \param n Número de colunas da matriz nxn.
  \param m Número de linhas da matriz nxn.
  \return Retorna a matriz com os valores lidos ou NULL caso haja algum erro.
*/
double **leMatriz(int n, int m){
    double **matriz = alocaMatriz(n, m);
    if(matriz == NULL)
        return NULL;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &matriz[i][j]);
        } 
    }
    return matriz;
}

/*!
  \brief Printa na saída padrão uma matriz quadrada (debug)
  \param m Matriz a ser printada
  \param n Número de colunas da matriz nxn.
  \param lin Número de linhas da matriz nxn.
*/
void printMatriz(double **m, int n, int lin, FILE *saida){
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < n; j++){
            fprintf(saida, "%lf ", m[i][j]);
        }
        fprintf(saida, "\n");
    }
    fprintf(saida, "##################################\n"); 
    
}

double *leValoresTab(int n){
    double *valores = malloc(n * sizeof(double));
    if(valores == NULL)
        return NULL;
    for (int i = 0; i < n; i++){
        scanf("%lf", &valores[i]);
    }
    return valores;
}
