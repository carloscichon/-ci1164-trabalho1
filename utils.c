#include "utils.h"

/*  Retorna tempo em milisegundos

    Forma de uso:
 
    double tempo;
    tempo = timestamp();
    <treceho de programa do qual se deseja medir tempo>
    tempo = timestamp() - tempo;
*/

double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

void pegaParametrosDeExecucao(int argc, char **argv, int *pivo, FILE *saida){
  char c;
  while ((c = getopt (argc, argv, "o:p")) != -1){
        switch (c){
        case 'o':
            printf("Você ativou a opcao o\n");
            saida = fopen(optarg, "w");
            if(saida == NULL){
                fprintf(stderr, "Não foi possível abrir o arquivo %s\n", optarg);
                exit(2);
            }
            break;
        case 'p':
            printf("Você ativou a opcao p\n");
            *pivo = 1;
            break;
        case '?':
            if (optopt == 'o')
            fprintf (stderr, "Opção -%c precisa de um argumento.\n", optopt);
            else
            fprintf (stderr, "Opção desconhecida. %c\n", optopt);
            exit(3);
        default:
            break;
        }
    }
}
