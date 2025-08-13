#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    getline(cin,s);
    stack<char> stk;
    long long result=0;
    long long temp=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stk.push('(');
            temp*=2;
        }
        else if(s[i]=='['){
            stk.push('[');
            temp*=3;
        }
        else if(s[i]==')'){
            if(stk.empty()||stk.top()!='('){
                result=0;
                break;
            }
            if(s[i-1]=='(') result+=temp;
            stk.pop();
            temp/=2;
        }
        else if(s[i]==']'){
            if(stk.empty()||stk.top()!='['){
                result=0;
                break;
            }
            if(s[i-1]=='[') result+=temp;
            stk.pop();
            temp/=3;
        }
    }
    if(!stk.empty()) result=0;
    cout<<result<<"\n";
    return 0;
}