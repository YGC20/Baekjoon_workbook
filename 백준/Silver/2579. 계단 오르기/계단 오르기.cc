#include <iostream>
#include <algorithm>
using namespace std;
int stair[301];
int dp[301];
void upStair(void){
    int N;
    cin>>N;
    for(int i=1;i<N+1;i++) cin>>stair[i];
    dp[1]=stair[1];
    if(N>=2) dp[2]=stair[1]+stair[2];
    if(N>=3)
        for(int i=3;i<=N;i++) dp[i]=max(dp[i-2],dp[i-3]+stair[i-1])+stair[i];
    cout<<dp[N]<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    upStair();
    return 0;
}