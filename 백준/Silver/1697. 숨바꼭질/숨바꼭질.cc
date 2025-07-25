#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
bool visited[MAX];
int bfs(int start, int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    visited[start] = true;

    while(!q.empty()){
        int curPos=q.front().first;
        int curTim=q.front().second;
        q.pop();

        if(curPos==end) return curTim;
        
        int nextPos1=curPos-1;
        int nextPos2=curPos+1;
        int nextPos3=curPos*2;

        if(nextPos1>=0&&!visited[nextPos1]){
            q.push({nextPos1,curTim+1});
            visited[nextPos1]=true;
        }
        if(nextPos2<MAX&&!visited[nextPos2]){
            q.push({nextPos2,curTim+1});
            visited[nextPos2]=true;
        }
        if(nextPos3<MAX&&!visited[nextPos3]){
            q.push({nextPos3,curTim+1});
            visited[nextPos3]=true;
        }
    }
    return -1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    cout<<bfs(N,K)<<"\n";
    return 0;
}