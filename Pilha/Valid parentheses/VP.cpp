#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> p;
int main(){
    cin>>s;

    for(int i = 0; i < s.size();i++){
        if((s[i]=='(') || (s[i]=='{') || (s[i]=='[')){
            p.push(s[i]);
        }else if(!p.empty() && (p.top()=='(') && (s[i]==')')){
            p.pop();
        }else if(!p.empty() && (p.top()=='{') && (s[i]=='}')){
            p.pop();
        }else if(!p.empty() && (p.top()=='[') && (s[i]==']')){
            p.pop();
        }
    }
    if(p.empty()){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}