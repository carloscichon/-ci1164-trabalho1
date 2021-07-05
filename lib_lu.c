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

// aloca um sistema triangular
S_tri *alocaLU(int n){
    S_tri *sistema;
    // aloca os ponteiros para as linhas
    sistema->coef = malloc(n * sizeof(double*));
    // aloca cada uma das linhas
    for (int i = 0; i < n; i++)
        sistema->coef[i] = malloc(i+1 * sizeof(double));
    sistema->n = n;

    return sistema;
}

void printTri(S_tri *sistema){
    for (int i = 0; i < sistema->n; i++){
        for (int j = 0; i < i+1; j++){
            printf("%f ", sistema->coef[i][j]);
        }
    }
    
}

// encontra o maior pivo
int encontraMax(double **A, int i, int n){
  double numLinha=0;
  int maior=0;
  for (int j = i; j < n; j++){
    if (A[j][i] >= numLinha){
      maior = j;
      numLinha = A[j][i];
    }
  }
  return maior;
}

// triangularizacao
int triangulariza(double **entrada, int n, S_tri *L, int pivo){
    for (int i = 0; i < n; i++){
        /*if (pivo){
            pivo = encontraMax(entrada, i, n);
            if(pivo != i){
                // troca linha
            }
        }*/

        for (int k=i+1; k < n; k++){
            printf("Teste : %lf\n", entrada[k][i]);
            double m = entrada[k][i] / entrada[i][i];
            printf("Teste i,j: %d,%d\n", k,i);
            L->coef[k][i] = m;
            entrada[k][i] = 0.0;
            for (int j = i+1; j < n; j++)
                entrada[k][j] -= entrada[i][j] * m;
            //gauss->b[k] -= gauss->b[i] * m;
    }
        
        
    }
    
}
