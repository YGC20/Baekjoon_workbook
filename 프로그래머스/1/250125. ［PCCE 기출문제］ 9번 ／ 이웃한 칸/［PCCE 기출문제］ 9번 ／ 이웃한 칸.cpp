#include <string>
#include <vector>
using namespace std;
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string color = board[h][w];
    int s = board.size();
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    for(int dir=0;dir<4;++dir){
        int x=w+dx[dir];
        int y=h+dy[dir];
        if(0<=x&&x<s&&0<=y&&y<s){
            if(color==board[y][x])  answer++;
        }
    }
    return answer;
}