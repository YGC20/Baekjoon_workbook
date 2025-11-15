#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> maps(rows,vector<int>(columns));
    vector<int> answer;
    int idx = 0;
    for(int i=0;i<rows;++i)
        for(int j=0;j<columns;++j)
            maps[i][j] = ++idx;
    for(auto q:queries){
        int x1 = q[0]-1, y1 = q[1]-1, x2 = q[2]-1, y2 = q[3]-1;
        int prev = maps[x1][y1], minNum = prev;
        for(int y = y1+1;y<=y2;++y){
            int tmp = maps[x1][y];
            maps[x1][y] = prev;
            prev = tmp;
            minNum = (minNum>prev?prev:minNum);
        }
        for(int x = x1+1;x<=x2;++x){
            int tmp = maps[x][y2];
            maps[x][y2] = prev;
            prev = tmp;
            minNum = (minNum>prev?prev:minNum);
        }
        for(int y = y2-1;y>=y1;--y){
            int tmp = maps[x2][y];
            maps[x2][y] = prev;
            prev = tmp;
            minNum = (minNum>prev?prev:minNum);
        }
        for(int x = x2-1;x>=x1;--x){
            int tmp = maps[x][y1];
            maps[x][y1] = prev;
            prev = tmp;
            minNum = (minNum>prev?prev:minNum);
        }
        answer.push_back(minNum);
    }
    return answer;
}