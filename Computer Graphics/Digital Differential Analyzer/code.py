import math
x1, y1 = 2, 1
x2, y2 = 8, 4

## Algoritmo DDA
print("\nAlgoritmo DDA")
dx = x2 - x1
dy = y2 - y1

steps = max(abs(dx), abs(dy))

x_inc = dx / steps
y_inc = dy / steps

x = x1
y = y1

print(f"Incremento X: {x_inc} | Incremento Y: {y_inc}")

for i in range(steps + 1):
    x_arredondado = math.ceil(x)
    y_arredondado = math.ceil(y)

    print(f"Calculado: ({x_arredondado}, {y_arredondado})")

    x = x + x_inc
    y = y + y_inc