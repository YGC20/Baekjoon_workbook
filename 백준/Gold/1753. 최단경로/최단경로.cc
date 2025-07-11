#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 2147483647

int V, E, K;
vector<pair<int,int>> adj[20001];
vector<int> dist;

void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[K]=0;
    pq.push({0,K});

    while(!pq.empty()){
        int curCost=pq.top().first;
        int curNode=pq.top().second;
        pq.pop();

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
    cin>>V>>E>>K;
    dist.assign(V+1,INF);

    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    dijkstra();
    for(int i=1;i<=V;i++){
        if(dist[i]==INF)
            cout<<"INF"<<"\n";
        else
            cout<<dist[i]<<"\n";
    }
    return 0;
}