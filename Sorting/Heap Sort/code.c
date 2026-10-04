#include <stdio.h>

void heapify (int arr[], int n, int i) {
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l<n && arr[l]>arr[largest])
        largest = l;

    if (r<n && arr[r]>arr[largest])
        largest = r;

    if (largest != i) {

        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort (int arr[], int n) {

    for (int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}


int main () {
    int tamanho=10;
    int vetor[10] = {10,3,2,8,7,4,6,5,9,1};

    printf("\nVetor antes da ordenacao\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);
        
    heapSort(vetor, tamanho);

    printf("\nVetor ordenado\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);    

    return 0;
}