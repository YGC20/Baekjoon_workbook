#include <stdio.h>
int main(void){
    int T, i, n, dp[11]={0};
    scanf("%d", &T);
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(i=4; i<11; ++i){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    for(i=0; i<T; ++i){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}