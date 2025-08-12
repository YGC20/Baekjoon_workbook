#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin>>s;
    stack<char> stk;
    int result=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')   stk.push(s[i]);
        else{
            stk.pop();
            if(s[i-1]=='('){
                result+=stk.size();
            }
            else if(s[i-1]==')'){
                result+=1;
            }
        }
    }
    cout<<result<<"\n";
    return 0;
}