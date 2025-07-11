#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 2147483647

int N,M,S,E;
vector<pair<int,int>> adj[100001];
vector<int> dist;
void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[S]=0;
    pq.push({0,S});

    while(!pq.empty()){
        int curCost=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();
        if(curNode==E) break;
        if(dist[curNode]<curCost) continue;
        for(int i=0;i<adj[curNode].size();i++){
            int nextNode=adj[curNode][i].first;
            int nextCost=adj[curNode][i].second;
            int totalCost=curCost+nextCost;
            if(totalCost<dist[nextNode]){
                dist[nextNode]=totalCost;
                pq.push({totalCost,nextNode});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    dist.assign(N+1,INF);
    for(int i=0;i<M;i++){
        int s,e,w;
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
    }
    cin>>S>>E;
    dijkstra();
    cout<<dist[E]<<"\n";
    return 0;
}