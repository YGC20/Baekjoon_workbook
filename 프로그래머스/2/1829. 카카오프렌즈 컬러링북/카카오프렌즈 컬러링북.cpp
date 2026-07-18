#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> vvi;

typedef struct _node
{
    int x, y;
} Node;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int x, int y, int m, int n, vvi& picture, vvi& visited)
{
    int i;
    int color = picture[x][y];
    int cnt = 0;
    queue<Node> que;
    que.push((Node){x, y});
    
    while(!que.empty()) {
        int currX = que.front().x;
        int currY = que.front().y;
        que.pop();
        
        for(i=0; i<4; ++i) {
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];
            
            if(nextX<0 || nextX>=m || nextY<0 || nextY>=n) {
                continue;
            }
            if(picture[nextX][nextY]==color && visited[nextX][nextY]==0) {
                cnt++;
                visited[nextX][nextY] = color;
                que.push((Node){nextX, nextY});
            }
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vvi picture)
{
    int i, j;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vvi visited(m,vector<int>(n,0));
    for(i=0; i<m; ++i) {
        for(j=0; j<n; ++j) {
            if(picture[i][j]!=0 && visited[i][j] == 0) {
                number_of_area++;
                int sooa = bfs(i, j, m, n, picture, visited);
                if(max_size_of_one_area < sooa) {
                    max_size_of_one_area = sooa;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}