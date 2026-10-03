#include <stdio.h>
#define inf (1e9+10)

void merge (int A[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1+1];
    int R[n2+1];

    R[0] = inf;
    L[0] = inf;

    for (int i=n1,j=0; i>0; i--,j++)
        L[i] = A[p+j-1];
    for (int i=n2,j=0; i>0; i--,j++)
        R[i] = A[q+j];

    int i = n1;
    int j = n2;

    for (int k=p-1; k<r; k++) {
        if (L[i] <= R[j]) 
            A[k] = L[i--];
        else 
            A[k] = R[j--];
    }

}

void merge_sort (int A[], int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}


int main () {
    int tamanho=10;
    int vetor[10] = {10,3,2,8,7,4,6,5,9,1};

    printf("\nVetor antes da ordenacao\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);
        
    merge_sort(vetor, 1, tamanho);

    printf("\n\nVetor ordenado\n");
    for (int i=0; i<tamanho; i++)
        printf("[%d] ", vetor[i]);    

    return 0;
}