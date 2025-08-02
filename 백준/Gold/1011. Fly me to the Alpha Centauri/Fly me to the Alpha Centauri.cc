#include <iostream>
using namespace std;
int solve(int x, int y){
    long long d=y-x;
    long long k=1;
    while(1){
        if(k*k>=d) break;
        k++;
    }
    long long m=k*k-k;
    if(d>m) return (2*k-1);
    else if(d<=m) return (2*k-2);
    return 0;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T,x,y;
    cin>>T;
    while(T>0){
        cin>>x>>y;
        cout<<solve(x,y)<<"\n";
        T--;
    }
    return 0;
}