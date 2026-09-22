# Insertion Sort

Explicando o funcionamento do algoritmo **Insertion Sort** (ordenação por inserção), usando como referência a implementação em C.

```c
void insertionSort (int *vetor, int tamanho) {
    for (int i=1; i<tamanho; i++) {
        // elemento a ser inserido na posição correta
        int chave = vetor[i];
        int j = i-1;

        // copia parte do vetor uma posição a frente
        while (j > -1 && vetor[j] > chave) {
            vetor[j+1] = vetor[j];
            j--;
        }
        
        // colar chave na posição correta    
        vetor[j+1] = chave;
    }
}
```

## O que é

**Insertion Sort** é um algoritmo que constrói a ordenação aos poucos, inserindo cada elemento na posição correta de uma parte já ordenada do vetor. É parecido com organizar cartas de baralho na mão: você vai pegando uma carta por vez do monte desorganizado e a encaixa no lugar certo entre as cartas que já estão ordenadas.

## Como funciona

O vetor é dividido mentalmente em duas partes: a **ordenada** (à esquerda) e a **não ordenada** (à direita). A cada iteração, pega-se o primeiro elemento da parte não ordenada (a `chave`) e desloca-se os elementos maiores que ela, uma posição à direita, até achar o lugar certo para inserir a `chave`.

Exemplo rápido com `[5, 2, 4, 1]` (o primeiro elemento já conta como "ordenado"):
- `chave=2`: `2 < 5`, desloca o `5` → `[2, 5, 4, 1]`
- `chave=4`: `4 < 5`, desloca o `5` → `[2, 4, 5, 1]`
- `chave=1`: desloca `5`, `4` e `2` → `[1, 2, 4, 5]`

No código, o laço externo (`i`) percorre a parte não ordenada e guarda o elemento atual em `chave`. O laço `while` interno é quem desloca os elementos maiores que `chave` uma posição à frente (`vetor[j+1] = vetor[j]`), andando para trás (`j--`) enquanto houver elemento maior à esquerda. Quando o `while` para, `vetor[j+1] = chave` coloca a chave exatamente na posição que sobrou.

**Para visualizar o algoritmo rodando passo a passo:** 

- [Algorithm Visualizer — Insertion Sort](https://algorithm-visualizer.org/brute-force/insertion-sort)
- [VisuAlgo — Sorting](https://visualgo.net/en/sorting)

## Por que funciona

A cada iteração `i`, o algoritmo garante que os elementos de `vetor[0]` até `vetor[i]` estão ordenados entre si, isso é o que se chama de invariante do laço. Como a `chave` é sempre inserida na posição correta dentro dessa parte já ordenada (empurrando os maiores para a frente), a cada passo a região ordenada cresce em um elemento sem quebrar a ordem já conquistada. Quando `i` chega ao fim do vetor, a região ordenada cobre o vetor inteiro.

## Complexidade

- **Tempo (melhor caso):** O(n) — se o vetor já estiver ordenado, o `while` nunca desloca nada.
- **Tempo (médio/pior caso):** O(n²) — se o vetor estiver em ordem aleatória ou inversa, cada `chave` pode precisar deslocar quase todos os elementos já ordenados.
- **Espaço:** O(1) — ordenação *in-place*, usando só a variável `chave` como espaço auxiliar.

### Vantagens
- Simples de entender e implementar.
- Estável: elementos iguais mantêm a ordem relativa original.
- Eficiente para vetores pequenos ou quase ordenados, quanto menos "fora de ordem" (menos inversões), menos trabalho ele faz.
- *In-place*, sem gasto extra de memória proporcional ao tamanho da entrada.

### Desvantagens
- O(n²) no caso médio/pior o torna ineficiente para vetores grandes.
- Perde para algoritmos como Merge Sort ou Quick Sort na maioria dos cenários com muitos dados.

## Referência

Baseado na explicação e nos exemplos de implementação do artigo [Insertion Sort Algorithm — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/).