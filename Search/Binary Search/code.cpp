#include <iostream>
#include <vector>
using namespace std;

int Binary_Search (vector<int> lista, int item) {
    int baixo = 0;
    int alto  = lista.size() - 1;

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
    vector<int> lista = {1,3,5,7,9};

    int x;
    x = Binary_Search(lista, 3);

    if (x != -1) 
        cout << "O elemento esta na posicao " << x << '.' << endl;
    else 
        cout << "Elemento nao encontrado." << endl;

    return 0;
}