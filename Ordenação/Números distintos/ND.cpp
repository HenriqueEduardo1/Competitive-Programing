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

int n,a,res;
vi v;
 
int main() {_
    cin>>n;

    v.push_back(0);

    for(int i = 0; i < n; i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++){
        if(v[i] != v[i-1])
            res++;
    }
    cout<<res<<endl;
}