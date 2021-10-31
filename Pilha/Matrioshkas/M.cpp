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
int s,d,e;
string a,l;
 
int main() {_
    while(getline(cin, l)) {
        stringstream ss;
        ss << l;
        while(ss >> a) { v.push_back(abs(stoi(a))); }

        bool t = true;
        p.push({v[0],0});

        for(int i = 1; i < sz(v); i++){
            if((!p.empty()) && (p.top().fs > v[i])){
                p.push({v[i],0});
            }else if((!p.empty()) && (p.top().fs == v[i]) && (p.top().fs > p.top().sc)){
                if(!p.empty()){
                    s = p.top().fs;
                    p.pop();
                    if(!p.empty()){ p.top().sc += s; }
                }
            }else{
                t = false;
                break;
            }
        }
        
        if(p.empty() && t){
            cout<<":-) Matrioshka!"<<endl;
        }else{
            cout<<":-( Try again."<<endl;
            while(!p.empty()){ p.pop(); }
        }
        v.clear();
    }   
}