#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int moveRobot(vector<string>& board, int sx, int sy)
{
    int row = board.size(), col = board[0].length();
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    vector<vector<int>> visited(row, vector<int>(col, -1));
    queue<tuple<int, int, int>> que;
    visited[sx][sy] = 0;
    que.push({sx, sy, 4});

    while(!que.empty()) {
        auto curr = que.front(); que.pop();
        int x = get<0>(curr);
        int y = get<1>(curr);
        int dir = get<2>(curr);
        if(board[x][y] == 'G') { return visited[x][y]; }

        for(int i=0; i<4; ++i) {
            if((dir^1) == i) { continue; }
            int nx = x + dx[i], ny = y + dy[i];

            if(nx<0 || nx>=row || ny<0 || ny>=col) { continue; }
            if(board[nx][ny] == 'D') { continue; }
            while(((nx+dx[i])>=0 && (nx+dx[i])<row 
            && (ny+dy[i])>=0 && (ny+dy[i])<col) 
            && board[nx+dx[i]][ny+dy[i]] != 'D') {
                nx += dx[i]; ny += dy[i];
            }
            if(visited[nx][ny] == -1) {
                visited[nx][ny] = visited[x][y] + 1;
                que.push({nx, ny, i});
            }
        }
    }
    return -1;
}

int solution(vector<string> board)
{
    int result = 0;
    int row = board.size(), col = board[0].length();
    for(int i=0; i<row; ++i) {
        for(int j=0; j<col; ++j) {
            if(board[i][j] == 'R') { result = moveRobot(board, i, j); }
        }
    }
    return result;
}