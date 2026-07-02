#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;

ll solution(int n)
{
    int i;
    ll dp[2001] = {0};
    dp[1] = 1; dp[2] = 2;
    for(i=3; i<=n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    return dp[n];
}