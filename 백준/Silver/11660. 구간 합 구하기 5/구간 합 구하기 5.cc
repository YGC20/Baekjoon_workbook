#include <iostream>
using namespace std;
void solution(int n, int m){
    int dp[1025][1025] = {0};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int num;
            cin>>num;
            dp[i][j]=num+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }

    for(int i=0; i<m; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int sum = dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
        cout<<sum<<"\n";
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    solution(N,M);
    return 0;
}