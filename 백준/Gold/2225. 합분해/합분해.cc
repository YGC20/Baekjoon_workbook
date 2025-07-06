#include <iostream>
using namespace std;
void solution(void){
    int N, K;
    cin>>N>>K;
    int dp[201][201] = {0};
    for(int i=1; i<=K; i++) dp[i][0]=1;
    for(int i=1; i<=K; i++)
        for(int j=1; j<=N; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
    cout<<dp[K][N]<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}