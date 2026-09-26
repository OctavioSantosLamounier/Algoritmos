# Pesquisa Binária (Binary Search)

Explicando o funcionamento do algoritmo de **Pesquisa Binária**, usando como referência o código em C++.

```cpp
int Binary_Search (vector<int> lista, int item) {
    int baixo = 0;
    int alto  = lista.size() - 1;

    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int chute = lista[meio];
        if (chute == item)
            return meio;
        if (chute > item)
            alto = meio - 1;
        else
            baixo = meio + 1;
    }

    return -1;
}
```

## O que é

Pense em como você procuraria um nome que começa com `K` numa agenda telefônica, ou uma palavra que começa com `O` num dicionário: você não folheia página por página a partir do início, você já abre pelo meio, porque sabe que o que procura está mais perto dali. É exatamente essa ideia que a pesquisa binária formaliza: dada uma **lista ordenada**, ela verifica o elemento do meio e, a partir dessa comparação, decide em qual metade da lista o elemento procurado pode estar. Assim, a outra metade é descartada e o processo continua apenas na parte que ainda pode conter o elemento.

## Como funciona

Imagine um jogo de adivinhação: alguém pensa em um número entre 1 e 100, e a cada palpite ela só diz se você chutou "muito alto", "muito baixo" ou acertou. Uma busca ingênua ("pesquisa simples") tentaria `1, 2, 3, 4...`, eliminando só um número por tentativa, se o número fosse 99, seriam necessárias 99 tentativas. A pesquisa binária, em vez disso, sempre chuta o **meio** do intervalo restante: primeiro `50`; se for baixo, o próximo chute é o meio entre `50` e `100`, ou seja `75`; e assim por diante, cortando pela metade a cada tentativa.

No código, esses intervalos é controlado por duas variáveis, `baixo` e `alto`, que marcam o início e o fim da faixa onde o item ainda pode estar. A cada passo do `while`:
1. Calcula-se `meio = (baixo + alto) / 2` (a divisão inteira já arredonda para baixo).
2. Compara-se `chute = lista[meio]` com o item procurado.
3. Se forem iguais, encontrou, retorna a posição.
4. Se o chute for maior que o item, o item só pode estar na metade da esquerda: `alto = meio - 1`.
5. Se o chute for menor, o item só pode estar na metade da direita: `baixo = meio + 1`.

O laço continua enquanto `baixo <= alto`; quando essa condição falha, é porque a faixa de busca ficou vazia. Logo, o item não está na lista.

Rastreando o código com a lista `{1, 3, 5, 7, 9}` procurando o item `3`:

| passo | baixo | alto | meio | chute | ação |
|-------|-------|------|------|-------|------|
| 1 | 0 | 4 | 2 | 5 | `5 > 3` → `alto = 1` |
| 2 | 0 | 1 | 0 | 1 | `1 < 3` → `baixo = 1` |
| 3 | 1 | 1 | 1 | 3 | `3 == 3` → retorna `1` |

<br>

Para visualizar o algoritmo rodando passo a passo:
- [Algorithm Visualizer — Binary Search](https://algorithm-visualizer.org/branch-and-bound/binary-search)

## Por que funciona

A pesquisa binária só é possível porque a lista está **ordenada**: ao comparar o item com o elemento do meio, uma única comparação já diz em qual metade inteira ele pode estar, permitindo descartar a outra metade sem examiná-la. Numa lista desordenada, essa garantia não existe, o item poderia estar em qualquer posição, então cortar metade da lista poderia jogar fora justamente onde ele está.

## Complexidade

A cada tentativa, a pesquisa binária elimina **metade** dos candidatos restantes, não apenas um. Para uma lista de 8 elementos, isso significa no máximo 3 tentativas (`2³ = 8`); para 1.024 elementos, no máximo 10 (`2¹⁰ = 1.024`). De forma geral, para uma lista de `n` elementos, a pesquisa binária precisa de `log₂n` passos no pior caso, contra `n` passos da pesquisa simples (linear).

- **Tempo:** O(log n).
- **Espaço:** O(1) na versão iterativa do código — apenas `baixo`, `alto`, `meio` e `chute`, independente do tamanho da lista.

Para a lista de 5 elementos do código, `log₂5 ≈ 2.32`, ou seja, no máximo 3 tentativas, exatamente o que aconteceu no rastreamento acima.

**Observação sobre o código:** como C++ não tem um equivalente direto do `None` do Python para indicar "não encontrado" em um `int`, o código usa `-1` como valor sentinela, uma posição que nunca ocorre de verdade num vetor.

## Referências

- Capítulo de Pesquisa Binária do livro *Entendendo Algoritmos*, de Aditya Y. Bhargava.
- [Binary Search — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/binary-search/)