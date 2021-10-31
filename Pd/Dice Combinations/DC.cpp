#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define i64 long long
#define sz(x) (int)(x).size()
#define fs first
#define sc second
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
 
vi dp(1e6+1,-1);
const int MOD = 1e9 + 7;
 
int solve(int n){
    i64 res = 0;
    if((n==1) || (n==0)) return 1;
    if(dp[n] != -1) return dp[n];
    for(int i = n-1; i >= max(n-6,0); i--){
        res += solve(i);
    }
    dp[n] = res%MOD;
    return res%MOD;
}
 
i64 n; 
 
int main() {_
    cin>>n;
    
    cout<<solve(n%MOD)<<endl;
}