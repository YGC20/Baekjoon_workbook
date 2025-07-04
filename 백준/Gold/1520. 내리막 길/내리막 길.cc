#include <iostream>
using namespace std;

int M, N;
int maps[501][501];
int dp[501][501];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dfs(int y, int x) {
    if(y==M-1 && x==N-1) return 1;
    if(dp[y][x] != -1)return dp[y][x];
    dp[y][x] = 0;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny>=0 && ny<M && nx>=0 && nx<N)
            if(maps[ny][nx] < maps[y][x])
                dp[y][x] += dfs(ny, nx);
    }

    return dp[y][x];
}

void solution(void) {
    cin >> M >> N;

    for(int i=0; i<M; i++){
        for(int j = 0; j < N; j++){
            cin >> maps[i][j];
            dp[i][j] = -1;
        }
    }

    int result = dfs(0, 0);
    cout << result << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}
