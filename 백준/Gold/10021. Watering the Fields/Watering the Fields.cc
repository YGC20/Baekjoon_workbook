#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct NODE{ int x,y; };
struct Point{ long long x,y; };
struct Edge{
    int u,v;
    long long cost;
};
bool compareEdges(const Edge& a, const Edge& b){ return a.cost<b.cost; }

int parent[2001];
Point points[2001];
vector<Edge> edges;

int find_set(int x){
    if(parent[x]==x)    return x;
    return parent[x]=find_set(parent[x]);
}
void unite_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b)    parent[b]=a;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    long long C;
    cin>>N>>C;
    for(int i=0;i<N;++i)    parent[i]=i;
    for(int i=0;i<N;++i)    cin>>points[i].x>>points[i].y;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            long long dx=points[i].x-points[j].x;
            long long dy=points[i].y-points[j].y;
            long long cost=dx*dx+dy*dy;
            if(cost>=C) edges.push_back({i,j,cost});
        }
    }
    sort(edges.begin(),edges.end(),compareEdges);
    long long total_cost=0;
    int edges_count=0;
    for(const auto& edge:edges){
        if(find_set(edge.u)!=find_set(edge.v)){
            unite_sets(edge.u,edge.v);
            total_cost+=edge.cost;
            edges_count++;
        }
    }
    if(edges_count==N-1)    cout<<total_cost<<"\n";
    else    cout<<"-1\n";
    return 0;
}