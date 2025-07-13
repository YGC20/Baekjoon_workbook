#include <iostream>
using namespace std;

int M,N;
int primeNum[1000001];
void primeNumCheck(){
    primeNum[1]=0;
    for(int i=2;i<=N;i++)
        primeNum[i]=i;
    for(int i=2;i*i<=N;i++){
        if(primeNum[i]==0) continue;
        for(int j=i*i;j<=N;j+=i)
            primeNum[j]=0;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>M>>N;
    primeNumCheck();
    for(int i=M;i<=N;i++){
        if(primeNum[i]!=0)
            cout<<primeNum[i]<<"\n";
    }
    return 0;
}