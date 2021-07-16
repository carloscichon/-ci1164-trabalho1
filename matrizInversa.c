#include "lib_lu.h"
#include <unistd.h>

int main(int argc, char **argv){
    char c;
    FILE *saida = stdout;
    int pivo = 0;
    while ((c = getopt (argc, argv, "o:p")) != -1){ // tirar daqui
        switch (c){
        case 'o':
            printf("Você ativou a opcao o\n");
            saida = fopen(optarg, "w");
            if(saida == NULL){
                fprintf(stderr, "Não foi possível abrir o arquivo %s\n", optarg);
                return -1;
            }
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
            return -2;
        default:
            break;
        }
    }

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
                return -3;
            }
            
            fatoracaoLU(entrada, n, L, pivo, saida);
        }
    }
    liberaMatriz(entrada, n);
    liberaLU(L, n);
    
}