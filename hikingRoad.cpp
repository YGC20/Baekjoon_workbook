// 다익스트라 알고리즘 이용
#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int N;
int ax, ay;
vector<vector<int>> mount(N, vector<int>(N));

void bfs()
{
	int dist = 0;
	queue<pair<int, int>> q;
	q.push({ ax, ay });
	vector<vector<bool>> visited(N, vector<bool>(N));
	visited[ax][ay] = true;

	while (!q.empty()) {
		pair<int, int> temp = q.front(); q.pop();
		int x = temp.first;
		int y = temp.second;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visited[nx][ny]) {
					
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mount[i][j];
		}
	}

	
	
	bfs(&q);
	return 0;
}
#endif