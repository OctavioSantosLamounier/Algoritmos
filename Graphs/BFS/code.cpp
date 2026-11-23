#include <bits/stdc++.h>
using namespace std;
#define inf 1e9+10

struct Vertice{
    vector<int> adj;   // lista de adjacência
    char cor = 'B';    // Branco
    int pai = -1;      // pai
    int dist = 0;      // distancia
};

void BFS(vector<Vertice> &G, int s){
    // limpa todos vertices 
    for(Vertice &u: G){
        u.cor = 'B';
        u.dist = inf;
        u.pai = -1;
    }
    // define o vertice de partida
    G[s].cor = 'C';
    G[s].dist = 0;
    G[s].pai = -1;
    queue<int> qv;
    qv.push(s);
    // percorre tudo
    while(!qv.empty()){
        int u = qv.front();
        qv.pop();
        // pecorre todos vertices adjacentes
        for(int v: G[u].adj)
            if(G[v].cor == 'B'){
                G[v].cor = 'C';
                G[v].dist = G[u].dist + 1;
                G[v].pai = u;
                qv.push(v);
            }
        // final do processamento
        G[u].cor = 'P';
    }
}


int main() {
    int V,e;

    cin >> V >> e;
    vector<Vertice> G(V);

    while(e--){
        int u,v;
        cin >> u >> v ;
        u--; v--;

        G[u].adj.push_back(v);
        G[v].adj.push_back(u);
        
    }
    
    BFS(G,0); 

    // recostrução de caminho
    
    vector<int> path;
    path.push_back(V-1);
    while(G[path.back()].pai != -1)
        path.push_back(G[path.back()].pai);
    
    // saida
    if(G[V-1].dist != 1e9+7){
        cout << G[V-1].dist+1 << endl;
        for(auto i=path.rbegin(); i!=path.rend(); i++)
            cout << *i+1 << ' ';
    }
    else
        cout << "IMPOSSIBLE";

    cout << endl;

    return 0;
}
