def quick_sort(array):
    if len(array) < 2:
        return array
    else:
        pivo = array[0]
        menores = [i for i in array[1:] if i <= pivo]
        maiores = [i for i in array[1:] if i >  pivo]

        return quick_sort(menores) + [pivo] + quick_sort(maiores)


vetor = [10, 3, 2, 8, 7, 4, 6, 5, 9, 1]

print("Vetor antes da ordenacao")
print(vetor)

vetor = quick_sort(vetor)

print("\nVetor ordenado")
print(vetor)