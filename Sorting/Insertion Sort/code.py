def insertion_sort(vetor):
    for i in range(1, len(vetor)):
        chave = vetor[i]
        j = i - 1

        while j >= 0 and vetor[j] > chave:
            vetor[j + 1] = vetor[j]
            j -= 1

        vetor[j + 1] = chave


vetor = [10, 3, 2, 8, 7, 4, 6, 5, 9, 1]

print("Vetor antes da ordenacao")
print(vetor)

insertion_sort(vetor)

print("\nVetor ordenado")
print(vetor)