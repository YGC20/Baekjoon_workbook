#include <iostream>
#include <vector>

void solution(int num)
{
    std::vector<int> nums(num);
    for(int i=0; i<num; ++i) {
        std::cin>>nums[i];
    }

    int current_sum = nums[0];
    int max_num = nums[0];
    for(int i=1; i<num; ++i) {
        current_sum = (nums[i]>(current_sum+nums[i]))?nums[i]:(current_sum+nums[i]);
        if(current_sum>max_num) {
            max_num = current_sum;
        }
    }
    std::cout<<max_num<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    if(std::cin>>num) {
        solution(num);
    }
    return 0;
}