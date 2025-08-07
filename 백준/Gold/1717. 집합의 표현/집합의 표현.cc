#include <iostream>
using namespace std;
int n,m;
int parent[1000001];
int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void unite(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(a<b) parent[b]=a;
        else parent[a]=b;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<=n;++i) parent[i]=i;
    while(m--){
        int c,a,b;
        cin>>c>>a>>b;
        if(c==0){
            unite(a,b);
        }
        else if(c==1){
            if(find(a)==find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}