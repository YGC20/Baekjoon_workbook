#include <string>
#include <vector>
using namespace std;

void dfs(vector<int>& numbers, int target, int sum, int idx, int& cnt)
{
    if(idx>=numbers.size()) {
        if(target==sum) cnt++;
        return ;
    }
    
    dfs(numbers, target, sum+numbers[idx], idx+1, cnt);
    dfs(numbers, target, sum-numbers[idx], idx+1, cnt);
}

int solution(vector<int> numbers, int target) 
{
    int cnt = 0;
    dfs(numbers, target, 0, 0, cnt);
    return cnt;
}