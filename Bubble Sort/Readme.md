# Bubble Sort

Explicação do funcionamento do algoritmo **Bubble Sort** (ordenação por bolha), usando como referência a implementação em C.

```c
void bubbleSort (int *vetor, int tamanho) {
    for (int i=0; i<tamanho-1; i++) {
        for (int j=0; j<tamanho-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                // swap
                int auxiliar = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxiliar;
            }
        }
    }
}
```

## O que é

**Bubble Sort** é o mais simples dos algoritmos de ordenação. A ideia central é comparar pares de elementos **adjacentes** no vetor e trocá-los de posição sempre que estiverem fora de ordem. Repetindo esse processo várias vezes, os elementos maiores vão "borbulhando" para o final do vetor, daí o nome.

Não é um algoritmo eficiente para grandes volumes de dados, mas é excelente para aprender os fundamentos de ordenação, já que sua lógica é curta e visual.

## Como funciona

O algoritmo trabalha em **passadas** sobre o vetor: em cada uma, percorre os elementos da esquerda para a direita comparando vizinhos (`vetor[j]` com `vetor[j+1]`) e trocando-os quando estão fora de ordem. Ao final de cada passada completa, o maior valor restante já foi "empurrado" até sua posição final. Repetindo isso, o vetor inteiro fica ordenado.

Exemplo rápido com `[5, 2, 4, 1]`:
- Passada 1: `[5,2,4,1]` → `[2,5,4,1]` → `[2,4,5,1]` → `[2,4,1,5]` (o `5` chega à posição final)
- Passada 2: `[2,4,1,5]` → `[2,1,4,5]` (o `4` chega à posição final)
- Passada 3: `[2,1,4,5]` → `[1,2,4,5]` (ordenado)

No código, o laço externo (`i`) controla o número de passadas e o laço interno (`j`) faz as comparações/trocas. Vale notar que essa implementação sempre roda `tamanho-1` comparações internas em toda passada. Versões otimizadas reduzem esse laço para `tamanho-1-i` e param mais cedo se em uma passada não fizer nenhuma troca (sinal de vetor já ordenado), aqui optou-se pela forma mais simples e didática.

**Indicação para visualizar o algoritmo rodando passo a passo:**
- [Algorithm Visualizer — Bubble Sort](https://algorithm-visualizer.org/brute-force/bubble-sort)
- [VisuAlgo — Sorting](https://visualgo.net/en/sorting)

## Por que funciona

A corretude vem de uma ideia simples: como o maior valor "carregado" numa passada nunca é ultrapassado (ele segue sendo trocado para a direita a cada comparação), ele acaba empurrado até o fim da região ainda não ordenada. Repetindo isso a cada passada, após `k` passadas os `k` maiores elementos já estão corretamente posicionados nas últimas `k` posições, até o vetor inteiro ficar ordenado.

## Complexidade

- **Tempo:** O(n²) — tanto no pior caso quanto no caso médio, pois há dois laços aninhados, cada um percorrendo (aproximadamente) todo o vetor.
- **Espaço:** O(1) — a ordenação é feita *in-place*, usando apenas uma variável auxiliar para a troca, sem precisar de estruturas extras proporcionais ao tamanho da entrada.

### Vantagens
- Simples de entender e implementar.
- Não exige memória extra significativa.
- É um algoritmo de ordenação **estável**: elementos com valores iguais mantêm a ordem relativa original entre si.

### Desvantagens
- O(n²) o torna muito lento para vetores grandes.
- Tem pouca aplicação na prática real, seu uso é essencialmente didático, para ensinar conceitos de ordenação.

## Referência

Baseado na explicação e nos exemplos de implementação do artigo [Bubble Sort Algorithm — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/).