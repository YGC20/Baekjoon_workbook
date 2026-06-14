#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (100+5)

int R, C;
int rs, cs;
char pipeMap[MAX_N][MAX_N] = { 0 };
int visited[MAX_N][MAX_N] = { 0 };

int pipeLine[12][4] = {
	{0,0,0,0}, {0,1,0,1}, {1,0,1,0}, {0,1,1,0},
	{0,0,1,1}, {1,0,0,1}, {1,1,0,0}, {1,1,1,0},
	{0,1,1,1}, {1,0,1,1}, {1,1,0,1}, {1,1,1,1},
};

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

typedef struct _node {
	int x, y;
}Node;

Node que[MAX_N * MAX_N * 4] = { 0 };
int front = 0, rear = 0;

void enqueue(Node data)
{
	que[rear++] = data;
}

Node dequeue(void)
{
	return que[front++];
}

void inputData(void)
{
	(void)scanf("%d %d", &R, &C);
	(void)scanf("%d %d", &rs, &cs);
	char temp[MAX_N] = { 0 };
	for (int r = 1; r <= R; ++r) {
		(void)scanf("%s", temp + 1);
		for (int c = 1; c <= C; ++c) {
			if (temp[c] == 'A' || temp[c] == 'B')
				pipeMap[r][c] = (temp[c] - 'A') + 10;
			else
				pipeMap[r][c] = temp[c] - '0';
		}
	}
}

void printData(void)
{
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			printf("%3d", pipeMap[r][c]);
		} printf("\n");
	} printf("\n");
}

int rmPipeBFS(void)
{
	enqueue((Node) {rs,cs});
	visited[rs][cs] = 1;

	while (front < rear) {
		Node curr = dequeue();
		int currR = curr.x, currC = curr.y;

		for (int i = 0; i < 4; ++i) {
			int currDir = pipeLine[pipeMap[currR][currC]][i];
			if (currDir == 0) continue;

			int nr = currR + dr[i];
			int nc = currC + dc[i];

			if (nr <= 0 || nr > R || nc <= 0 || nc > C) continue;
			if (visited[nr][nc] == 1) continue;

			int nextDir = pipeLine[pipeMap[nr][nc]][(i + 2) % 4];
			if (nextDir == 0) continue;

			visited[nr][nc] = 1;
			enqueue((Node) { nr, nc });
		}
	}

	int cnt = 0;
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (visited[r][c] == 0 && pipeMap[r][c] != 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void)
{
	inputData();
	printData();
	int result = rmPipeBFS();
	printf("%d\n", result);
	return 0;
}
#endif