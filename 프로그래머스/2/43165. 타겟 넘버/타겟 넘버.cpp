#include <string>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, int target, int idx, int sum, int& cnt)
{
    if(idx == static_cast<int>(nums.size())) {
        if(target == sum) { cnt++; }
        return;
    }
    dfs(nums, target, idx+1, sum + nums[idx], cnt);
    dfs(nums, target, idx+1, sum - nums[idx], cnt);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}