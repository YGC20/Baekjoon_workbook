#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int rows = land.size(), cols = land[0].size();
    vector<vector<int>> id(rows, vector<int>(cols, 0));
    vector<int> clusterSize; clusterSize.push_back(0);
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    int nextId = 1;
    for(int r=0; r<rows; ++r) {
        for(int c=0; c<cols; ++c) {
            if(land[r][c] == 1 && id[r][c] == 0) { 
                queue<pair<int,int>> que;
                que.push({r, c});
                id[r][c] = nextId;

                int cnt = 0;
                while(!que.empty()) {
                    auto [cx, cy] = que.front(); que.pop();
                    cnt++;

                    for(int d=0; d<4; ++d) {
                        int nx = cx + dx[d], ny = cy + dy[d];
                        if(nx<0 || nx>=rows || ny<0 || ny>=cols) { continue; }
                        if(land[nx][ny] == 0 || id[nx][ny] != 0) { continue; }
                        id[nx][ny] = nextId;
                        que.push({nx, ny});
                    }
                }
                clusterSize.push_back(cnt);
                nextId++;
            }
        }
    }
    
    int best = 0;
    for(int c=0; c<cols; ++c) {
        unordered_set<int> seen;
        int total = 0;
        for(int r=0; r<rows; ++r) {
            int cid = id[r][c];
            if(cid != 0 && seen.insert(cid).second) { total += clusterSize[cid]; }
        }
        best = max(best, total);
    }
    
    return best;
}