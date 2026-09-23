#include <iostream>
using namespace std;


void selectionSort (int *vetor, int tamanho) {

    for (int i=0; i<tamanho-1; i++) {
        // guarda o indice do menor elemento
        int menor = i;
        // procura o menor valor aparti de i+1
        for (int j=i+1; j<tamanho; j++) 
            if (vetor[j] < vetor[menor]) 
                menor = j;
            
        swap(vetor[i], vetor[menor]);
    }
    
}

int main () {
    int tamanho=10;
    int vetor[tamanho] = {10,3,2,8,7,4,6,5,9,1};

    cout << "Vetor antes da ordenacao" << endl;
    for (int i=0; i<tamanho; i++)
        cout << '[' << vetor[i] << "] ";
        
    selectionSort(vetor, tamanho);

    cout << "\nVetor ordenado" << endl;
    for (int i=0; i<tamanho; i++)
        cout << '[' << vetor[i] << "] ";

    return 0;
}