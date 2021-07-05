# ci1164-trabalho1

## Especificação

O trabalho consiste em calcular a matriz inversa de várias matrizes quadradas utilizando o Método de Fatoração LU.

As matrizes serão lidas pela Entrada Padrão. O formato de entrada dos dados consiste de diversos blocos separados por uma linha em branco. Cada bloco tem a ordem da matriz na 1ª linha, e nas linhas restantes do bloco estão a matriz quadrada da qual se quer a matriz inversa.

O programa deverá gerar como saída diversos blocos separados por uma linha em branco. Cada bloco tem a ordem da matriz na 1ª linha, seguida da matriz de entrada e da matriz inversa calculada. As matrizes estão separadas por uma linha contendo apenas o caracter #.

Além disso, ao final de cada bloco (após a matriz inversa) deve constar:

* O tempo de execução da triangularização;
* O tempo de cálculo de Y e X nas fases Ly=b e Ux=y
* O valor da norma L2 do resíduo na fase Ux=y

## Utils
* https://www.youtube.com/watch?v=e9duc5gvPWE&list=PLS5eXCRgrGweLsVonsq9J7dFZTUpKXjbG&index=2
* https://gitlab.c3sl.ufpr.br/nicolui/ci1164_2020-trab01.
* https://www.codewithc.com/c-program-for-lu-factorization/
* https://www.codewithc.com/lu-decomposition-algorithm-flowchart/
