#include <iostream>
#include <vector>
using namespace std;
int N,Q;
vector<pair<int,int>> graph[5001];
bool visited[5001];
void solve(int usado, int start_node){
    visited[start_node]=true;
    for(pair<int,int> node:graph[start_node]){
        if(node.second>=usado&&!visited[node.first])
            solve(usado,node.first);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>Q;
    for(int i=0;i<N-1;++i){
        int p,q,r;
        cin>>p>>q>>r;
        graph[p].push_back({q,r});
        graph[q].push_back({p,r});
    }
    while(Q--){
        int k,v,count=0;
        cin>>k>>v;
        for(int i=1;i<=N;++i)
            visited[i]=false;
        solve(k,v);
        for(int i=1;i<=N;++i){
            if(visited[i])
                count++;
        }
        cout<<count-1<<"\n";
    }
    return 0;
}