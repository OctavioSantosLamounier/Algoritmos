def bubble_sort(vetor):
    tamanho = len(vetor)

    for i in range(tamanho - 1):
        for j in range(tamanho - 1):
            if vetor[j] > vetor[j + 1]:
                vetor[j], vetor[j + 1] = vetor[j + 1], vetor[j]


vetor = [10, 3, 2, 8, 7, 4, 6, 5, 9, 1]   

print("Vetor antes da ordenacao")
print(vetor)

bubble_sort(vetor) 

print("\n\nVetor ordenado")
print(vetor)
