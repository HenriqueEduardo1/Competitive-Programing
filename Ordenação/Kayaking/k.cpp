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

int n,m,x,res = INF;
vi c,vm,ax;
set<int> s;

int minDif(int a, int b, int v){
    int sm = 0;
    for(int i = 0; i < sz(c); i++)
        if(i != a && i != b) ax.push_back(c[i]);

    for(int i = 0; i < sz(ax)-1; i+=2)
        vm.push_back(abs(ax[i] - ax[i+1]));

    sort(vm.begin(), vm.end());
    for(int i = 0; i < sz(vm); i++){
        if(v > 0){
            sm += vm[i];
            v--;
        }
    }
    ax.clear();
    vm.clear();
    return sm;
}
int main() {_
    cin>>n;
    m = n-1;

    for(int i = 0; i < n*2; i++){
        cin>>x;
        c.push_back(x);
    }
    sort(c.begin(), c.end());

    for(int i = 0; i < sz(c)-1; i++){
        for(int j = i+1; j < sz(c); j++){
            res = min(res, minDif(i,j,m));
        }
    }
    cout<<res<<endl;
}