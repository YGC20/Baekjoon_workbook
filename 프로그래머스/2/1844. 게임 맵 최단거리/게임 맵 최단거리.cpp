#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int rows = static_cast<int>(maps.size());
    int cols = static_cast<int>(maps[0].size());
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    vector<vector<int>> visited(rows, vector<int>(cols, -1));
    queue<pair<int,int>> que;
    
    que.push({0,0});
    visited[0][0] = 1;
    while(!que.empty()) {
        auto [x, y] = que.front(); que.pop();
        if(x == (rows-1) && y == (cols-1)) { break; }
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || nx>=rows || ny<0 || ny>=cols) { continue; }
            if(maps[nx][ny] == 0 || visited[nx][ny] != -1) { continue; }
            
            visited[nx][ny] = visited[x][y] + 1;
            que.push({nx, ny});
        }
    }
    
    answer = visited[rows-1][cols-1];
    return answer;
}