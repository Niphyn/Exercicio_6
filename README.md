
# EA05 - Exercicio avaliativo

Para esse exercício, deverá ser  implementada a função `list_sort` para ordenação de uma lista encadeada. Um dos argumentos da `list_sort` deverá ser uma função para comparação de elementos da lista (similar àquela utilizada como entrada para o qsort e bsearch). O cabeçalho da `list_sort` pode ser encontrado em 'lista.h'. O arquivo 'lista.c' contém implementações das operações básicas de listas encadeadas já estudadas em sala. 

A função será utilizada para ajudar Seu Adamor, um senhorzinho de idade que gosta de fazer suas próprias compras no mercado, mas, por ser bem esquecido, sempre faz uma lista desorganizada.

O programa principal deverá ler uma lista de compras e armazená-la em uma lista encadeada simples. Em seguida, a função `list_sort` deverá ser utilizada para ordenar a lista e, por fim, a lista ordenada deverá ser exibida na tela.

Para realizar este exercício, os nós deverão ser genéricos, i.e., o tipo dos valores deve ser `void*`. As devidas alterações deverão ser feitas nas outras funções para que este tipo seja suportado.

Regras: 
- É obrigatório implementar a função `list_sort` ;
- **Não deve-se usar a função InsereOrdenado feita no laboratório anterior**;
- Deve-se implementar a função de comparação que será passada como argumento para `list_sort`;
- Você pode utilizar a biblioteca 'string.h' e funções como `strdup` e `strcmp`. Obs.: Lembre-se que a `strdup` aloca espaços de memória internamente.
  
**Entradas**: Conjunto de strings separados por ‘\n’ com a última linha terminando em ‘.’.

**Saída**: A saída do programa deve conter uma lista ordenada alfabeticamente.)

Exemplos:

-----------

Entrada:
 
    azeite
    .

Saída:

    azeite

-----------

Entrada:
 
    mamao
    brocolis
    .

Saída:

    brocolis
    mamaos

-----------

Entrada:
 
    cafe
    leite
    pao
    .

Saída:

    cafe
    leite
    pao

-----------

Entrada:
 
    maca
    pao
    queijo
    leite
    arroz
    feijao
    farinha
    .

Saída:

    arroz
    farinha
    feijao
    leite
    maca
    pao
    queijo

-----------
