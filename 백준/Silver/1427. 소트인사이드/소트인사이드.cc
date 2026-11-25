#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string N = ""; cin >> N;
    int len = static_cast<int>(N.length());
    vector<int> nums(len, 0);
    for(int i=0; i<len; ++i) { nums[i] = N[i] - '0'; }
    sort(nums.rbegin(), nums.rend());
    for(auto& n : nums) { cout << n; }
    cout << "\n";
    return 0;
}