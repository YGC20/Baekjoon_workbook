#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> solution(int n, ll k)
{
    vector<ll> fact(21, 0);
    fact[0] = fact[1] = 1;
    for(int i=2; i<=n; ++i) { fact[i] = fact[i-1] * i; }
    
    vector<int> nums;
    for(int i=1; i<=n; ++i) { nums.push_back(i); }
    
    k--;
    vector<int> answer;
    while(n > 0) {
        if(n == 1) { answer.push_back(nums[0]); break; }
        
        int idx = k / fact[n-1];
        answer.push_back(nums[idx]);
        nums.erase(nums.begin() + idx);
        k %= fact[--n];
    }
    return answer;
}