#include <stdio.h>

int Binary_Search (int lista[], int tamanho, int item) {
    int alto  = tamanho - 1;
    int baixo = 0;

    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int chute = lista[meio];
        if (chute == item)
            return meio;
        if (chute > item)
            alto = meio - 1;
        else
            baixo = meio + 1;
    }

    return -1;
}


int main() {
    int lista[] = {1,3,5,7,9};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    int x;
    x = Binary_Search(lista, tamanho, 3);

    if (x != -1) 
        printf("O elemento esta na posicao %d.\n", x);
    else 
        printf("Elemento nao encontrado.\n");
        
    return 0;
}