#include <iostream>
using namespace std;

void solution(){
    bool isPrime[1000001];
    for(int i=0;i<1000000;i++)
        isPrime[i]=true;
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=1000000;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=1000000;j+=i)
                isPrime[j]=false;
        }
    }

    int num;
    while(true){
        cin>>num;
        if(num==0) break;
        for(int i=3;i<=num/2;i+=2){
            if(isPrime[i]&&isPrime[num-i]){
                cout<<num<<" = "<<i<<" + "<<num-i<<"\n";
                break;
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    solution();
    return 0;
}