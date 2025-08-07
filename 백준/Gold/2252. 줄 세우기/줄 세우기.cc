#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<int> graph[32001];
vector<int> result;
int inDegree[32001];
void topologicalSort(){
    queue<int> q;
    for(int i=1;i<=N;i++)
        if(inDegree[i]==0) q.push(i);
    
    while(!q.empty()){
        int curStudent = q.front();
        result.push_back(curStudent);
        q.pop();
        for(int ns:graph[curStudent])
            if(--inDegree[ns]==0) q.push(ns);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++) inDegree[i]=0;
    while(M--){
        int A,B;
        cin>>A>>B;
        inDegree[B]++;
        graph[A].push_back(B);
    }
    topologicalSort();
    for(int r:result) cout<<r<<" ";
    cout<<"\n";
    return 0;
}