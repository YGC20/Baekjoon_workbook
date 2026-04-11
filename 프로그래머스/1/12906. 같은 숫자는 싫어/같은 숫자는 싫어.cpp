#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> p_arr) 
{
    stack<int> stk;
    for(int a : p_arr) {
        if(!stk.empty() && stk.top()==a) {
            continue;
        }
        else {
            stk.push(a);
        }
    }
    int stkLen = stk.size();
    vector<int> answer(stkLen);
    for(int i=stkLen-1; i>=0; i--) {
        answer[i]=stk.top();
        stk.pop();
    }
    return answer;
}