#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M, V;
bool graphs[1001][1001];
bool visited[1001];
void DFS(int V){
    visited[V]=true;
    cout<<V<<" ";
    for(int i=1;i<=N;i++){
        if(graphs[V][i]&&!visited[i]) DFS(i);
        if(i==N) return;
    }
}
void BFS(int V){
    queue<int> q;
    q.push(V);
    while(!q.empty()){
        int next = q.front();
        visited[next]=true;
        cout<<next<<" ";
        q.pop();
        for(int i=0;i<=N;i++)
            if(graphs[next][i]&&!visited[i]){
                q.push(i);
                visited[i]=true;
            }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int s, e;
    cin>>N>>M>>V;
    for(int i=0;i<M;i++){
        cin>>s>>e;
        graphs[s][e]=graphs[e][s]=true;
    }
    DFS(V);
    cout<<"\n";
    memset(visited, false, sizeof(visited));
    BFS(V);
    return 0;
}
