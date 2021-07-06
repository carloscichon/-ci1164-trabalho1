#include "lib_lu.h"
#include <unistd.h>

int main(int argc, char **argv){
    char c;
    while ((c = getopt (argc, argv, "o:p")) != -1){
        switch (c){
        case 'o':
            printf("Você ativou a opcao o\n");
            break;
        case 'p':
            printf("Você ativou a opcao p\n");
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
    //printf("n %d\n", n);
    L = alocaLUPadrao(n);
    //L = alocaLU(n);
    entrada = leMatriz(n);
    printMatriz(entrada, n);
    
    triangulariza(entrada, n, L, 0);
    //printf("Tamanho do L: %ld\n", sizeof(L->coef));
    printMatriz(L->coef, n);

    //printTri(L);
}