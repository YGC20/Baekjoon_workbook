#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> maps)
{
    int rows = static_cast<int>(maps.size());
    int cols = static_cast<int>(maps[0].length());
    vector<int> answer;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    int r, c;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    for(r=0; r<rows; ++r) {
        for(c=0; c<cols; ++c) {
            if(maps[r][c]=='X' || visited[r][c]) { continue; }
            queue<pair<int,int>> que;
            que.push({r,c});
            visited[r][c] = true;
            
            int cost = 0;
            while(!que.empty()) {
                auto [x, y] = que.front(); que.pop();
                cost += (maps[x][y] - '0');
                
                for(int n=0; n<4; ++n) {
                    int nx = x + dx[n];
                    int ny = y + dy[n];
                    
                    if(nx<0 || nx>=rows || ny<0 || ny>=cols) { continue; }
                    if(maps[nx][ny]=='X' || visited[nx][ny]) { continue; }
                    visited[nx][ny] = true;
                    que.push({nx,ny});
                }
            }
            answer.push_back(cost);
        }
    }
    
    if(answer.empty()) { answer.push_back(-1); }
    else { sort(answer.begin(), answer.end()); }
    return answer;
}