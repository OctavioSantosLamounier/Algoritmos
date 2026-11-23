#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int tempo = 0;

struct Vertice {
    vector<int> adj;   // lista de adjacência
    char cor = 'B';    // Branco
    int pai = -1;      // pai
    int td;            // tempo descoberta
    int tf;            // tempo finalização
};

void DFS_Visita(vector<Vertice> &G, int u) {
    tempo++;
    G[u].td  = tempo;
    G[u].cor =   'C';

    // varre adjcentes
    for (auto v : G[u].adj)
        // compara se n foi verificado
        if (G[v].cor == 'B') {
            G[v].pai = u;
            DFS_Visita(G, v);
        }
    // execultado na volta dos vertices
    tempo++;
    G[u].cor =   'P';
    G[u].tf  = tempo;
}

void DFS(vector<Vertice> &G) {
    tempo = 0;
    // limpa a compararação
    for (auto &i : G) {
        i.cor = 'B';
        i.pai = -1;
    }
    // precessa vertice a vertice
    for (int i=0; i<G.size(); i++)
        // compara se n foi verificado
        if (G[i].cor == 'B')
            DFS_Visita(G, i);
        // execultado na volta dos vertices
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<Vertice> G(n);

    // loop de entrada
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;

        // remova um se for grafo direcionado
        G[x].adj.push_back(y);
        G[y].adj.push_back(x); 
    }

    // execulta a função
    DFS(G);

     // exibição
    for (int i=0; i<n; i++) {
        cout << "Vertice " << i+1 << endl;
        cout << "Pai: " << G[i].pai + 1 << endl;
        cout << "Descoberta: " << G[i].td << endl;
        cout << "Finalizacao: " << G[i].tf << endl;
        cout << endl;
    } 

    return 0;
}