#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool checkBalance(const string& s){
    stack<char> stk;
    for(char c:s){
        if(c=='('||c=='['){
            stk.push(c);
        }
        else if(c==')'){
            if(stk.empty()||stk.top()!='(') return false;
            stk.pop();
        }
        else if(c==']'){
            if(stk.empty()||stk.top()!='[') return false;
            stk.pop();
        }
    }
    return stk.empty();
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    while(true){
        getline(cin,s);
        if(s==".") break;
        if(checkBalance(s)) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}