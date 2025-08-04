#include <iostream>
using namespace std;
int N,M;
int sequ[9];
void backtrack(int index, int start){
    if(index==M){
        for(int i=0;i<M;i++) cout<<sequ[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=start;i<=N;i++){
        sequ[index]=i;
        backtrack(index+1,i);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    backtrack(0,1);
    return 0;
}