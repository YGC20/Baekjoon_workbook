#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int meal[3];
    cin>>meal[0]>>meal[1]>>meal[2];
    int count=0;
    for(int i=0;i<3;++i){
        int num;    cin>>num;
        if(num>meal[i])
            count+=num-meal[i];
    }
    cout<<count<<"\n";
    return 0;
}