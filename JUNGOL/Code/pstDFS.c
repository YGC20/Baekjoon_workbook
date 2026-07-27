#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int minDist = 100000000;

void dfs(int** node, unsigned char* visited, int from, int N, int* dist)
{
	visited[from] = 1;

	for (int i = 0; i < N; ++i) {
		if (!visited[i] && node[from][i] != 0) {
			dfs(node, visited, i, N, *dist + node[from][i]);
		}
	}
	*dist += node[from][0];
	if (minDist > *dist) minDist = *dist;
}

int main(void)
{
	int N = 0; (void)scanf("%d", &N);
	unsigned char* visited = (unsigned char*)calloc(N, sizeof(unsigned char));
	int** node = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; ++i) {
		node[i] = (int*)calloc(N, sizeof(int));
		for (int j = 0; j < N; ++j) {
			(void)scanf(" %d", &node[i][j]);
		}
	}

	int dist = 0;
	dfs(node, visited, 0, N, &dist);

	printf("%d\n", minDist);
	return 0;
}
#endif