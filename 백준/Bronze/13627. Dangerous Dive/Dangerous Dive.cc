#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,R;
    int volunteers[10001]={0};
    cin>>N>>R;
    for(int i=0;i<R;++i){
        int num;    cin>>num;
        volunteers[num]++;
    }
    int count=0;
    for(int i=1;i<=N;++i){
        if(volunteers[i]==0){
            cout<<i<<" ";
            count++;
        }
    }
    if(count==0)    cout<<"*\n";
    else    cout<<"\n";
    return 0;
}