#include <iostream>
#include <string>
#include <vector>
using namespace std;

void graph(int n, vector<int>& nums)
{
    nums.push_back(n);
    while(n > 1) {
        if(n % 2 == 0) { n /= 2; }
        else { n *= 3; n += 1;}
        nums.push_back(n);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<int> nums;
    graph(k, nums);
    
    int len = static_cast<int>(nums.size());
    vector<double> area(len-1, 0);
    for(int i=0; i<len-1; ++i) {
        area[i] = static_cast<double>(nums[i] + nums[i+1]) / 2.0;
    }

    vector<double> answer;
    for(vector<int>& sec : ranges) {
        int left = sec[0], right = len - 1 + sec[1];
        double n = 0;
        if(left > right) { n = -1.0; }
        else if(left == right) { n = 0.0; }
        else {
            for(int i=left; i<right; ++i) { n += area[i]; }
        }
        answer.push_back(n);
    }
    
    return answer;
}