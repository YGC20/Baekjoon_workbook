#include <iostream>
#include <cmath>
using namespace std;
long long power(long long base, long long exp){
    long long res=1, mod=1000000007;
    while(exp>0){
        if(exp%2==1)    res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    long long N,M,A,H;
    cin>>N>>M>>A;
    cin>>H;
    long long result=power(M,N-1);
    cout<<result<<"\n";
    return 0;
}