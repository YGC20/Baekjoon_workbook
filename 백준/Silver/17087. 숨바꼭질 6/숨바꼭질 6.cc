#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

void solution(int n, int s){
    int dist[n];
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        dist[i] = abs(s-num);
    }
    if(n==1){
        cout<<dist[0]<<"\n";
        return;   
    }
    int resultGCD = dist[0];
    for(int i=1;i<n;i++)
        resultGCD = gcd(resultGCD,dist[i]);
    cout<<resultGCD<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, S;
    cin>>N>>S;
    solution(N,S);
    return 0;
}