#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
    int x, y, distance, direction;
} Node;

bool operator>(const Node& a, const Node& b) { return a.distance > b.distance; }

int solution(vector<vector<int>> board)
{
    int rows = board.size(), cols = board[0].size();
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(4, 1e9)));
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({0,0,0,1}); dp[0][0][1] = 0;
    pq.push({0,0,0,3}); dp[0][0][3] = 0;
    
    while(!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        int x = curr.x, y = curr.y, dist = curr.distance, dir = curr.direction;
        if(dist > dp[x][y][dir]) { continue; }
        
        for(int d=0; d<4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx<0 || nx>=rows || ny<0 || ny>=cols) { continue; }
            if(board[nx][ny] == 1 || dir == (d ^ 1)) { continue; }
            
            int next = dist + 100 + ((dir != d)?500:0);
            if(next < dp[nx][ny][d]) {
                dp[nx][ny][d] = next;
                pq.push({nx, ny, next, d});
            }
        }
    }
    int minDist = dp[rows-1][cols-1][0];
    for(int d=1; d<4; ++d) {
        if(minDist > dp[rows-1][cols-1][d]) {
            minDist = dp[rows-1][cols-1][d];
        }
    }
    return minDist;
}