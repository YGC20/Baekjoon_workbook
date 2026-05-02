#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n)
{
    vector<int> nums;
    for(int i=1; i*i<=n; i++) {
        if(n%i==0) {
            nums.push_back(i);
            if(i*i!=n)
                nums.push_back(n/i);
        }
    }
    sort(nums.begin(), nums.end());
    return nums;
}