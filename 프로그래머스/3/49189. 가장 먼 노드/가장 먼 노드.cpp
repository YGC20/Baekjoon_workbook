#include <string>
#include <vector>
#include <queue>
using namespace std;

int maxVal = 0;

void bfs(vector<int>& visited, vector<vector<int>>& node, int idx)
{
    queue<int> que;
    que.push(idx);
    
    while(!que.empty()) {
        int curr = que.front();
        que.pop();
        
        for(auto n : node[curr]) {
            if(!visited[n]) {
                visited[n] = visited[curr] + 1;
                if(maxVal<visited[n]) {
                    maxVal = visited[n];
                }
                que.push(n);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    vector<int> visited(n+1, 0);
    vector<vector<int>> node(n+1);
    for(auto e : edge) {
        node[e[0]].push_back(e[1]);
        node[e[1]].push_back(e[0]);
    }
    
    visited[1] = 1;
    bfs(visited, node, 1);
    
    int cnt = 0;
    for(auto v : visited) {
        if(v==maxVal) {
            cnt++;
        }
    }
    return cnt;
}