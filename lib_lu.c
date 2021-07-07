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
  \param m Matriz a ser printada
  \param n Tamanho da matriz nxn.
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
    //printTri(sistema);
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
  \param n Tamanho da matriz nxn.
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

/*!
  \brief Preenche com 1s a matriz identidade
  \param matriz Matriz identidade
  \param n Tamanho da matriz identidade
*/
void preencheIdent(double **matriz, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if(i == j)
        matriz[i][j] = 1.0;
}

/*!
  \brief Printa um vetor (debug)
  \param v Vetor a ser printado
  \param n Tamanho do vetor
*/
void printVetor(double *v, int n){
  for (int i = 0; i < n; i++){
    printf("%lf ", v[i]);
  }
  printf("\n");
}

/*!
  \brief Realiza a retrossubstituição em L para obter Y
  \param sistema Sistema triangular L
  \param b Coluna da matriz identidade
  \param y Vetor Y a ser obtido
  \param n Tamanho dos vetores
*/
void retrosSubsL(S_tri *sistema, double *b, double *y, int n){
  for (int i = 0; i < n; ++i){
    y[i] = b[i];
    for (int j = 0; j < i; j++)
      y[i] -= sistema->coef[i][j] * y[j];
    y[i] /= sistema->coef[i][i];
  }
}

/*!
  \brief Realiza a retrossubstituição em U para obter X
  \param a Matriz U
  \param y Vetor Y
  \param x Vetor X a ser obtido
  \param n Tamanho dos vetores
*/
void retrosSubsU(double **a, double *y, double *x, int n){
  for (int i = n-1; i >= 0; i--){
    x[i] = y[i];
    for (int j = i+1; j < n; j++)
      x[i] -= a[i][j] * x[j];
    x[i] /= a[i][i];
  }
  //printVetor(x, n);

}

/*!
  \brief Copia um vetor para uma coluna de matriz
  \param m Matriz destino
  \param v Vetor a ser copiado
  \param n Tamanho da matriz e do vetor
  \param i Numero da coluna a ser copiado
*/
void copyCol(double **m, double *v, int n, int i){
  for (int j = 0; j < n; j++)
    m[j][i] = v[j];
}

/*!
  \brief Aplica a fatoração LU para descobrir a matriz inversa
  \param entrada Matriz U
  \param n Tamanho da matriz e do Sistema Triangular
  \param L Sistema Triangular L
*/
int fatoracaoLU(double **entrada, int n, S_tri *L){
  double *Y, *X, **ident, **saida;
  Y = malloc(n * sizeof(double));
  X = malloc(n * sizeof(double));
  ident = alocaMatriz(n);
  saida = alocaMatriz(n);
  preencheIdent(ident, n);

  for (int i = 0; i < n; i++){
    retrosSubsL(L, ident[i], Y, n); // transposta da identidade é ela mesma
    retrosSubsU(entrada, Y, X, n);
    copyCol(saida, X, n, i);
  }
  printMatriz(saida, n);
}
