#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define vi vector<int>
#define stc stack<char>

using namespace std;

int n;
string s;
char pri,ult;
stc p1, p2;
 
int main() {_
    cin >> n;

    while(n--){
        cin>>s;
        pri = s[0];
        ult = s.back();
        vi s1, s2;

        for(char c : s){
            if(c == pri){
                s1.push_back('(');
                s2.push_back('(');
            }
            else if(c == ult){
                s1.push_back(')');
                s2.push_back(')');
            }
            else{
                s1.push_back('(');
                s2.push_back(')');
            }
        }
        for(int i = 0; i < s1.size(); i++){
            if((!p1.empty()) && (p1.top()=='(') && ((s1[i])==')')){ p1.pop(); }
            else{ p1.push(s1[i]); }
            if((!p2.empty()) && (p2.top()=='(') && ((s2[i])==')')){ p2.pop(); }
            else{ p2.push(s2[i]); }
        }
        if((p1.empty()) || (p2.empty())){
            cout<<"YES"<<endl;
            while(!p1.empty()){ p1.pop(); }
            while(!p2.empty()){ p2.pop(); }
        }else{
            cout<<"NO"<<endl;
            while(!p1.empty()){ p1.pop(); }
            while(!p2.empty()){ p2.pop(); }
        }
    }
}