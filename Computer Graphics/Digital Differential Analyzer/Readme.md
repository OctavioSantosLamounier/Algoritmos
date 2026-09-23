# DDA (Digital Differential Analyzer)

Explicando o funcionamento do **Algoritmo DDA** para desenhar retas em uma grade de pixels, usando como referência o código em Python.

```python
import math
x1, y1 = 2, 1
x2, y2 = 8, 4

dx = x2 - x1
dy = y2 - y1

steps = max(abs(dx), abs(dy))

x_inc = dx / steps
y_inc = dy / steps

x = x1
y = y1

for i in range(steps + 1):
    x_arredondado = math.ceil(x)
    y_arredondado = math.ceil(y)

    print(f"Calculado: ({x_arredondado}, {y_arredondado})")

    x = x + x_inc
    y = y + y_inc
```

## O que é

DDA é uma evolução do algoritmo analítico. Em vez de calcular `y = mx + b` do zero para cada `x` (o que exige uma multiplicação por iteração), o DDA parte do ponto inicial e vai **somando um incremento fixo** a cada passo, tanto em `x` quanto em `y`, até alcançar o ponto final. A ideia central: o próximo pixel é sempre o pixel atual mais um pequeno incremento constante.

## Como funciona

1. Calcula-se `dx` e `dy`, a variação total entre os dois pontos.
2. Calcula-se `steps = max(|dx|, |dy|)`. O algoritmo usa o **eixo que varia mais** para decidir quantos passos serão dados, garantindo que nenhum pixel seja pulado, independente da inclinação da reta.
3. Calculam-se os incrementos por passo: `x_inc = dx/steps` e `y_inc = dy/steps`.
4. A cada iteração, arredonda-se a posição atual para pintar o pixel, e então soma-se o incremento a `x` e `y` para preparar o próximo passo.

Com os valores de exemplo no código (`P1(2,1)` a `P2(8,4)`): `dx=6`, `dy=3`, então `steps=6`, `x_inc=1` e `y_inc=0.5`:

| passo | x (exato) | y (exato) | pixel (`ceil`) |
|-------|-----------|-----------|-----------------|
| 0     | 2.0       | 1.0       | (2, 1)          |
| 1     | 3.0       | 1.5       | (3, 2)          |
| 2     | 4.0       | 2.0       | (4, 2)          |
| 3     | 5.0       | 2.5       | (5, 3)          |
| 4     | 6.0       | 3.0       | (6, 3)          |
| 5     | 7.0       | 3.5       | (7, 4)          |
| 6     | 8.0       | 4.0       | (8, 4)          |

## Por que funciona

O DDA resolve diretamente os três problemas do algoritmo analítico:

- **Sem divisão por zero:** `steps` é o maior valor entre `|dx|` e `|dy|`, então mesmo numa reta vertical (`dx=0`), `steps` é baseado em `dy` e o cálculo nunca quebra.
- **Sem buracos:** como o número de passos acompanha o eixo que mais varia, o eixo mais lento sempre avança em frações (`< 1`) a cada passo, garantindo que nenhuma posição do eixo mais rápido fique sem um pixel correspondente.
- **Mais rápido:** dentro do laço, a única operação é uma soma (`x = x + x_inc`), muito mais barata para o processador do que a multiplicação (`m * x`) repetida em cada iteração do algoritmo analítico.

## Comparação: Analítico vs. DDA

| Característica | Algoritmo Analítico | DDA |
|---|---|---|
| Base matemática | Equação da reta (`y = mx+b`) | Incremento diferencial |
| Operação no laço | Multiplicação e adição | Apenas adição |
| Retas verticais | Falha (divisão por zero) | Funciona |
| Retas íngremes (\|m\|>1) | Falha (gera buracos) | Funciona |
