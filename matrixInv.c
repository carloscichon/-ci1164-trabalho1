#include "lib_interpolacao.h"
#include "lib_ajuste.h"
#include <likwid.h>
#include <likwid-marker.h>

int main(int argc, char **argv){
    char c;
    FILE *saida = stdout;
    int pivo = 0;
    pegaParametrosDeExecucao(argc, argv, &pivo, saida);
    int n, m;
    double *valoresTabelados;
    double **entrada;
    S_tri *L;
    while(fscanf(stdin, "%c", &c) != EOF){
        if (c >= 48 && c <= 57){
            ungetc(c, stdin);
            scanf("%d %d", &n, &m);
            valoresTabelados = leValoresTab(n);
            entrada = leMatriz(n, m);
            //printVetor(valoresTabelados, n);
            //printMatriz(entrada, n, m, stdout);
            // erro de alocacao
            if(entrada == NULL || L == NULL){
                fprintf(stderr, "Falha na alocação de memória\n");
                return 4;
            }
            for (int i = 0; i < m; ++i) {
                //LIKWID_MARKER_INIT;
                interpolacao(valoresTabelados, entrada[i], n, pivo, saida);
                ajusteCurvas(valoresTabelados, entrada[i], n, pivo, saida);
                //LIKWID_MARKER_CLOSE;


            }
            free(entrada);
            free(valoresTabelados);
        }
    }
}