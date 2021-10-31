#include <bits/stdc++.h>
using namespace std;
string s,res;
stack<char> p;
int main(){
    cin>>s;

    for(int i = 0; i < s.size();i++){
        if(i==0){ p.push(s[i]); }
        else if((!p.empty()) && (p.top() == s[i])){ p.pop(); }
        else{ p.push(s[i]); }
    }
    while(!p.empty()){
        res += p.top();
        p.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}