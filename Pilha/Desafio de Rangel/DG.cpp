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

int n;
vi x,res;
stii p;
 
int main() {_
    cin>>n;
    x = vi(n);
    res = vi(n,0);

    for (int i = 0; i < n; i++){ cin>>x[i]; }
    
    for (int i = 0; i < n; i++){
        while((!p.empty()) && (p.top().fs < x[i])){
            res[p.top().sc] = x[i];
            p.pop();
        }
        p.push({x[i],i});
    }

    for(int i = 0; i < sz(res); i++){
        if(i == 0){
            if(res[i] != 0) cout<<res[i];
            else cout<<"*";
        }else{
            if(res[i] != 0) cout<<" "<<res[i];
            else cout<<" *";
        }
    }cout<<endl;
}