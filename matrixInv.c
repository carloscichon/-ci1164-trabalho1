#include "lib_lu.h"

int main(int argc, char **argv){
    char c;
    FILE *saida = stdout;
    int pivo = 0;

    pegaParametrosDeExecucao(argc, argv, pivo, saida);
    
    int n;
    double **entrada;
    S_tri *L;

    while(fscanf(stdin, "%c", &c) != EOF){
        if (c >= 48 && c <= 57){
            ungetc(c, stdin);
            scanf("%d", &n);
            L = alocaLUPadrao(n);
            entrada = leMatriz(n);

            // erro de alocacao
            if(entrada == NULL || L == NULL){
                fprintf(stderr, "Falha na alocação de memória\n");
                return 4;
            }
            fatoracaoLU(entrada, n, L, pivo, saida);
            free(entrada);
            liberaLU(L, n);
        }
    }
}