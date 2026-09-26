def Binary_Search(lista, item):
    baixo = 0
    alto = len(lista) - 1

    while baixo <= alto:
        meio = (baixo + alto) // 2
        chute = lista[meio]
        if chute == item:
            return meio
        if chute > item:
            alto = meio - 1
        else:
            baixo = meio + 1

    return None


lista = [1,3,5,7,9]

x = Binary_Search(lista, 3)

if x != None:
    print(f"O elemento está na posição {x}.\n")
else: 
    print("Elemento não encontrado.\n")