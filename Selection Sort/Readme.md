# Selection Sort

Explicando o funcionamento do algoritmo **Selection Sort** (ordenação por seleção), usando como referência a implementação em C.

```c
void selectionSort (int *vetor, int tamanho) {
    for (int i=0; i<tamanho-1; i++) {
        // guarda o indice do menor elemento
        int menor = i;
        // procura o menor valor aparti de i+1
        for (int j=i+1; j<tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        // swap
        int auxiliar = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = auxiliar;
    }
}
```

## O que é

**Selection Sort** ordena repetindo um processo simples: encontrar o menor elemento da parte ainda não ordenada e trocá-lo de lugar com o primeiro elemento dessa parte. Feito isso, a posição do menor elemento fica definitiva, e o mesmo processo se repete para o restante do vetor.

## Como funciona

A cada iteração `i`, o vetor já está dividido em uma parte ordenada (`0` até `i-1`) e uma não ordenada (`i` até o fim). O algoritmo percorre a parte não ordenada procurando o índice do menor valor e, ao final da busca, troca esse valor com `vetor[i]`, colocando-o na sua posição final.

Exemplo rápido com `[4, 9, 1, 6, 3]`:

- `i=0`: menor da faixa `[4,9,1,6,3]` é `1` (índice 2) → troca com posição 0 → `[1, 9, 4, 6, 3]`
- `i=1`: menor da faixa `[9,4,6,3]` é `3` (índice 4) → troca com posição 1 → `[1, 3, 4, 6, 9]`
- `i=2`: menor da faixa `[4,6,9]` é `4` (já está na posição) → `[1, 3, 4, 6, 9]`
- `i=3`: menor da faixa `[6,9]` é `6` (já está na posição) → `[1, 3, 4, 6, 9]`

No código, o laço externo (`i`) representa a fronteira entre a parte ordenada e a não ordenada. O laço interno (`j`) varre a parte não ordenada e atualiza `menor` sempre que encontra um valor menor. Ao final do laço interno, o `swap` coloca o menor valor encontrado na posição `i`.


**Para visualizar o algoritmo rodando passo a passo:** 

- [Algorithm Visualizer — Selection Sort](https://algorithm-visualizer.org/brute-force/selection-sort)
- [VisuAlgo — Sorting](https://visualgo.net/en/sorting)

## Por que funciona

A cada iteração `i`, o algoritmo garante que `vetor[i]` recebe o menor valor entre os elementos ainda não posicionados e, como esse valor é comparado com todos os outros da parte não ordenada antes da troca, ele é garantidamente o mínimo daquela faixa. Assim, a cada passo a parte ordenada cresce em um elemento, sempre com valores menores ou iguais a tudo que resta na parte não ordenada. Quando `i` percorre todo o vetor, ele está ordenado.

## Complexidade

- **Tempo:** O(n²) em todos os casos (melhor, médio e pior), a busca pelo menor elemento sempre percorre toda a parte não ordenada, independente de o vetor já estar ordenado ou não.
- **Espaço:** O(1) — ordenação *in-place*, usando só a variável `auxiliar` para o swap.

### Vantagens
- Simples de entender e implementar.
- Faz poucas trocas (no máximo `tamanho-1` swaps), útil quando escrever na memória é uma operação cara.
- *In-place*, sem gasto extra de memória proporcional ao tamanho da entrada.

### Desvantagens
- O(n²) mesmo no melhor caso (diferente do Insertion Sort, que é O(n) se o vetor já estiver ordenado), o que o torna lento para vetores grandes.
- **Não é estável**: a ordem relativa entre elementos iguais pode mudar, já que o swap troca posições distantes no vetor.

## Referência

Baseado na explicação e nos exemplos de implementação do artigo [Selection Sort — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/).