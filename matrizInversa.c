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
    scanf("%d", &n);
    entrada = leMatriz(n);
    printMatriz(entrada, n);
}