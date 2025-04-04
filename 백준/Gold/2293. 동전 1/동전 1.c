#include <stdio.h>
int main(void){
    int n, k, i, j, coin[101], dp[10001]={0};
    scanf("%d%d", &n, &k);
    for(i=0; i<n; ++i)
        scanf("%d", &coin[i]);
    dp[0]=1;
    for(i=0; i<n; ++i)
        for(j=coin[i]; j<=k; ++j)
            dp[j]+=dp[j-coin[i]];
    printf("%d", dp[k]);
    return 0;
}