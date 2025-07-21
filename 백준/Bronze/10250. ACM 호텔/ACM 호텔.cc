#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T,H,W,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>H>>W>>N;
        int X,Y;
        if(N%H==0){
            X=N/H;
            Y=H*100;
        }
        else{
            X=N/H+1;
            Y=N%H*100;
        }
        cout<<Y+X<<"\n";
    }
    return 0;
}