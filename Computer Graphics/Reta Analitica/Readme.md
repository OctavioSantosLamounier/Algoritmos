# Reta Analítica (Algoritmo Analítico de Geração de Retas)

Explicando o funcionamento do **Algoritmo Analítico** para desenhar retas em uma grade de pixels, usando como referência o código em Python.

```python
import math
x1, y1 = 2, 1
x2, y2 = 8, 4

dx = x2 - x1
dy = y2 - y1
    
m = dy / dx
b = y1 - (m * x1)

for x in range(x1, x2 + 1):
    y = (m * x) + b
    y = math.ceil(y)
    print(f"Calculado: ({x}, {y})")
```

## O que é

O algoritmo analítico é a forma mais intuitiva de desenhar uma reta em uma tela: usar diretamente a equação fundamental da reta, `y = mx + b`, calculando o `y` correspondente para cada `x` inteiro entre os dois pontos extremos.

O desafio de fundo é que a matemática lida com retas contínuas (infinitos pontos), enquanto a tela é uma grade discreta de pixels inteiros. O algoritmo analítico tenta resolver esse problema calculando a equação exata e depois arredondando o resultado para o pixel mais próximo.

## Como funciona

1. Calcula-se o coeficiente angular `m = (y2-y1)/(x2-x1)`, que representa a inclinação da reta.
2. Calcula-se o coeficiente linear `b = y1 - m*x1`, o ponto onde a reta cruza o eixo Y.
3. Percorre-se cada valor inteiro de `x` entre `x1` e `x2`, calculando o `y` exato pela equação.
4. Arredonda-se `y` para um valor inteiro, já que um pixel não existe em posições fracionárias.

Com os valores de exemplo no código (`P1(2,1)` a `P2(8,4)`): `dx=6`, `dy=3`, logo `m=0.5` e `b=0`. A cada passo de `x`, o algoritmo calcula:

| x | y exato | y arredondado (`ceil`) |
|---|---------|-------------------------|
| 2 | 1.0     | 1                       |
| 3 | 1.5     | 2                       |
| 4 | 2.0     | 2                       |
| 5 | 2.5     | 3                       |
| 6 | 3.0     | 3                       |
| 7 | 3.5     | 4                       |
| 8 | 4.0     | 4                       |

**Observação sobre o código:** ao invés de `round()` (arredondamento para o mais próximo, comum nos materiais didáticos), o código usa `math.ceil()`, que sempre arredonda para cima. O resultado final ainda forma uma reta coerente, mas em valores como `1.5` o pixel escolhido tende a "puxar" a reta ligeiramente para cima em comparação ao arredondamento tradicional.

## Limitações do algoritmo analítico

Essa abordagem, apesar de intuitiva, tem falhas conhecidas:

- **Divisão por zero em retas verticais:** se `x1 == x2`, então `dx = 0`, e o cálculo de `m = dy/dx` quebra o programa.
- **Buracos em retas íngremes:** quando `|m| > 1`, o valor de `y` cresce mais rápido que `x`. Como o laço avança apenas 1 unidade em `x` por vez, o algoritmo pula posições de `y`, resultando numa reta pontilhada, cheia de falhas, em vez de contínua.
- **Custo computacional:** o cálculo de `y = m*x + b` faz uma multiplicação em ponto flutuante a cada iteração do laço, uma operação lenta para o processador.

Essas limitações são o que motiva o uso de algoritmos incrementais como o **DDA** (Digital Differential Analyzer), que substituem a multiplicação por somas simples e lidam melhor com retas verticais e íngremes.