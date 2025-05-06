#include <iostream>
using namespace std;
bool decimalCheck(int a){
    if(a<2) return false;
    for(int i=2;i*i<=a;i++)
        if(a%i==0) return false;
    return true;
}
void decimal(void){
    int M, N, sum=0, min=-1;
    cin>>M>>N;
    for(int i=M;i<=N;i++){
        if(decimalCheck(i)){
            if(min==-1) min=i;
            sum+=i;
        }
    }
    if(sum!=0) cout<<sum<<"\n";
    cout<<min<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    decimal();
    return 0;
}