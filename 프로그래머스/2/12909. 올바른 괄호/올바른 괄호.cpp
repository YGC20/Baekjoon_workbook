#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stk;
    for(char c:s){
        if(c=='(')  stk.push(c);
        else if(c==')'){
            if(stk.empty())    return false;
            stk.pop();
        }
    }
    if(!stk.empty())    answer=false;
    return answer;
}