#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv)
{
    unordered_map<char, int> dirCmd = {{'L', 0},{'R', 1},{'U', 2},{'D', 3}};
    unordered_map<char, int> dirTank = {{'<', 0},{'>', 1},{'^', 2},{'v', 3}};
    static const char tank[4] = {'<', '>', '^', 'v'};
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    int T, H, W, N; cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        cin >> H >> W;
        vector<string> board(H);
        for(int i=0; i<H; ++i) { cin >> board[i]; }

        int x, y, dir;
        for(int i=0; i<H; ++i) {
            for(int j=0; j<W; ++j) {
                char tank = board[i][j];
                if(tank == '<' || tank == '>' || tank == '^' || tank == 'v') {
                    x = i; y = j; dir = dirTank[tank];
                }
            }
        }

        cin >> N;
        string command; cin >> command;
        for(auto& cmd : command) {
            int nx, ny;
            if(cmd == 'S') {
                nx = x, ny = y;
                while((nx>=0 && nx<H && ny>=0 && ny<W) && board[nx][ny] != '#') {
                    if(board[nx][ny] == '*') { board[nx][ny] = '.'; break; }
                    nx += dx[dir]; ny += dy[dir];
                }
            } else {
                int newdir = dirCmd[cmd];
                nx = x + dx[newdir]; ny = y + dy[newdir];
                if(nx<0 || nx>=H || ny<0 || ny>=W || board[nx][ny] != '.') {
                    dir = newdir;
                    board[x][y] = tank[newdir];
                    continue; 
                }
                board[x][y] = '.';
                x = nx; y = ny; dir = newdir;
                board[x][y] = tank[dir];
            }
        }
        
        cout << "#" << tc << " ";
        for(int i = 0; i < H; ++i) {
            if(i > 0) cout << "\n";
            cout << board[i];
        }
        cout << "\n";
    }
    return 0;
}