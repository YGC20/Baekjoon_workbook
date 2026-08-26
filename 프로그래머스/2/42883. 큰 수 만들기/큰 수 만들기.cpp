#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string number, int k)
{
    stack<char> stk;
    for(auto& num : number) {
        while(!stk.empty() && k > 0 && stk.top() < num) { stk.pop(); --k; }
        stk.push(num);
    }
    
    while(k-- > 0 && !stk.empty()) { stk.pop(); }
        
    string result = "";
    while(!stk.empty()) {
        result += stk.top(); stk.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}