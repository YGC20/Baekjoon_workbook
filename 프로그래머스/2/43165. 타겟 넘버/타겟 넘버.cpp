#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& num, int idx, const int& target, int sum, int& cnt)
{
    if(idx>=num.size()) {
        if(target==sum) {
            cnt++;
        }
        return;
    }
    
    dfs(num, idx+1, target, sum+num[idx], cnt);
    dfs(num, idx+1, target, sum-num[idx], cnt);
}

int solution(vector<int> number, int target)
{
    int cnt = 0;
    dfs(number, 0, target, 0, cnt);
    return cnt;
}