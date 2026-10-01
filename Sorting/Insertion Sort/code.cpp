#include <iostream>
using namespace std;


void insertionSort (int *vetor, int tamanho) {

    for (int i=1; i<tamanho; i++) {
        // elemento a ser inserido na posição correta
        int chave = vetor[i];
        int j = i-1;

        // copia parte do vetor uma posição a frente
        while (j > -1 && vetor[j] > chave) {
            vetor[j+1] = vetor[j];
            j--;
        }
        
        // colar chave na posição correta    
        vetor[j+1] = chave;
    }

}   

int main () {
    int tamanho=10;
    int vetor[tamanho] = {10,3,2,8,7,4,6,5,9,1};

    cout << "Vetor antes da ordenacao" << endl;
    for (int i=0; i<tamanho; i++)
        cout << '[' << vetor[i] << "] ";
        
    insertionSort(vetor, tamanho);

    cout << "\nVetor ordenado" << endl;
    for (int i=0; i<tamanho; i++)
        cout << '[' << vetor[i] << "] ";

    return 0;
}