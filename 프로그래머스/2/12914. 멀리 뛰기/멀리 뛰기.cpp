#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> dp(2000,0);
    dp[1]=1, dp[2]=2;
    for(int i=3;i<=n;++i){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    long long answer = dp[n];
    return answer;
}