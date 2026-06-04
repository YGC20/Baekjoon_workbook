/*
* 바이러스
*/
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void dfs(char (*graph)[101], char* visited, int n, int from)
{
	for (int i = 1;i <= n;++i) {
		if (graph[from][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			dfs(graph, visited, n, i);
		}
	}
}

int main(void)
{
	int node; (void)scanf("%d", &node);
	int lines; (void)scanf("%d", &lines);

	char graph[101][101] = { 0 };
	char visited[101] = { 0 };

	int from, to;
	for (int i = 0;i < lines; ++i) {
		(void)scanf("%d %d", &from, &to);
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	dfs(graph, visited, node, 1);
	int result = 0;
	for (int i = 2;i <= node;++i) {
		if (visited[i] != 0) result++;
	}

	printf("%d", result);
	return 0;
}
#endif