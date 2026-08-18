#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> rooms;
vector<vector<int>> dp;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int dfs(int x, int y)
{
    if(dp[x][y] != 0) { return dp[x][y]; }
    dp[x][y] = 1;
    for(int i=0; i<4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || nx>=N || ny<0 || ny>=N) { continue; }
        if((rooms[nx][ny] - rooms[x][y]) == 1) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
	}
    return dp[x][y];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int testCase, T;
    cin >> T;
    for(testCase=1; testCase<=T; ++testCase) {
        cin >> N;
        rooms.assign(N, vector<int>(N, 0));
        dp.assign(N, vector<int>(N, 0));
        
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                cin >> rooms[i][j];
            } /* for j */
        } /* for i */
        
        int maxDist = 0;
        int minRoomNum = 1e9;
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                int dist = dfs(i, j);
                if(dist > maxDist) {
                    maxDist = dist;
                    minRoomNum = rooms[i][j];
                } else if(dist == maxDist) {
                    if(rooms[i][j] <minRoomNum) { minRoomNum = rooms[i][j]; }
                }
            } /* for j */
        } /* for i */
        
        cout << "#" << testCase << " " << minRoomNum << " " << maxDist << "\n";
    } /* for testCase */
    return 0;
}