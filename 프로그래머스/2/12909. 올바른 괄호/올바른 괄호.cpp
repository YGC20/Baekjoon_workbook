#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for(auto& ch : s) {
        if(ch == ')') {
            if(!stk.empty() && stk.top() == '(') {
                stk.pop();
            }
            else {
                stk.push(ch);
                answer = false;
            }
        }
        else {
            stk.push(ch);
        }
    }
    if(!stk.empty()) {
        answer = false;
    }
    return answer;
}