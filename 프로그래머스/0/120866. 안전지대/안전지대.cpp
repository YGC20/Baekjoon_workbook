#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int raw = board.size();
    int col = board[0].size();
    int safeZone = raw * col;
    
    vector<vector<int>> boxs = board;
    for(int x=0; x<raw; x++) {
        for(int y=0; y<col; y++) {
            if(board[x][y]==1) {
                for(int dx=x-1; dx<=x+1; dx++) {
                    for(int dy=y-1; dy<=y+1; dy++) {
                        if((0<=dx && dx<raw) && (0<=dy && dy<col)) {
                            boxs[dx][dy] = 1;
                        }
                    }
                }
            }
        }
    }
    
    int cnt = 0;
    for(int x=0; x<raw; x++) {
        for(int y=0; y<col; y++) {
            if(boxs[x][y]==1) {
                cnt++;
            }
        }
    }
    return safeZone - cnt;
}