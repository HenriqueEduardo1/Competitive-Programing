#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define i64 long long
#define sz(x) (int)(x).size()
#define fs first
#define sc second
#define eb emplace_back
#define UNV 0
#define VIS 1
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

int c,e,l,p,x,y,cont = 1;
vvi adj;
vi vis,dist,res;

void bfs(int s){
    queue<int> fila;
    vis = vi(c+1, UNV);
    dist = vi(c+1, INF);

    fila.push(s);

    vis[s] = VIS;
    dist[s] = 0;

    while (!fila.empty()){
        int u = fila.front();
        fila.pop();
        
        if(dist[u] <= p && u != l) res.eb(u);

        for(int v : adj[u]){
            if (vis[v] == UNV){
                fila.push(v);
                vis[v] = VIS;
                dist[v] = dist[u] + 1;
            }
        }
    }
}
 
int main(){_

    while(cin>>c>>e>>l>>p && (c||e||l||p)){
        adj = vvi(c+1);

        for (int i=e; i--;){
            cin>>x>>y;
            adj[x].eb(y);
            adj[y].eb(x);
        }
        
        bfs(l);
        sort(res.begin(), res.end());

        cout<<"Teste "<<cont<<endl;
        cont++;

        for(int i : res){
            cout<<i<<' ';
        }cout<<endl; cout<<endl;
        res.clear();
    }
}