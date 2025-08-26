#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Pawn{ int x,y,m; };
int N,K;
int board[13][13];
vector<int> maps[13][13];
Pawn pawns[11];
int dx[]={0,0,0,-1,1};
int dy[]={0,1,-1,0,0};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N>>K;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            cin>>board[i][j];
    for(int i=1;i<=K;++i){
        Pawn p;
        cin>>p.x>>p.y>>p.m;
        pawns[i]=p;
        maps[p.x][p.y].push_back(i);
    }
    for(int turn=1;turn<=1000;++turn){
        for(int i=1;i<=K;++i){
            Pawn& p=pawns[i];
            if(maps[p.x][p.y][0]!=i)    continue;
            auto it=find(maps[p.x][p.y].begin(),maps[p.x][p.y].end(),i);
            int pos=distance(maps[p.x][p.y].begin(),it);
            vector<int> temp;
            for(int j=pos;j<maps[p.x][p.y].size();++j)
                temp.push_back(maps[p.x][p.y][j]);
            maps[p.x][p.y].erase(maps[p.x][p.y].begin()+pos,maps[p.x][p.y].end());
            int nm = p.m;
            int nx=p.x+dx[nm];
            int ny=p.y+dy[nm];
            if(nx<1||nx>N||ny<1||ny>N||board[nx][ny]==2){
                if(nm==1)  nm=2;
                else if(nm==2) nm=1;
                else if(nm==3) nm=4;
                else if(nm==4) nm=3;
                nx=p.x+dx[nm];
                ny=p.y+dy[nm];
                if(nx<1||nx>N||ny<1||ny>N||board[nx][ny]==2){
                    maps[p.x][p.y].insert(maps[p.x][p.y].end(),temp.begin(),temp.end());
                    continue;
                }
            }
            p.m = nm;
            if(board[nx][ny]==1)    reverse(temp.begin(),temp.end());
            maps[nx][ny].insert(maps[nx][ny].end(),temp.begin(),temp.end());
            for(int t:temp){
                pawns[t].x=nx;
                pawns[t].y=ny;
            }
            if(maps[nx][ny].size()>=4){
                cout<<turn<<"\n";
                return 0;
            }
        }
    }
    cout<<"-1\n";
    return 0;
}