#include <stdio.h>
int main(void){
    int i, j, n, max=-1, dp[501][501];
    scanf("%d", &n);
    for(i=1; i<=n; ++i)
        for(j=1; j<=i; ++j)
            scanf("%d", &dp[i][j]);
    for(i=1; i<=n; ++i){
        for(j=1; j<=i; ++j){
            if(i==1)
                dp[i][j] += dp[i-1][j];
            else if(i==j)
                dp[i][j] += dp[i-1][j-1];
            else
                dp[i][j] += ((dp[i-1][j]>dp[i-1][j-1])?dp[i-1][j]:dp[i-1][j-1]);
            if(max<dp[i][j])
                max=dp[i][j];
        }
    }
    printf("%d\n", max);
    return 0;
}