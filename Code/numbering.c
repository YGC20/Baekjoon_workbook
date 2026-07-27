#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char uc;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(uc** nm, uc** v, int x, int y, int N, int* cntR)
{
	v[x][y] = 1;
	(*cntR)++;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (v[nx][ny] == 0 && nm[nx][ny] == 1) {
				dfs(nm, v, nx, ny, N, cntR);
			}
		}
	}
}

int compare(const int* a, const int* b)
{
	return (*(const int*)a - *(const int*)b);
}

int main(void)
{
	int N; (void)scanf("%d", &N);
	uc** numMap = (uc**)calloc(N, sizeof(uc*));
	uc** visited = (uc**)calloc(N, sizeof(uc*));
	int* cntBuild = (int*)calloc(N * N, sizeof(int));

	for (int x = 0; x < N; ++x) {
		numMap[x] = (uc*)calloc(N, sizeof(uc));
		visited[x] = (uc*)calloc(N, sizeof(uc));
		for (int y = 0; y < N; ++y) {
			int temp; (void)scanf("%1d", &temp);
			numMap[x][y] = (uc)temp;
		}
	}

	int cnt = 0;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (visited[x][y] == 0 && numMap[x][y] == 1) {
				int cntR = 0;
				cnt++;
				dfs(numMap, visited, x, y, N, &cntR);
				cntBuild[cnt-1] = cntR;
			}
		}
	}

	qsort(cntBuild, cnt, sizeof(int), compare);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i) {
		printf("%d\n", cntBuild[i]);
	}

	for (int x = 0; x < N; ++x) {
		free(numMap[x]); free(visited[x]);
	}
	free(numMap); free(visited);
	return 0;
}
#endif