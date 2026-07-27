#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#if 0
#define MAX_N (12+2)
int N;
int route[MAX_N][MAX_N] = { 0 };
int visited[MAX_N] = { 0 };

void inputData(void)
{
	(void)scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf(" %d", &route[i][j]);
		}
	}
}

void tspDFS(int from)
{
	int to = 0;
	int minDist = 1000001;
	for (int i = 1; i <= N; ++i) {
		if (from != i && minDist > route[from][i] && !(visited[i])) {
			to = i;
			visited[i] = 1;
			minDist = route[from][i];
		}
	}

	tspDFS(to);
}

int main(void)
{
	inputData();
	return 0;
}
#endif