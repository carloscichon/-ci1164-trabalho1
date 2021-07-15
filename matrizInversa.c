#include "lib_lu.h"
#include <unistd.h>

int main(int argc, char **argv){
    char c;
    FILE *saida = stdout;
    int pivo = 0;
    while ((c = getopt (argc, argv, "o:p")) != -1){
        switch (c){
        case 'o':
            printf("Você ativou a opcao o\n");
            saida = fopen(optarg, "w");
            break;
        case 'p':
            printf("Você ativou a opcao p\n");
            pivo = 1;
            break;
        case '?':
            if (optopt == 'o')
            fprintf (stderr, "Opção -%c precisa de um argumento.\n", optopt);
            else
            fprintf (stderr, "Opção desconhecida. %c\n", optopt);
            return 1;
        default:
            break;
        }
    }
    int n;
    double **entrada;
    S_tri *L;
    scanf("%d", &n);
    L = alocaLUPadrao(n);
    entrada = leMatriz(n);

    // erro de alocacao
    if(entrada == NULL || L == NULL){
        fprintf(stderr, "Falha na alocação de memória\n");
        return 1;
    }
    
    fatoracaoLU(entrada, n, L, pivo, saida);

}