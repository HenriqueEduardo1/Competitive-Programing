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

vi v;
stii p;
int res;

int main() {_

    v = {4,5,8,1};
    v.push_back(0);

    for(int i = 0; i < sz(v); i++){
        if((!p.empty()) && (v[i] < p.top().fs)){
            int ult = i;
            while((!p.empty()) && (v[i] < p.top().fs)){
                res = max(res,((i-p.top().sc) * (p.top().fs)));
                ult = p.top().sc;
                p.pop();
            }
            p.push({v[i],ult});
        }else{
            p.push({v[i],i});
        }
    }
    cout<<res<<endl;
}