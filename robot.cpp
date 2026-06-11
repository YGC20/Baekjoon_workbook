#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int M, N;
int startX, startY, startAzi, distX, distY, distAzi;
vector<vector<int>> path(M, vector<int>(N));

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ startX, startY });

}

void inputData() {
	cin >> M >> N;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			int temp; cin >> temp;
			if (temp == 1) path[i][j] = -1;
			else path[i][j] = temp;
		}
	}
	cin >> startX >> startY >> startAzi;
	cin >> distX >> distY >> distAzi;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	return 0;
}
#endif