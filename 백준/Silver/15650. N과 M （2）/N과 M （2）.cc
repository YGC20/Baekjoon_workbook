#include <iostream>
using namespace std;
int N,M;
int arr[9];
void backtrack(int index, int start){
    if(index==M){
        for(int i=0;i<M;i++) cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=start;i<=N;i++){
        arr[index]=i;
        backtrack(index+1,i+1);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    backtrack(0,1);
    return 0;
}