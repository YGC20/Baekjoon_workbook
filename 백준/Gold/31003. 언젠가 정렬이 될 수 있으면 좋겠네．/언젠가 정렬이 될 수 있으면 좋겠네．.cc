#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int N;
int arr[3001], inDegree[3001]={0};
vector<int> graph[3001];
struct compare{
    bool operator()(pair<int,int>pair1,pair<int,int>pair2){
        return pair1.first>pair2.first;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
stack<pair<int,int>> stk;
vector<int> result;
int gcd(int a, int b){
    while(b!=0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void solve(){
    while(!pq.empty()){
        pair<int,int> pair1;
        while(1){
            pair1=pq.top();
            pq.pop();
            if(inDegree[pair1.second]==0)
                break;
            stk.push(pair1);
        }
        result.push_back(pair1.first);
        for(int i=0;i<graph[pair1.second].size();i++){
            int num=graph[pair1.second][i];
            inDegree[num]--;
        }
        while(!stk.empty()){
            pq.push(stk.top());
            stk.pop();
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        pq.push({arr[i],i});
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(gcd(arr[i], arr[j])!=1){
                graph[i].push_back(j);
                inDegree[j]++;
            }
        }
    }
    solve();
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}