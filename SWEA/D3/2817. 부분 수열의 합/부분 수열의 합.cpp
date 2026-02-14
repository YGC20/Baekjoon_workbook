#include <iostream>
#include <vector>

void dfs(int n, int k, int* cnt, int idx, int sum, const std::vector<int>& nums)
{
    if(sum==k) {
        (*cnt)++;
        return;
    }

    if(idx==n || sum>k) {
        return;
    }

    dfs(n, k, cnt, idx+1, sum+nums[idx], nums);
    dfs(n, k, cnt, idx+1, sum, nums);
}

void solution(int test_case)
{
    int idx=0, target_value=0;
    std::cin>>idx>>target_value;

    std::vector<int> nums(idx);
    for(int i=0; i<idx; ++i) {
        std::cin>>nums[i];
    }

    int cnt = 0;
    dfs(idx, target_value, &cnt, 0, 0, nums);

    std::cout<<"#"<<test_case<<" "<<cnt<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case;
    if(std::cin>>test_case) {
        for(int i=1; i<=test_case; ++i) {
            solution(i);
        }
    }
    return 0;
}