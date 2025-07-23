#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
bool visited[1001];
void bfs(const vector<vector<int>>& graph, int start_node){
    q.push(start_node);
    visited[start_node]=true;
    while(!q.empty()){
        int curNode = q.front();
        q.pop();
        for(int next:graph[curNode]){
            if(!visited[next]){
                q.push(next);
                visited[next]=true;
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> graph(N+1);
    for(int i=0;i<M;i++){
        int start,end;
        cin>>start>>end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    int graphCount=0;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            graphCount++;
            bfs(graph, i);
        }
    }
    cout<<graphCount<<"\n";
    return 0;
}