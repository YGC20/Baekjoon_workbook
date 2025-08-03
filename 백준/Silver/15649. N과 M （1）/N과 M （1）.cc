#include <iostream>
using namespace std;
int N,M;
int seq[9];
bool visited[9];
void backtrack(int depth){
    if(depth==M){
        for(int i=0;i<M;i++) cout<<seq[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            seq[depth]=i;
            backtrack(depth+1);
            visited[i]=false;
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    backtrack(0);
    return 0;
}