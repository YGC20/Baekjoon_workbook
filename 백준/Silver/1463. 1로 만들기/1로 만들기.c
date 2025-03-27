#include <stdio.h>
int min(int num1, int num2){
    if(num1>num2)
        return num2;
    else
        return num1;
}
int main(void){
    int X, dp[1000001];
    scanf("%d", &X);
    dp[1]=0;
    for(int i=2; i<=X; ++i){
        dp[i] = dp[i-1]+1;
        if(i%2==0)
            dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3==0)
            dp[i] = min(dp[i], dp[i/3]+1);
    }
    printf("%d\n", dp[X]);
    return 0;
}