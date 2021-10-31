#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define i64 long long
#define sz(x) (int)(x).size()
#define fs first
#define sc second
#define eb emplace_back
#define UNVISITED 0
#define VISITED 1
#define INF 0x3f3f3f3f
#define vi vector<int>
#define vl vector<i64> 
#define vvi vector<vi>
#define pii pair<int,int>
#define pll pair<i64,i64>
#define vpii vector<pii>
#define vpll vector<pll>
#define sti stack<int>
#define stii stack<pii>
#define mii map<int,int>
#define mll map<i64,i64>

using namespace std;

/*lista de Adjacencia nao direcionado e nao ponderado*/
/*BFS 0-1*/

int n; //número vertices
int m; //números arestas
int u, v, w; // vertice de uma aresta de u -> v, com peso w
vvi adj;
vi vis;//vis[u] diz u ja foi alcaçado em algum momento pelo bfs 

void bfs(int s){
    queue<int> fila;
    vis = vi(n+1, UNVISITED);

    fila.push(s);
    vis[s] = VISITED;
    while (!fila.empty()){
        int u = fila.front(); fila.pop();
        // logica do bfs para o vértice da vez
        cout << u << endl;
        for(int v : adj[u]){
            if (vis[v]==UNVISITED){
                fila.push(v);
                vis[v] = VISITED;
            }
        }
    }
}

int main(){_
    cin >> n >> m;
    adj = vvi(n+1);
    for (int i=m; i--;){
        cin >> u >> v;
        adj[u].eb(v);// u->v
        adj[v].eb(u);// v->u
    }
    //algoritmo
    bfs(1);
}