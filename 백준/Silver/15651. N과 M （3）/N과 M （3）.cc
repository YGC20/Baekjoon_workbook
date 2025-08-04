#include <iostream>
using namespace std;
int N,M;
int sequ[8];
void backtrack(int index){
    if(index==M){
        for(int i=0;i<M;i++) cout<<sequ[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        sequ[index]=i;
        backtrack(index+1);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    backtrack(0);
    return 0;
}