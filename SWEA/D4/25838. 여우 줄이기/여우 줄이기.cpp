#include<iostream>
#include<string>
#include<stack>

void solution(int testCase) {
    int index;
    std::cin>>index;
    
    std::string str;
    std::cin>>str;
    
    std::stack<char> stk;
    for(auto s : str) {
        stk.push(s);
        if(stk.size()>=3 && s=='x') {
            char third = stk.top();
            stk.pop();
            char second = stk.top();
            stk.pop();
            char first = stk.top();
            stk.pop();
            
            if(first == 'f' && second == 'o' && third == 'x') {
                continue;
            }
            else {
                stk.push(first);
                stk.push(second);
                stk.push(third);
            }
        }
    }
    std::cout<<stk.size()<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int testCase;
    if(std::cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            solution(i);
        }
    }
    return 0;
}