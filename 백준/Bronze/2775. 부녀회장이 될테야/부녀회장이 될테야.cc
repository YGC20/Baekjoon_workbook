#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int dp[15][15]={0};
    for(int i=0;i<15;++i)   dp[0][i]=i;
    for(int i=1;i<15;++i)
        for(int j=1;j<15;++j)
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        cout<<dp[k][n]<<"\n";
    }
    return 0;
}