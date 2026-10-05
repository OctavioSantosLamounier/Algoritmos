# Merge Sort

Explicando o funcionamento do algoritmo **Merge Sort** (ordenação por intercalação), usando como referência a implementação em C++.

```cpp
#define inf (1e9+10)

void merge (int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1+1];
    int R[n2+1];

    // copia cada metade para seu vetor auxiliar
    for (int i=0; i<n1; i++)
        L[i] = A[p+i];
    for (int j=0; j<n2; j++)
        R[j] = A[q+1+j];

    // sentinelas
    L[n1] = inf;
    R[n2] = inf;

    int i = 0;
    int j = 0;

    // intercala: sempre pega o menor entre os dois elementos do início
    for (int k=p; k<=r; k++) {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void merge_sort (int A[], int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}
```

A chamada inicial usa índices a partir de 1: `merge_sort(vetor, 1, tamanho)`. O elemento `A[k]` fica em `vetor[k-1]`.

## O que é

**Merge Sort** é um algoritmo de ordenação baseado em **dividir para conquistar**: divide o vetor ao meio, recursivamente, até restarem subvetores de um único elemento (o caso base, já que um elemento sozinho está ordenado) e depois **intercala** as metades ordenadas, duas a duas, até formar um único vetor ordenado.

## Como funciona

A **intercalação** junta duas listas ordenadas `A` e `B` em uma única lista ordenada `C`. Para isso, compara-se o primeiro elemento de cada lista e o menor é colocado em `C`. Em seguida, avança-se para o próximo elemento da lista de onde o elemento foi retirado. Esse processo se repete até que uma das listas termine. Quando isso acontece, os elementos restantes da outra lista são adicionados diretamente ao final de `C`.

O algoritmo possui duas etapas principais: **dividir para conquistar** e **combinar**. Na etapa de **dividir para conquistar**, o vetor é dividido ao meio repetidamente até que cada subvetor tenha apenas um elemento. Nesse ponto, cada subvetor já está ordenado. Na etapa de **combinar**, os subvetores são intercalados em ordem, formando subvetores cada vez maiores, até obter um único vetor ordenado.

Exemplo rápido com `[5, 2, 4, 1]`:
- Divide: `[5, 2]` e `[4, 1]`, depois `[5]`, `[2]`, `[4]` e `[1]`
- Intercala `[5]` e `[2]` → `[2, 5]`
- Intercala `[4]` e `[1]` → `[1, 4]`
- Intercala `[2, 5]` e `[1, 4]` → `[1, 2, 4, 5]`

No código, `merge_sort` calcula o meio `q`, chama a si mesmo para cada metade e ao final chama `merge` para combiná-las. Dentro de `merge`, cada metade é copiada para um vetor auxiliar (`L` e `R`), e no fim de cada vetor fica uma **sentinela** `inf`. Os índices `i` e `j` começam em 0 e apontam para o menor elemento restante de cada metade. A cada passo, o menor entre `L[i]` e `R[j]` vai para `A[k]` e seu índice avança. Quando uma metade acaba, o índice dela chega na sentinela, que perde todas as comparações, então o restante da outra metade é copiado sem precisar de um laço extra.

**Para visualizar o algoritmo rodando passo a passo:**

- [Sorting Algorithms Visualization — CS 10C](https://cs.ucr.edu/~tyf/10c/08.sorting/sorting-viz.html)
- [VisuAlgo — Sorting](https://visualgo.net/en/sorting)

## Por que funciona

A prova é por indução no tamanho do subvetor. Com 1 elemento, ele já está ordenado (caso base). Se `merge_sort` ordena corretamente as duas metades, basta mostrar que `merge` junta as duas em um subvetor ordenado. Isso vale pelo invariante do laço de `merge`: no início de cada iteração `k`, `A[p..k-1]` contém, em ordem, os `k - p` menores elementos de `L` e `R` juntos, e `L[i]` e `R[j]` são os menores elementos que ainda não foram copiados (ou a sentinela, se a metade já acabou). Como `L` e `R` estão ordenados, o menor entre `L[i]` e `R[j]` é sempre o próximo elemento correto, e ele vai para `A[k]`. O laço roda `r - p + 1` vezes, então as sentinelas nunca são copiadas e, ao final, todo o intervalo `A[p..r]` está ordenado.

## Complexidade

- **Tempo (melhor, médio e pior caso):** Θ(n log n). O vetor é dividido em `log n` níveis e a intercalação de cada nível custa `O(n)`.
- **Espaço:** O(n) auxiliar (os vetores `L` e `R`) + O(log n) de pilha de recursão.

### Vantagens
- Desempenho previsível: O(n log n) em qualquer entrada.
- Estável: elementos iguais mantêm a ordem relativa original.
- Eficiente para grandes vetores.

### Desvantagens
- **Esta implementação em específico não é *in-place***: precisa de memória extra proporcional ao tamanho da entrada.
- Nesta implementação, `L` e `R` são vetores de tamanho variável na pilha, o que pode estourar a pilha para `n` muito grande.
- A sentinela `inf` exige que todos os valores sejam menores que ela (inf pode ser alterado para um valor maior caso nescessario).
- Para vetores pequenos ou quase ordenados, algoritmos simples como o Insertion Sort costumam ser mais rápidos, já que o merge sort sempre dará Θ(n log n) para qualquer tipo de vetor.

## Referência

Baseado na explicação e nos exemplos de implementação do artigo [Merge Sort — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/merge-sort/).