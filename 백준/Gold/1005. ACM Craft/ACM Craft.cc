#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int T,N,K,W;
vector<int> graph[1001];
int time[1001], input[1001], DP[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N>>K;

        for(int j=1;j<=N;j++)
            graph[j].clear();
        memset(input, 0, sizeof(input));
        memset(DP, 0, sizeof(DP));

        for(int j=1;j<=N;j++)
            cin>>time[j];
        for(int k=0;k<K;k++){
            int X,Y;
            cin>>X>>Y;
            graph[X].push_back(Y);
            input[Y]++;
        }
        cin>>W;

        queue<int> q;
        for(int j=1;j<=N;j++){
            if(input[j]==0){
                q.push(j);
                DP[j]=time[j];
            }
        }
        while(!q.empty()){
            int curNode=q.front();
            q.pop();
            for(int node:graph[curNode]){
                DP[node]=max(DP[node], DP[curNode]+time[node]);
                input[node]--;
                if(input[node]==0)
                    q.push(node);
            }
        }

        cout<<DP[W]<<"\n";
    }
    return 0;
}