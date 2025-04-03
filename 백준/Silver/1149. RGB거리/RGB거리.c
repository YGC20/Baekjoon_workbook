#include <stdio.h>
int main(void){
    int N, dp[1001][3];
    scanf("%d", &N);
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    dp[1][0]=r; dp[1][1]=g; dp[1][2]=b;
    for(int i=2; i<=N; ++i){
        scanf("%d%d%d", &r, &g, &b);
        dp[i][0] = r + ((dp[i-1][1]<dp[i-1][2])?dp[i-1][1]:dp[i-1][2]);
        dp[i][1] = g + ((dp[i-1][0]<dp[i-1][2])?dp[i-1][0]:dp[i-1][2]);
        dp[i][2] = b + ((dp[i-1][0]<dp[i-1][1])?dp[i-1][0]:dp[i-1][1]);
    }
    int ans = dp[N][0];
    ans = (ans<dp[N][1])?ans:dp[N][1];
    ans = (ans<dp[N][2])?ans:dp[N][2];
    printf("%d\n", ans);
    return 0;
}
