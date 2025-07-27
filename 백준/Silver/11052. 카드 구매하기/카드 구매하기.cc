#include <iostream>
#define MAX 1001
using namespace std;
int Arr[MAX], DP[MAX];
int compareMAX(int a, int b){return(a>b)?a:b;}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>Arr[i];
    DP[0]=Arr[0]=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=i;j++)
            DP[i]=compareMAX(DP[i],DP[i-j]+Arr[j]);
    cout<<DP[N]<<"\n";
    return 0;
}