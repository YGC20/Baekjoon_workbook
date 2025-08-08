#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
    int a, b, cost;
};
struct CompareEdge{
    bool operator()(const Edge& x, const Edge& y){ return x.cost>y.cost; }
};
int N,M;
int parent[1001];
int setFind(int x){
    if(parent[x]==x) return x;
    else return setFind(parent[x]);
}
bool setUnion(int a, int b){
    a=setFind(a);
    b=setFind(b);
    if(a!=b){
        parent[b]=a;
        return true;
    }
    else return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    for(int i=0;i<=N;i++) parent[i]=i;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({a,b,c});
    }
    int result=0;
    while(!pq.empty()){
        Edge curEdge=pq.top();
        pq.pop();
        if(setUnion(curEdge.a,curEdge.b)) result+=curEdge.cost;
    }
    cout<<result<<"\n";
    return 0;
}