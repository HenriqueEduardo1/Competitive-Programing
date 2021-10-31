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

int m[101],n,x;
vl pd(1000001, -1);

int solve(int x){
    if(x == 0) return 0;

    if(pd[x] != -1) return pd[x];

    int ans = INF;

    for(int i = 1; i <= n; i++){
        if(x - m[i] >= 0)
            ans = min(ans, solve(x - m[i]) + 1);
    }
    pd[x] = ans;
    return pd[x];
}
 
int main() {_
    cin>>n>>x;

    for(int i = 1; i <= n; i++){
        cin>>m[i];
    }
    if(solve(x) != INF)
        cout<<solve(x)<<endl;
    else
        cout<<-1<<endl;
}