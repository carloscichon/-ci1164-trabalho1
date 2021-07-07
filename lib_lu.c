#include "lib_lu.h"

/*!
  \brief Alocação de uma matriz quadrada.
  \param n Tamanho da matriz nxn.
  \return Retorna a matriz alocada dinamicamente.
*/
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

/*!
  \brief Liberação da memória alocada para uma matriz quadrada.
  \param matriz A matriz a ser liberada
  \return - se a liberação funcionou. 1 se não.
*/
int liberaMatriz(double **matriz){
    free(matriz[0]);
    free(matriz);
    if(matriz == NULL)
        return 0;
    return 1;
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
  \param n Tamanho da matriz nxn.
  \param m Matriz a ser printada
*/
void printMatriz(double **m, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%lf ", m[i][j]);
        }
        printf("\n");
    }
    
}

/*!
  \brief Inicializa um Sistema Triangular
  \param sistema O sistema a ser inicializado.
*/
void initLu(S_tri *sistema){
    for (int i = 0; i < sistema->n; ++i) {
        for (int j = 0; j <= i; ++j){
            if(i == j)
                sistema->coef[i][j] = 1.0;
            else
                sistema->coef[i][j] = 0.0;
        }
    }  
}

/*!
  \brief Printa na saída padrão um Sistema Triangular
  \param sistema Sistema a ser impresso.
*/
void printTri(S_tri *sistema){
    for (int i = 0; i < sistema->n; i++){
        for (int j = 0; j < i+1; j++){
            printf("%f ", sistema->coef[i][j]);
        }
        printf("\n");
    }
}

/*!
  \brief Alocação de um sistema triangular.
  \param n Tamanho da matriz nxn.
  \return Retorna o sistema alocado dinamicamente ou NULL caso haja algum erro.
*/
S_tri *alocaLUPadrao(int n){
    S_tri *sistema = malloc(sizeof(S_tri));
    
    sistema->coef = malloc(n * sizeof(double*));
    for (int i = 0; i < n; ++i) {
        sistema->coef[i] = malloc((i+1) * sizeof(double*));
    }
    if(sistema == NULL)
        return NULL;
    
    sistema->n = n;
    initLu(sistema);
    printTri(sistema);
    return sistema;
}

/*!
  \brief Encontra o pivo para o pivoteamento parcial.
  \param A Matriz a ser encontrado o pivo.
  \param i Número da coluna que está sendo testada.
  \param n Tamanho da matriz nxn.
  \return Retorna o maior valor abaixo de i.
*/
int encontraMax(double **A, int i, int n){
  double numLinha=0;
  int maior=0;
  for (int j = i; j < n; j++){
    if (A[j][i] > numLinha){
      maior = j;
      numLinha = A[j][i];
    }
  }
  return maior;
}

/*!
  \brief Copia um vetor em outro.
  \param a Vetor fonte.
  \param b Vetor destino.
  \param n Tamanho do vetor.
*/
void copyV(double *a, double *b, int n){
  for (int i = 0; i < n; i++)
    b[i] = a[i];
}

/*!
  \brief Troca duas linhas de uma matriz.
  \param matriz Matriz a ter linhas trocadas.
  \param n Tamango da matriz nxn.
  \param i Número da linha a ser trocada.
  \param i Número da outra linha a ser trocada.
*/
void trocaLinha(double **matriz, int n, int i, int iPivo){
  double *auxVet = malloc(n * sizeof(double));
  double aux;
  
  copyV(matriz[i], auxVet, n);
  copyV(matriz[iPivo], matriz[i], n);
  copyV(auxVet, matriz[iPivo], n);
  free(auxVet);
  
  // aqui troca as linhas do vetor de resultados
  /*aux = SL->b[i];
  SL->b[i] = SL->b[iPivo];
  SL->b[iPivo] = aux;*/

}

/*!
  \brief Realiza a triangularização de uma matriz e salva as operações num Sistema Triangular.
  \param entrada Matriz a ter linhas trocadas.
  \param n Tamango da matriz nxn.
  \param L Sistema Triangular que receberá as operações (L da fatoração LU).
  \param pivo Flag de pivoteamento parcial
*/
int triangulariza(double **entrada, int n, S_tri *L, int pivo){
    for (int i = 0; i < n; i++){
        if (pivo){
            pivo = encontraMax(entrada, i, n);
            if(pivo != i){
                trocaLinha(entrada, n, i, pivo);
            }
        }
        
        for (int k=i+1; k < n; k++){
            double m = entrada[k][i] / entrada[i][i];
            L->coef[k][i] = m;
            entrada[k][i] = 0.0;
            for (int j = i+1; j < n; j++)
                entrada[k][j] -= entrada[i][j] * m;
        }
    }
}

// passar as n colunas da matriz indentidade para calcular a matriz Y 
/*
void retrosSubsL(S_tri *sistema, double *y){
  for (int i = 0; i < SL->n; ++i){
    y[i] = SL->b[i];
    for (int j = i+1; j < SL->n; j++)
      y[i] -= matriz[i][j] * y[j];
    y[i] /= matriz[i][i];
  }
}

// passar as n colunas da matriz Y para calcular a matriz X
void retrossubs(SistLinear_t *SL, double *x){
  for (int i = SL->n-1; i >= 0; i--){
    x[i] = SL->b[i];
    for (int j = i+1; j < SL->n; j++)
      x[i] -= matriz[i][j] * x[j];
    x[i] /= matriz[i][i];
  }
}*/