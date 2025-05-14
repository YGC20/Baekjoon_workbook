#include <iostream>
using namespace std;
void coinZero(void){
    int N, K;
    cin>>N>>K;
    int A[N];
    for(int i=0;i<N;i++) cin>>A[i];
    int count=0;
    for(int i=N-1;i>=0;i--) if(A[i]<=K){
        count += K/A[i];
        K %= A[i];
    }
    cout<<count<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    coinZero();
    return 0;
}