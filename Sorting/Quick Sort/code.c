#include<stdio.h>
#include <stdlib.h>


int particionar (int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    pivo = vetor[fim]; 
    for (int j=inicio; j <= fim-1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            int aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }

    int aux = vetor[i+1];
    vetor[i+1] = vetor[fim];
    vetor[fim] = aux;
    return i+1;
}

void quickSort (int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivoIndice = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, pivoIndice - 1);
        quickSort(vetor, pivoIndice + 1, fim);
    }
}


int main () {
    int tamanho=10;
    int vetor[10] = {10,3,2,8,7,4,6,5,9,1};

    printf("\nVetor antes da ordenacao\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);
        
    quickSort(vetor, 0, tamanho-1);

    printf("\n\nVetor ordenado\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);    

    return 0;
}