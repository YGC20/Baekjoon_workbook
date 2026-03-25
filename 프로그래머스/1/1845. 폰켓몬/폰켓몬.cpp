#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size()/2;

    int cnt = 0;
    vector<bool> check_num(200001, false);
    for(int num : nums) {
        if(!check_num[num]) {
            check_num[num] = true;
            cnt++;
        }
    }

    if(n>cnt) {
        return cnt;
    }
    else {
        return n;
    }
}