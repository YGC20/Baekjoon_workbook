#include <string>
#include <vector>
#define DIV 1000000007
using namespace std;

int solution(int n)
{
    if(n%2!=0) return 0;
    int* dp = (int*)calloc((n+1),sizeof(int));
    dp[0] = 1; 
    if(n>=2) dp[2] = 3;
    for(int i=4; i<=n; i+=2) {
        dp[i] = (4LL*dp[i-2] - dp[i-4] + DIV)%DIV;
    }
    int num = dp[n];
    free(dp);
    return num;
}