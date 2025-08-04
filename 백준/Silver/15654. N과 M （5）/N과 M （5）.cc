#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
int arry[9];
vector<int> sequ;
bool visited[10001];
bool compare(int a, int b){ return a<b; }
void backtrack(int index){
    if(index==M){
        for(int i=0;i<M;i++) cout<<arry[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<N;i++){
        if(!visited[sequ[i]]){
            visited[sequ[i]]=true;
            arry[index]=sequ[i];
            backtrack(index+1);
            visited[sequ[i]]=false;
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        sequ.push_back(num);
    }
    sort(sequ.begin(),sequ.end(),compare);
    backtrack(0);
    return 0;
}