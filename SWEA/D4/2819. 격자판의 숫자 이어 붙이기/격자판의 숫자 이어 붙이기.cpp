#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> rooms(4, vector<int>(4, 0));
set<int> numbers;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y, int num, int cnt)
{
    if(cnt >= 7) {
        numbers.insert(num);
        return;
    }
    
    for(int i=0; i<4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || nx>=4 || ny<0 || ny>=4) { continue; }
        dfs(nx, ny, num*10+rooms[nx][ny], cnt + 1);
    }
}

int main(int argc, char** argv)
{
	int T; cin>>T;
	for(int tc=1; tc<=T; ++tc)
	{
        string temp;
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                cin >> rooms[i][j];
            } /* for j */
        } /* for i */
        
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                dfs(i, j, rooms[i][j], 1);
            } /* for j */
        } /* for i */
        
        cout << "#" << tc << " " << numbers.size() << "\n";
        numbers.clear();
	}
	return 0;
}