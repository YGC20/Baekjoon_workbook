#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    int i;
    int len = static_cast<int>(prices.size());
    vector<int> answer(len, 0);
    stack<int> stk;
    
    for(i=0; i<len; ++i) {
        while(!stk.empty() && prices[stk.top()] > prices[i]) {
            int idx = stk.top(); stk.pop();
            answer[idx] = i - idx;
        }
        stk.push(i);
    }
    
    while(!stk.empty()) {
        int idx = stk.top(); stk.pop();
        answer[idx] = len - 1 - idx;
    }
    return answer;
}