# Integrantes
* Carlos Eduardo Cichon Henriques - GRR20196991
* Nicolas Dencker de Marco - GRR20171605

# Documentação
O funcionamento de cada uma das funções do programa está documento logo acima de sua implementação.
## matrizInversa.c
Arquivo principal do programa, trata a passagem de argumento na execução e realiza a fatoração LU para cada bloco da entrada.

## lib_lu.c e lib_lu.h
Arquivos de implementação e cabeçalho contendo as funções e subfunções relacionadas a fatoração LU em si.

## matrizes.c e matrizes.h
Arquivos de implementação e cabeçalho contendo as funções e subfunções a matrizes. Como por exemplo alocação, leitura, e outras úteis.

## lib_sTri.c e lib_sTri.h
Arquivos de implementação e cabeçalho contendo as funções e subfunções da estrutura S_tri, que representa um sistema linear triangular, serve para
a abstração do L da LU. Conta com funções de alocação, leitura, e outras úteis.

# Estruturas
## Matriz
Apesar de não ter uma estrutura propriamente definida, nós utilizamos matrizes como um **double. Elas são alocadas dinamicamente
como um vetor de ponteiros de linhas contíguas. [Referência](http://wiki.inf.ufpr.br/maziero/doku.php?id=prog2:alocacao_dinamica_de_matrizes&s[]=aloca%C3%A7%C3%A3o&s[]=de&s[]=matrizes)

## S_tri
Estrutura que representa um sistema/matriz triangular, é alocado dinâmicamente e cada uma de suas linhas possui um elemento a mais que a linha anterior.
Desse modo, não armazenamos os 0s que ficariam na matriz triangular original.

# Códigos de erro
* **1:** Operação não permitida (divisão por 0 encontrada).
* **2:** Erro na abertura ou leitura de um arquivo. (fopen).
* **3:** Erro na passagem de parâmetros na chamada do programa.
* **4:** Erro de aloção de memória do programa.