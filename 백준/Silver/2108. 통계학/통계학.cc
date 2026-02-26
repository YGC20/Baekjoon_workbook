#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solution(int test_case)
{
    int sum = 0;
    vector<int> nums(test_case);
    vector<int> counter(8001, 0);
    for(int i=0; i<test_case; ++i) {
        cin>>nums[i];
        sum+=nums[i];
        counter[nums[i]+4000]++;
    }
    sort(nums.begin(), nums.end());

    int arithmetic_mean = round((double)sum/test_case);
    int median = nums[test_case/2];
    int max_rep = 0;
    for(int i=0; i<=8000; ++i) {
        if(counter[i]>max_rep) {
            max_rep = counter[i];
        }
    }
    vector<int> modes;
    for(int i=0; i<=8000; ++i) {
        if(counter[i]==max_rep) {
            modes.push_back(i-4000);
        }
    }
    int mode = (modes.size()>1)?modes[1]:modes[0];
    int range = nums[test_case-1]-nums[0];

    cout<<arithmetic_mean<<"\n";
    cout<<median<<"\n";
    cout<<mode<<"\n";
    cout<<range<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    if(cin>>test_case) {
        solution(test_case);
    }
    return 0;
}