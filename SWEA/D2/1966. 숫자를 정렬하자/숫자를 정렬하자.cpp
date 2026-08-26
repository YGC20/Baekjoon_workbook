#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    int T; std::cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        int N; std::cin >> N;
        std::vector<int> nums(N, 0);
        for(int i=0; i<N; ++i) { std::cin >> nums[i]; }
        std::sort(nums.begin(), nums.end());
        std::cout << "#" << tc << " ";
        for(int& n : nums) { std::cout << n << " "; }
        std::cout << std::endl;
    }
    return 0;
}