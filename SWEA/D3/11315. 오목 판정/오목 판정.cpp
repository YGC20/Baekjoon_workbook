#include <iostream>
#include <vector>
using namespace std;

int N;
bool isFive;
vector<string> board;
int dx[8] = {-1,1,0,0,1,1,-1,-1};
int dy[8] = {0,0,-1,1,1,-1,1,-1};

void checkFive(int x, int y, int dir, int cnt)
{
    if(cnt>4) {
        isFive = true;
        return; 
    }
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx<0 || nx>=N || ny<0 || ny>=N) { return; }
    if(board[nx][ny] == '.') { return; }
    checkFive(nx, ny, dir, cnt+1);
}

int main(int argc, char** argv)
{
	int T; cin>>T;
    for(int tc=1; tc<=T; ++tc) {
        cin>>N;
        board.assign(N, "");
        for(int i=0; i<N; ++i) {
            cin>>board[i];
        } /* for i N */
        
        isFive = false;
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                if(board[i][j] == '.') { continue; }
                for(int d=0; d<8; ++d) {
                    checkFive(i, j, d, 1);
                    if(isFive) { break; }
                } /* for d 8 */
                if(isFive) { break; }
            } /* for j N */
            if(isFive) { break; }
        } /* for i N */
        
        if(isFive) { cout << "#" << tc << " YES" << endl; }
        else { cout << "#" << tc << " NO" << endl; }
    } /* for tc T */
    return 0;
}