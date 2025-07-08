#include <iostream>
#include <string>
#include <queue>
using namespace std;
int maze[101][101] = {0};
int dist[101][101] = {0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N, M;

void bfs(int start_x, int start_y){
    queue<pair<int, int>> q;
    q.push({start_x,start_y});
    dist[start_x][start_y]=1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=1 && nx<=N && ny>=1 && ny<=M && maze[nx][ny]==1 && dist[nx][ny]==0){
                q.push({nx,ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

void solution(){
    for(int i=1; i<=N; i++){
        string row;
        cin>>row;
        for(int j=0; j<=M; j++){
            maze[i][j+1] = row[j]-'0';
        }
    }
    bfs(1,1);
    cout<<dist[N][M]<<"\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>M;
    solution();
    return 0;
}