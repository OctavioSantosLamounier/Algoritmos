def selection_sort(vetor):
    tamanho = len(vetor)

    for i in range(tamanho - 1):
        menor = i
        
        for j in range(i+1, tamanho):
            if vetor[j] < vetor[menor]: 
                menor = j
            
        vetor[i], vetor[menor] = vetor[menor], vetor[i]

    
vetor = [10, 3, 2, 8, 7, 4, 6, 5, 9, 1]   

print("Vetor antes da ordenacao")
for x in vetor: 
    print(f"[{x}] ", end="")

bubble_sort(vetor) 

print("\n\nVetor ordenado")
for x in vetor:
    print(f"[{x}] ", end="")