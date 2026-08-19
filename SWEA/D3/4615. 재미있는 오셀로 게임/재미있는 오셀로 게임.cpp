#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

int N, M;
int dx[8] = {-1,1,0,0,-1,1,-1,1};
int dy[8] = {0,0,-1,1,-1,-1,1,1};

bool checkChip(int x, int y, int c, int dir)
{
    if(x<0 || x>=N || y<0 || y>=N) { return false; }
    if(board[x][y] == 0) { return false; }
    if(board[x][y] == c) { return true; }
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    bool canFlip = checkChip(nx, ny, c, dir);
    if(canFlip) {
        board[x][y]^=3;
        return true;
    }
    return false;
}

void changeChip(int x, int y, int c)
{
    for(int i=0; i<8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || nx>=N || ny<0 || ny>=N) { continue; }
        if(board[nx][ny] == c) { continue; }
        checkChip(nx, ny, c, i);
    } /* for i */
}

int main(int argc, char** argv)
{
	int T; cin>>T;
	for(int tc=1; tc<=T; ++tc) {
        cin>>N>>M;
        board.assign(N, vector<int>(N,0));
        int mid = N/2;
        board[mid][mid] = board[mid-1][mid-1] = 2;
        board[mid-1][mid] = board[mid][mid-1] = 1;
        
        int x, y, c;
        for(int cnt=0; cnt<M; ++cnt) {
            cin>>x>>y>>c;
            --x; --y;
            board[x][y] = c;
            changeChip(x, y, c);
        } /* for cnt */
        
        int result[2] = {0};
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                if(board[i][j] == 1) { result[0]++; }
                else if(board[i][j] == 2) { result[1]++; }
            } /* for j */
        } /* for i */
        
        cout << "#" << tc << " " << result[0] << " " << result[1] << "\n";
	} /* for tc */
	return 0;
}