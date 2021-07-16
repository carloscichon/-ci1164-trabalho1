#include "lib_sTri.h"

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

void liberaLU(S_tri *L, int n){
  for (int i = 0; i < n; i++){
    free(L->coef[i]);
  }
  free(L);
}
