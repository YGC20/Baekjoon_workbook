#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> apartments(N, vector<int>(N, 0));
    for(int i=0; i<N; ++i) {
        string temp; cin >> temp;
        for(int j=0; j<N; ++j) {
            apartments[i][j] = temp[j] - '0';
        }
    }

    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    queue<pair<int,int>> que;
    vector<int> result;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(apartments[i][j] == 1) {
                int area = 0;
                que.push({i, j});
                apartments[i][j]++;
                while(!que.empty()) {
                    auto [x, y] = que.front(); que.pop();
                    area++;
                    for(int k=0; k<4; ++k) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if(nx<0 || ny<0 || nx>=N || ny>=N) { continue; }
                        if(apartments[nx][ny] != 1) { continue; }
                        apartments[nx][ny]++;
                        que.push({nx, ny});
                    }
                }
                result.push_back(area);
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto as : result) { cout << as << "\n"; }
    return 0;
}