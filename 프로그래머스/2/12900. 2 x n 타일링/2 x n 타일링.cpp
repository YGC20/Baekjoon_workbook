#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int i, result;
    int* dp = (int*)malloc((n+1)*sizeof(int));
    dp[0] = 0; dp[1] = 1; dp[2] = 2;
    
    for(i=3; i<=n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }
    result = dp[n];
    free(dp);
    return result;
}