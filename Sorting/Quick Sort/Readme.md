# Quick Sort

Explicando o funcionamento do algoritmo **Quick Sort** (ordenação rápida), usando como referência a implementação em C++.

```cpp
int particionar (int *vetor, int inicio, int fim) {
    // pivô: último elemento
    int pivo = vetor[fim];
    // i: índice do último elemento menor ou igual ao pivô
    int i = inicio - 1;

    for (int j=inicio; j <= fim-1; j++)
        // elemento pequeno: vai para o lado esquerdo
        if (vetor[j] <= pivo)
            swap(vetor[++i], vetor[j]);

    // coloca o pivô na posição correta
    swap(vetor[i+1], vetor[fim]);
    return i+1;
}

void quickSort (int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivoIndice = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, pivoIndice - 1);
        quickSort(vetor, pivoIndice + 1, fim);
    }
}
```

A chamada inicial é `quickSort(vetor, 0, tamanho-1)`.

## O que é

**Quick Sort** é um algoritmo de ordenação por troca, criado em 1962, que usa o paradigma de **dividir para conquistar**. Ele escolhe um elemento do vetor como **pivô** e rearranja o vetor de modo que os elementos menores ou iguais ao pivô fiquem à esquerda e os maiores fiquem à direita (o **particionamento**). Com isso, o pivô já está na sua posição final, e o mesmo processo é repetido recursivamente para cada lado até o vetor ficar completamente ordenado.

## Como funciona

O pivô pode ser o primeiro elemento, o último, um elemento aleatório ou a mediana. Nesta implementação, o pivô é o **último elemento**. Durante o particionamento, `j` percorre o vetor e `i` marca o fim da região dos elementos pequenos. Sempre que `vetor[j] <= pivo`, incrementa-se `i` e troca-se `vetor[i]` com `vetor[j]`. Ao fim do laço, troca-se `vetor[i+1]` com o pivô, que fica entre as duas regiões.

Exemplo rápido com `[20, 80, 30, 90, 40, 70]` (pivô = `70`, `i = -1`):
- `j=0`: `20 <= 70`, `i=0`, troca `vetor[0]` com `vetor[0]` → `[20, 80, 30, 90, 40, 70]`
- `j=1`: `80 > 70`, não faz nada
- `j=2`: `30 <= 70`, `i=1`, troca `vetor[1]` com `vetor[2]` → `[20, 30, 80, 90, 40, 70]`
- `j=3`: `90 > 70`, não faz nada
- `j=4`: `40 <= 70`, `i=2`, troca `vetor[2]` com `vetor[4]` → `[20, 30, 40, 90, 80, 70]`
- Fim do laço: troca `vetor[i+1]` com o pivô → `[20, 30, 40, 70, 80, 90]`

O pivô `70` está na posição correta (índice 3). Em seguida, `quickSort` é chamado para `[20, 30, 40]` (à esquerda) e para `[80, 90]` (à direita), até os subvetores terem no máximo 1 elemento (`inicio >= fim`), que é a condição de parada.

**Para visualizar o algoritmo rodando passo a passo:**

- [Sorting Algorithms Visualization — CS 10C](https://cs.ucr.edu/~tyf/10c/08.sorting/sorting-viz.html)
- [VisuAlgo — Sorting](https://visualgo.net/en/sorting)


## Por que funciona

No particionamento, `i` marca o fim da região dos elementos menores ou iguais ao pivô, e `j` percorre o subvetor. A cada iteração de `j`, `vetor[inicio..i]` contém só elementos `<=` pivô e `vetor[i+1..j-1]` contém só elementos `>` pivô. Quando o laço termina, trocar o pivô com `vetor[i+1]` o coloca entre as duas regiões: tudo à esquerda é `<=` e tudo à direita é `>`. Assim o pivô já está na posição final e nunca mais se move.

A correção do algoritmo segue por indução no tamanho do subvetor. Se ele tem 0 ou 1 elemento, já está ordenado. Se tem mais, o particionamento põe o pivô na posição final, com tudo que é `<=` dele à esquerda e tudo que é `>` à direita. Como a recursão ordena cada um dos dois lados, o subvetor inteiro termina ordenado.


## Complexidade

- **Tempo (melhor e médio caso):** O(n log n). Quando o pivô divide o vetor em partes de tamanho parecido, são `log n` níveis e cada nível custa O(n) de particionamento (`T(n) = 2T(n/2) + O(n)`).
- **Tempo (pior caso):** O(n²). Acontece quando o pivô sempre fica numa ponta, deixando um lado vazio (`T(n) = T(n-1) + O(n)`). Com o pivô no último elemento, isso ocorre em vetores já ordenados, em ordem inversa ou com todos os elementos iguais.
- **Espaço:** O(1) auxiliar (ordenação *in-place*) + pilha de recursão de O(log n) em média e O(n) no pior caso.

### Vantagens
- *In-place*: não precisa de vetor auxiliar.
- Muito rápido na prática, com O(n log n) em média.
- Poucas trocas e boa localidade de memória.

### Desvantagens
- Pior caso O(n²) quando a escolha do pivô é ruim (Escolher o pivô aleatório ou pela mediana reduz esse risco).
- Não é estável: as trocas podem inverter a ordem de elementos iguais.
- No pior caso, a recursão pode ficar profunda (O(n) de pilha).

## Referência

Baseado na explicação e nos exemplos de implementação do artigo [Quick Sort Algorithm — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/).