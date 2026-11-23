# Heap Sort

Explicando o funcionamento do algoritmo **Heap Sort** (ordenação por heap), usando como referência a implementação em C++.

```cpp
// afunda arr[i] até a subárvore de raiz i voltar a ser um max-heap
// n: tamanho atual do heap
void heapify (vector<int>& arr, int n, int i) {
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    // filho esquerdo é maior que o maior até agora?
    if (l<n && arr[l]>arr[largest])
        largest = l;

    // filho direito é maior que o maior até agora?
    if (r<n && arr[r]>arr[largest])
        largest = r;

    // se algum filho é maior, troca e continua descendo
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort (vector<int>& arr) {
    int n = arr.size();

    // constrói o max-heap
    for (int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);

    // move o maior (raiz) para o fim e refaz o heap com um elemento a menos
    for (int i=n-1; i>0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```


## O que é

**Heap Sort** é um algoritmo de ordenação por comparação baseado na estrutura **heap binário**: uma árvore binária completa guardada em um vetor, em que o filho esquerdo de `i` fica em `2i+1`, o direito em `2i+2` e o pai em `(i-1)/2`. Aqui usa-se um **max-heap**, em que todo pai é maior ou igual aos seus filhos, então o maior elemento fica sempre na raiz (`arr[0]`).

A ideia é parecida com a do Selection Sort, que seleciona o maior elemento a cada passo, mas o heap permite achar e remover o maior em O(log n) em vez de O(n).

## Como funciona

O algoritmo tem duas fases. Na primeira, o vetor é transformado em um max-heap. Na segunda, a raiz (o maior elemento) é trocada com o último elemento do heap, que passa a fazer parte da região ordenada no fim do vetor, e o heap, agora com um elemento a menos, é refeito.

A função `heapify(arr, n, i)` assume que as subárvores dos filhos de `i` já são heaps. Ela compara `arr[i]` com os filhos, troca com o maior deles se algum for maior e repete a partir da posição do filho, até a propriedade do heap ser restaurada. O parâmetro `n` é o tamanho do heap atual, então os elementos já ordenados no fim do vetor ficam de fora.

Exemplo rápido com `[4, 10, 3, 5, 1, 2]`:

Construção do heap (`i` de `n/2-1 = 2` até `0`):
- `i=2` (`3`) e `i=1` (`10`): já são maiores que seus filhos, nada muda
- `i=0` (`4`): troca com `10` e depois com `5` → `[10, 5, 3, 4, 1, 2]`

Extração (a região ordenada fica depois da barra):
- Troca `10` com o último e refaz o heap → `[5, 4, 3, 2, 1 | 10]`
- Troca `5` com o último e refaz o heap → `[4, 2, 3, 1 | 5, 10]`
- Troca `4` com o último e refaz o heap → `[3, 2, 1 | 4, 5, 10]`
- Troca `3` com o último e refaz o heap → `[2, 1 | 3, 4, 5, 10]`
- Troca `2` com o último e refaz o heap → `[1 | 2, 3, 4, 5, 10]`
- Resultado final: `[1, 2, 3, 4, 5, 10]`

**Para visualizar o algoritmo rodando passo a passo:**

- [Heap Sort — Algorithm Visualization (labuladong)](https://labuladong.online/algo-visualize/en/tutorial/heap-sort/)
- [Sorting Algorithms Visualization — CS 10C](https://cs.ucr.edu/~tyf/10c/08.sorting/sorting-viz.html)

## Por que funciona

Na construção, `heapify` é chamado de baixo para cima (de `n/2-1` até `0`), então, quando chega em `i`, as subárvores dos filhos já são heaps e só `arr[i]` pode violar a propriedade, o que `heapify` corrige. Na extração vale o invariante: antes de cada iteração `i`, `arr[0..i]` é um max-heap e `arr[i+1..n-1]` contém os maiores elementos, já em ordem. Como a raiz é o maior do heap, trocá-la com `arr[i]` coloca esse elemento na posição final. Só a raiz fica fora do lugar, e `heapify(arr, i, 0)` restaura o heap em `arr[0..i-1]`. Ao final, todo o vetor está ordenado.

## Complexidade

- **Tempo (melhor, médio e pior caso):** O(n log n). A construção do heap custa O(n), e a extração faz `n-1` chamadas de `heapify`, cada uma com custo O(log n), que é a altura do heap.
- **Espaço:** O(1) auxiliar para os dados (ordenação *in-place*) + O(log n) de pilha, porque `heapify` é recursivo (uma versão iterativa elimina esse custo).

### Vantagens
- O(n log n) garantido.
- *In-place*: não precisa de vetor auxiliar.

### Desvantagens
- Não é estável: as trocas a longa distância podem inverter a ordem de elementos iguais.

## Referência

Baseado na explicação e nos exemplos de implementação do artigo [Heap Sort — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/heap-sort/).