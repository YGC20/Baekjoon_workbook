#include <iostream>
#include <algorithm>
using namespace std;
void solution(){
    int N;
    int arr[1001], dp[1001];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        dp[i]=1;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=i-1;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int max_val=0;
    for(int i=0;i<N;i++){
        if(dp[i]>max_val)
            max_val=dp[i];
    }
    cout<<max_val<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    solution();
    return 0;
}