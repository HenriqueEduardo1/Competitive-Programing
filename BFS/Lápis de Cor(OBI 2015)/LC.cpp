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

int n;
vi d = {-1,0,1,0};
char a[1005][1005];
int dis[1005][1005];

void bfs(int i, int j){
    queue<pii> f;
    
    f.push({i,j});
    dis[i][j] = 0;

    while(!f.empty()){
        pii u = f.front();
        f.pop();

        for(int k = 0; k < 4; k++){
            int b = u.fs + d[k];
            int c = u.sc + d[3-k];

            if(dis[b][c] != -1){
                if((dis[u.fs][u.sc] + 1) < dis[b][c]){
                    if((dis[u.fs][u.sc] + 1) >= 9){
                        dis[b][c] = 9;
                        f.push({b,c});
                    }else{
                        dis[b][c] = dis[u.fs][u.sc] + 1;
                        f.push({b,c});
                    }
                }
            }        
        }
    }
}
int main() {_
    cin>>n;

    for (int i = 0; i <= n+1; i++){
        for (int j = 0; j <= n+1; j++){ dis[i][j] = -1; }}

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin>>a[i][j];
            dis[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if((a[i][j]) == '0'){
                bfs(i,j);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout<<dis[i][j];
        }cout<<endl;
    }
}