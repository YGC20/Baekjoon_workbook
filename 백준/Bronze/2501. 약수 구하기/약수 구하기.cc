#include <iostream>
using namespace std;
void divisor(void){
    int N, K, divIndex=0, ans=0;
    bool flag=false;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        if(N%i==0) divIndex++;
        if(K==divIndex){
            ans=i;
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<ans<<"\n";
    else
        cout<<0<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    divisor();
    return 0;
}