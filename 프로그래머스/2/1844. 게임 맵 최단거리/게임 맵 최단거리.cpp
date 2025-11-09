#include<vector>
#include<queue>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int solution(vector<vector<int>> maps){
    int n = maps.size(), m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m,-1));
    queue<pair<int,int>> q;
    dist[0][0] = 1; q.push({0,0});
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(x==n-1 && y==m-1) return dist[x][y];
        for(int i=0;i<4;++i){
            int nx = x+dx[i], ny = y+dy[i];
            if(0<=nx&&nx<n && 0<=ny&&ny<m){
                if(maps[nx][ny]==1 && dist[nx][ny]==-1){
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
            
        }
    }
    return -1;
}