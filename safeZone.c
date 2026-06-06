/**
* 안전지대
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int (*arr)[101], char (*v)[101], int N, int x, int y)
{
	v[x][y] = 1;
	for (int i = 0;i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (arr[nx][ny] != 0 && v[nx][ny] == 0) {
				dfs(arr, v, N, nx, ny);
			}
		}
	}
}

int main(void)
{
	int N; (void)scanf("%d", &N);
	int hlm[101][101] = { 0 };

	int hwl = 0;
	for (int i = 0;i < N; ++i) {
		for (int j = 0;j < N; ++j) {
			(void)scanf("%d", &hlm[i][j]);
			if (hwl < hlm[i][j]) hwl = hlm[i][j];
		}
	}

	int maxIsland = 1;
	for (int h = 1; h <= hwl; ++h) {
		char visited[101][101] = { 0 };

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (hlm[i][j] <= h) {
					visited[i][j] = 1;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (hlm[i][j] != 0 && visited[i][j] == 0) {
					dfs(hlm, visited, N, i, j);
					cnt++;
				}
			}
		}
		if (maxIsland < cnt)maxIsland = cnt;
	}

	printf("%d\n", maxIsland);
	return 0;
}
#endif