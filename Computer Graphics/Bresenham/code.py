x1, y1 = 2, 1
x2, y2 = 8, 4

## Algoritmo Bresenham
print("\nAlgoritmo Bresenham")
dx = x2 - x1
dy = y2 - y1

c1 = 2 * dy
c2 = 2 * dy - 2 * dx

p = 2 * dy - dx

y = y1

print(f"Constante 1: {c1} | Constante 2: {c2}")

for x in range(x1, x2 + 1):
    print(f"Calculado: ({x}, {y})")
    
    if p >= 0:
      y = y + 1
      p = p + c2
    else:
      p = p + c1