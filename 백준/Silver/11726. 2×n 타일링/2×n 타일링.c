#include <stdio.h>
int main(void){
    int n, i, dp[1001]={0};
    dp[1]=1; dp[2]=2;
    scanf("%d", &n);
    for(i=3; i<=n; ++i)
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    printf("%d\n", dp[n]);
    return 0;
}
