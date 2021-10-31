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

int n,m,res;
vi d = {-1,0,1,0};
char a[1005][1005];

void bfs(int i, int j){
    queue<pii> f;
    
    f.push({i,j});

    while(!f.empty()){
        pii u = f.front();
        f.pop();

        for(int k = 0; k < 4; k++){
            int b = u.fs + d[k];
            int c = u.sc + d[3-k];
            if(a[b][c] == '.'){
                f.push({b,c});
                a[b][c] = '#';
            }
        }
    }
}
int main() {_
    cin>>n>>m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if((a[i][j]) == '.'){
                bfs(i,j);
                res++;
            }
        }
    }
    cout<<res<<endl;
}