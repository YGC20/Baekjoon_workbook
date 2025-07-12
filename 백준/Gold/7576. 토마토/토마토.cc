#include <iostream>
#include <queue>
using namespace std;
int M,N;
int boxs[1001][1001]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> que;
void bfs(){
    while(!que.empty()){
        int x=que.front().first;
        int y=que.front().second;
        que.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=1 && nx<=N && ny>=1 && ny<=M && boxs[nx][ny]==0){
                que.push({nx,ny});
                boxs[nx][ny]=boxs[x][y]+1;
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>M>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int tomato;
            cin>>tomato;
            if(tomato==1)
                que.push({i,j});
            boxs[i][j]=tomato;
        }
    }
    bfs();
    int date=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(boxs[i][j]==0){
                cout<<"-1\n";
                return 0;
            }
            if(date<boxs[i][j])
                date=boxs[i][j];
        }
    }
    cout<<date-1<<"\n";
    return 0;
}