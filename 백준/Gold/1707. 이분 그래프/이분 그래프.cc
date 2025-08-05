#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int K,V,E;
vector<int> adj[20001];
int check[20001];
bool bfs(int startNode){
    queue<int> q;
    q.push(startNode);
    check[startNode]=1;
    while(!q.empty()){
        int next = q.front();
        q.pop();
        for(int v:adj[next]){
            if(check[v]==0){
                check[v]=3-check[next];
                q.push(v);
            }
            else if(check[v]==check[next]){
                return false;
            }
        }
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>K;
    while(K--){
        cin>>V>>E;
        for(int i=1;i<=V;i++) adj[i].clear();
        memset(check, 0, sizeof(check));

        for(int i=0;i<E;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool isBipartite=true;
        for(int i=1;i<=V;i++){
            if(check[i]==0){
                if(!bfs(i)){
                    isBipartite=false;
                    break;
                }
            }
        }

        if(isBipartite) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}