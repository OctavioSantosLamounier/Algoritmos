# Algoritmo de Bresenham

Explicando o funcionamento do **Algoritmo de Bresenham** para desenhar retas em uma grade de pixels, usando como referência o código em Python.

```python
x1, y1 = 2, 1
x2, y2 = 8, 4

dx = x2 - x1
dy = y2 - y1

c1 = 2 * dy
c2 = 2 * dy - 2 * dx

p = 2 * dy - dx

y = y1

for x in range(x1, x2 + 1):
    print(f"Calculado: ({x}, {y})")
    
    if p >= 0:
      y = y + 1
      p = p + c2
    else:
      p = p + c1
```

## O que é

Em 1962, Jack Bresenham, programador da IBM, precisava desenhar retas em processadores que **não tinham unidade de ponto flutuante**. Cálculos com casas decimais eram extremamente custosos, e o DDA (mesmo sendo mais rápido que o algoritmo analítico) ainda dependia de floats e arredondamentos a cada passo. O objetivo de Bresenham era radical: desenhar retas perfeitas usando **exclusivamente números inteiros**, sem divisão, sem floats e, tecnicamente, sem "arredondar" nada.

## Como funciona

A premissa geométrica (para retas como a do código, onde `0 < m < 1`, ou seja, `dy < dx`): o eixo X sempre avança exatamente 1 unidade por passo, essa é a "regra de ouro" para não deixar buracos na reta. A cada passo em X, o algoritmo só precisa decidir uma coisa: **o Y fica na mesma linha, ou sobe 1 pixel?**

Para decidir isso sem usar frações, Bresenham criou uma **variável de decisão** (`p`), que funciona como um acumulador de erro: ela mede, de forma proporcional, se a reta real está mais próxima do pixel de baixo ou do pixel de cima. Enquanto o erro acumulado for negativo, o pixel de baixo ainda é o mais próximo; quando o erro atinge ou ultrapassa zero, a reta já passou o meio do caminho e o pixel de cima passa a ser o mais próximo, hora do Y subir.

A mágica que elimina os floats: multiplicando a equação da reta (`y = mx + b`, onde `m = dy/dx`) por `2*dx`, a divisão desaparece e sobra só soma e subtração de inteiros. Isso gera duas constantes, calculadas uma única vez antes do laço:

- `c1 = 2*dy` — quanto o erro cresce quando o Y **não** sobe.
- `c2 = 2*dy - 2*dx` — quanto o erro muda quando o Y **sobe**.
- `p0 = 2*dy - dx` — valor inicial da variável de decisão.

A cada passo do laço: pinta-se o pixel `(x, y)` atual; se `p >= 0`, o Y sobe e `p` é atualizado com `c2`; caso contrário, o Y fica igual e `p` é atualizado com `c1`.

Com os valores de exemplo no código (`P1(2,1)` a `P2(8,4)`): `dx=6`, `dy=3`, logo `c1=6`, `c2=-6` e `p0=0`:

| x | y | p (antes do passo) | ação |
|---|---|----|------|
| 2 | 1 | 0  | `p>=0` → Y sobe, `p = 0 + c2 = -6` |
| 3 | 2 | -6 | `p<0` → Y fica, `p = -6 + c1 = 0` |
| 4 | 2 | 0  | `p>=0` → Y sobe, `p = 0 - 6 = -6` |
| 5 | 3 | -6 | `p<0` → Y fica, `p = -6 + 6 = 0` |
| 6 | 3 | 0  | `p>=0` → Y sobe, `p = -6` |
| 7 | 4 | -6 | `p<0` → Y fica, `p = 0` |
| 8 | 4 | 0  | (fim do laço) |

## Por que funciona

A variável `p` nada mais é do que a equação da reta original, reescrita para trabalhar só com inteiros. Ao multiplicar tudo por `2*dx`, a comparação "a reta está mais perto do pixel de cima ou de baixo?", que originalmente exigiria uma divisão fracionária, vira simplesmente checar o **sinal** de `p`. Cada atualização de `p` (`+c1` ou `+c2`) é matematicamente equivalente a avançar a posição exata da reta em `dy/dx` unidades, só que expressa como soma inteira. O resultado é o pixel mais próximo da reta real em cada coluna, sem nunca calcular uma fração.

## Comparação: DDA vs. Bresenham

| Característica | DDA | Bresenham |
|---|---|---|
| Tipo de número | Ponto flutuante (floats) | Apenas inteiros |
| Operações no laço | Adição e divisão (para calcular os incrementos) | Apenas adição e subtração |
| Arredondamento | Necessário a cada passo | Inexistente |
| Custo computacional | Alto (mais lento) | Baixíssimo (mais rápido) |