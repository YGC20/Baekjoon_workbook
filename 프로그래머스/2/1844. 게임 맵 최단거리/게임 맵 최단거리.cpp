#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int n = static_cast<int>(maps.size());
    int m = static_cast<int>(maps[0].size());
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    vector<vector<int>> route(n, vector<int>(m,0));
    
    queue<pair<int, int>> que;
    route[0][0] = 1; maps[0][0] = 0;
    que.push({0,0});
    
    while(!que.empty()) {
        pair<int, int> cn = que.front(); que.pop();
        for(int i=0; i<4; ++i) {
            int nx = cn.first + dx[i];
            int ny = cn.second + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) { continue; }
            if(maps[nx][ny] == 0) { continue; }
            
            maps[nx][ny] = 0;
            route[nx][ny] = route[cn.first][cn.second] + 1;
            que.push({nx, ny});
        }
    }
    
    if(route[n-1][m-1] == 0) { answer = -1; }
    else { answer = route[n-1][m-1]; }
    
    return answer;
}