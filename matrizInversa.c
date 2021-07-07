#include "lib_lu.h"
#include <unistd.h>

int main(int argc, char **argv){
    char c;
    char *outFile=NULL;
    int pivo = 0;
    while ((c = getopt (argc, argv, "o:p")) != -1){
        switch (c){
        case 'o':
            printf("Você ativou a opcao o\n");
            outFile = optarg;
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
    //printf("%s\n", outFile);
    scanf("%d", &n);
    //printf("n %d\n", n);
    L = alocaLUPadrao(n);
    //L = alocaLU(n);
    entrada = leMatriz(n);

    // erro de alocacao
    if(entrada == NULL || L == NULL){
        fprintf(stderr, "Falha na alocação de memória\n");
        return 1;
    }
    
    //printMatriz(entrada, n);
    
    //printf("Tamanho do L: %ld\n", sizeof(L->coef));
    //printMatriz(L->coef, n);
    //printTri(L);
    fatoracaoLU(entrada, n, L, pivo);

}