#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>& com, vector<bool>& vis){
    vis[i] = true;
    int n = (int)com.size();
    for(int j=0;j<n;++j){
        if(i!=j&&com[i][j]==1&&!vis[j])
            dfs(j,com,vis);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n,false);
    int answer = 0;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            answer++;
            dfs(i,computers,visited);
        }
    }
    return answer;
}