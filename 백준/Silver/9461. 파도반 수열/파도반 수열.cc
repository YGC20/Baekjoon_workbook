#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T, N;
    cin>>T;
    long long dp[101]={0};
    dp[1]=dp[2]=dp[3]=1;
    for(int i=4;i<=100;i++)
        dp[i]=dp[i-2]+dp[i-3];
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<dp[N]<<"\n";
    }
    return 0;
}