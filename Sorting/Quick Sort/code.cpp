#include <iostream>
using namespace std;


int particionar (int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    pivo = vetor[fim]; 
    for (int j=inicio; j <= fim-1; j++) 
        if (vetor[j] <= pivo)
            swap(vetor[++i], vetor[j]);
    
    swap(vetor[i+1], vetor[fim]);
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
    int vetor[tamanho] = {10,3,2,8,7,4,6,5,9,1};

    cout << "Vetor antes da ordenacao" << endl;
    for (int e: vetor)
        cout << '[' << e << "] ";
        
    quickSort(vetor, 0, tamanho-1);

    cout << "\n\nVetor ordenado" << endl;
    for (int e: vetor)
        cout << '[' << e << "] ";

    return 0;
}