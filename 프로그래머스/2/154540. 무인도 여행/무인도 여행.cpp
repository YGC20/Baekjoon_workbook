#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<string>& maps, 
        vector<vector<bool>>& visited, int x, int y)
{
    int i, sum = 0;
    int col = maps.size();
    int row = maps[0].size();
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    
    queue<pair<int,int>> que;
    visited[x][y] = true;
    sum = maps[x][y] - '0';
    que.push({x, y});
    
    while(!que.empty()) {
        int currX = que.front().first;
        int currY = que.front().second;
        que.pop();
        
        for(i=0; i<4; ++i) {
            int nx = currX + dc[i];
            int ny = currY + dr[i];
            if(nx<0 || nx>=col || ny<0 || ny>=row) { continue; }
            if(visited[nx][ny] || maps[nx][ny]=='X') { continue; }
            visited[nx][ny] = true;
            sum += maps[nx][ny] - '0';
            que.push({nx,ny});
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps)
{
    int i, j;
    int col = maps.size();
    int row = maps[0].size();
    vector<vector<bool>> visited(col, vector<bool>(row, false));
    
    vector<int> answer;
    for(i=0; i<col; ++i) {
        for(j=0; j<row; ++j) {
            if(maps[i][j] == 'X' || visited[i][j]) { continue; }
            int num = bfs(maps, visited, i, j);
            answer.push_back(num);
        }
    }
    if(answer.empty()) { answer.push_back(-1); }
    sort(answer.begin(), answer.end());
    
    return answer;
}