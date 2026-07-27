#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXVAL 1000000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int solution(int x, int y, int n)
{
    int i;
    
    if(x == y) return 0;
    
    int* dp = (int*)malloc((y + 1) * sizeof(int));
    for(i=0; i<=y; ++i) {
        dp[i] = MAXVAL;
    }
    
    dp[x] = 0;
    for(i=x; i<=y; ++i) {
        if(dp[i] == MAXVAL) continue;
        if((i + n) <= y) {
            dp[i + n] = MIN(dp[i + n], dp[i] + 1);
        }
        if((i * 2) <= y) {
            dp[i * 2] = MIN(dp[i * 2], dp[i] + 1);
        }
        if((i * 3) <= y) {
            dp[i * 3] = MIN(dp[i * 3], dp[i] + 1);
        }
    }
    int minVal = dp[y];
    if(minVal == MAXVAL)
        minVal = -1;
    
    free(dp);
    return minVal;
}