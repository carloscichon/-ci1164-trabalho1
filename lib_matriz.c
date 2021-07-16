#include "lib_matriz.h"

/*!
  \brief Alocação de uma matriz quadrada.
  \param n Tamanho da matriz nxn.
  \return Retorna a matriz alocada dinamicamente.
*/
double **alocaMatriz(int n){
    // aloca um vetor de n ponteiros para linhas
    double **matriz = malloc(n * sizeof(double*));
    /*if(matriz = NULL)
        return NULL;*/
    // aloca um vetor com todos os elementos da matriz
    matriz[0] = malloc(n * n * sizeof(double));
    
    /*if(matriz[0] = NULL)
        return NULL;*/
    // ajusta os demais ponteiros de linhas
    for (int i = 1; i < n; i++)
        matriz[i] = matriz[0] + i * n;
    return matriz;
}

/*!
  \brief Liberação da memória alocada para uma matriz quadrada.
  \param matriz A matriz a ser liberada
  \return - se a liberação funcionou. 1 se não.
*/
void liberaMatriz(double **matriz, unsigned int n){
    /*for (int i = 1; i < n; i++){
      free(matriz[i]);
    }  
    free(matriz[0]);*/
    free(matriz);
    
}

/*!
  \brief Leitura de uma matriz quadrada.
  \param n Tamanho da matriz nxn.
  \return Retorna a matriz com os valores lidos ou NULL caso haja algum erro.
*/
double **leMatriz(int n){
    double **matriz = alocaMatriz(n);
    if(matriz == NULL)
        return NULL;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
    return matriz;
}

/*!
  \brief Printa na saída padrão uma matriz quadrada (debug)
  \param m Matriz a ser printada
  \param n Tamanho da matriz nxn.
*/
void printMatriz(double **m, int n, FILE *saida){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fprintf(saida, "%lf ", m[i][j]);
        }
        fprintf(saida, "\n");
    }
    fprintf(saida, "##################################\n"); 
    
}
