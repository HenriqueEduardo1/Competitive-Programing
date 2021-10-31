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

int u,v,n,m,res;
vvi adj;
vi vis;

int bfs(int s){
    queue<int> f;
    int ans = 0;
    vis = vi(n+1, UNVISITED);
    
    f.push(s);
    vis[s] = VISITED;

    while(!f.empty()){
        int u = f.front();
        f.pop();
        ans++;

        for(int v : adj[u]){
            if(vis[v] == UNVISITED){
                f.push(v);
                vis[v] = VISITED;
            }
        }
    }
    return ans;
}
int main() {_
    int a;

    while(cin>>n>>m){
        adj = vvi(n+1);
        while(m--){
            cin>>u>>v;
            adj[u].eb(v);
            adj[v].eb(u);
        }
        cin>>a;
        cout<<bfs(a)<<endl;
        vis.clear();
        adj.clear();
    }
}