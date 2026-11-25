#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {1,1,1,0,0,-1,-1,-1};


int DFS(vector<vector<int>> &G,int n, int m, int x, int y) {
    int count = 1;
    G[x][y] = 1;
    
    for (int k=0; k<8; k++) {
        int sx = x + dx[k];
        int sy = y + dy[k]; 
        
        if (sx<0||sx>=n||sy<0||sy>= m)
            continue;
        
        if (G[sx][sy] != 1)
            count += DFS(G,n,m,sx,sy);
    }
    
    return count;
}


int main() {
    fastio;

    int n,m;
    cin >> n >> m;
    
    int x,y,k;
    cin >> x >> y >> k;

    vector<vector<int>> G(n,vector<int>(m,0));
    
    while (k--) {
        int a,b;
        cin >> a >> b;
        G[--a][--b] = 1;  
    }
    
    int ans = DFS(G,n,m,--x,--y);

    cout << ans << endl;
    return 0;
}

/* 
input:               output:
5 5 1 1 5            10
3 1
3 2
3 3
3 4
3 5
*/