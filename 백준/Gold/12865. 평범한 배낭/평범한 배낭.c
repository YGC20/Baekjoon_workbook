#include <stdio.h>
int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    int W[N], V[N];
    for(int i=0; i<N; ++i)
        scanf("%d %d", &W[i], &V[i]);
    int dp[N+1][K+1];
    for(int i=0; i<=N; ++i)
        for(int j=0; j<=K; ++j)
            dp[i][j]=0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=K; ++j){
            if(W[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=(dp[i-1][j] > dp[i-1][j-W[i-1]]+V[i-1]) ? dp[i-1][j] : dp[i-1][j-W[i-1]]+V[i-1];
        }
    }
    printf("%d\n", dp[N][K]);
    return 0;
}