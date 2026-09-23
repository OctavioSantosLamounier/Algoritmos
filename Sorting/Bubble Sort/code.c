#include <stdio.h>
#include <stdlib.h>

void bubbleSort (int *vetor, int tamanho) {

    for (int i=0; i<tamanho-1; i++) {

        for (int j=0; j<tamanho-1; j++) {

            if (vetor[j] > vetor[j+1]) {
                // swap
                int auxiliar = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxiliar;
            }
        }
    }
    
}

int main () {
    int tamanho=10;
    int vetor[10] = {10,3,2,8,7,4,6,5,9,1};

    printf("\nVetor antes da ordenacao\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);
        
    bubbleSort(vetor, tamanho);

    printf("\n\nVetor ordenado\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);    

    return 0;
}