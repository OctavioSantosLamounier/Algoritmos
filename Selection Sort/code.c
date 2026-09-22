#include <stdio.h>
#include <stdlib.h>


void selectionSort (int *vetor, int tamanho) {

    for (int i=0; i<tamanho-1; i++) {
        // guarda o indice do menor elemento
        int menor = i;
        // procura o menor valor aparti de i+1
        for (int j=i+1; j<tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        // swap
        int auxiliar = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = auxiliar;
    }
    
}

int main () {
    int tamanho=10;
    int vetor[10] = {10,3,2,8,7,4,6,5,9,1};

    printf("\nVetor antes da ordenacao\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);
        
    selectionSort(vetor, tamanho);

    printf("\n\nVetor ordenado\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);    

    return 0;
}