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

i64 p[100001],n,k;
vl pd(100001, -1);

int solve(int n){
    if(n == 1) return 0; 
    if(n == 2) return abs(p[1] - p[2]); 
    if(pd[n] != -1) return pd[n];

    i64 m = INF;

    for(int i = k; i >= 1; i--){
        if(n-i >= 1){
            m = min(m,abs(p[n] - p[n-i]) + solve(n-i));
        }
    }
    pd[n] = m;
    return pd[n];
}
 
int main() {_
    cin>>n>>k;

    for(int i = 1; i <= n; i++){ cin>>p[i]; }
    cout<<solve(n)<<endl;
}