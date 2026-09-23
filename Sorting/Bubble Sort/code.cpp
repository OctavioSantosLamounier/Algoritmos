#include <iostream>
using namespace std;

void bubbleSort (int *vetor, int tamanho) {

    for (int i=0; i<tamanho-1; i++) 
        for (int j=0; j<tamanho-1; j++) 
            if (vetor[j] > vetor[j+1])
                swap(vetor[j], vetor[j+1]);

}

int main () {
    int tamanho=10;
    int vetor[tamanho] = {10,3,2,8,7,4,6,5,9,1};

    cout << "Vetor antes da ordenacao" << endl;
    for (int i=0; i<tamanho; i++)
        cout << '[' << vetor[i] << "] ";
        
    bubbleSort(vetor, tamanho);

    cout << "\nVetor ordenado" << endl;
    for (int i=0; i<tamanho; i++)
        cout << '[' << vetor[i] << "] ";

    return 0;
}