#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s){
    stack<char> stk;
    for(char a:s){
        if(!stk.empty()&&stk.top()==a)
            stk.pop();
        else
            stk.push(a);
    }
    if(stk.empty())
        return 1;
    else
        return 0;
}