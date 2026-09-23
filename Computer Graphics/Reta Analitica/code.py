import math
x1, y1 = 2, 1
x2, y2 = 8, 4

## Algoritmo reta analitica
print("\nAlgoritmo Reta Analitica")
dx = x2 - x1
dy = y2 - y1
    
m = dy / dx
b = y1 - (m * x1)

print(f"Equação: y = {m}x + {b}")

for x in range(x1, x2 + 1):
    y = (m * x) + b
    y = math.ceil(y)
    print(f"Calculado: ({x}, {y})")