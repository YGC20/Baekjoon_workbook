#include <iostream>
using namespace std;
void solution(int n){
    int dp[1001] = {0};
    dp[1]=1, dp[2]=3;
    for(int i=3; i<=n; i++)
        dp[i]=(dp[i-1]+2*dp[i-2])%10007;
    cout<<dp[n]<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    solution(N);
    return 0;
}