#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (100+5)

int M, N;
int sX, sY, sDir, eX, eY, eDir;
int robotMap[MAX_N][MAX_N] = { 0 };
int visited[MAX_N][MAX_N][5] = { 0 };

int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };

typedef struct _node {
	int x, y;	// 위치정보
	int dir;	// 방향
	int cmd;	// 누적 명령 횟수
}Node;

typedef struct _que {
	int front, rear;
	Node qarr[MAX_N * MAX_N * 4];
}Que;

Que Q;

void enqueue(Que* q, Node data)
{
	q->qarr[q->rear++] = data;
}

Node dequeue(Que* q)
{
	return q->qarr[q->front++];
}

int turnLeft(int dir)
{
	if (dir == 1) return 4;
	if (dir == 2) return 3;
	if (dir == 3) return 1;
	if (dir == 4) return 2;
	return 0;
}

int turnRight(int dir)
{
	if (dir == 1) return 3;
	if (dir == 2) return 4;
	if (dir == 3) return 2;
	if (dir == 4) return 1;
	return 0;
}

void inputData(void) {
	(void)scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf(" %d", &robotMap[i][j]);
		}
	}
	(void)scanf("%d %d %d", &sX, &sY, &sDir);
	(void)scanf("%d %d %d", &eX, &eY, &eDir);
}

void printData(void)
{
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%3d", robotMap[i][j]);
		} printf("\n");
	}
}

int robotBFS(void)
{
	Q.front = Q.rear = 0;
	enqueue(&Q, (Node) { sX, sY, sDir, 0 });
	visited[sX][sY][sDir] = 1;

	while (Q.front != Q.rear) {
		Node curr = dequeue(&Q);
		int cx = curr.x, cy = curr.y, cdir = curr.dir;

		if (cx == eX && cy == eY && cdir == eDir) return curr.cmd;

		for (int k = 1; k <= 3; ++k) {
			int nx = cx + dx[cdir] * k;
			int ny = cy + dy[cdir] * k;

			if (nx <= 0 || nx > M || ny <= 0 || ny > N)break;
			if (robotMap[nx][ny] == 1) break;

			if (!visited[nx][ny][cdir]) {
				visited[nx][ny][cdir] = 1;
				enqueue(&Q, (Node) { nx, ny, cdir, curr.cmd + 1 });
			}
		}

		int left = turnLeft(cdir);
		if (!visited[cx][cy][left]) {
			visited[cx][cy][left] = 1;
			enqueue(&Q, (Node) { cx, cy, left, curr.cmd + 1 });
		}

		int right = turnRight(cdir);
		if (!visited[cx][cy][right]) {
			visited[cx][cy][right] = 1;
			enqueue(&Q, (Node) { cx, cy, right, curr.cmd + 1 });
		}
	}
	return -1;
}

int main(void)
{
	inputData();
	int result = robotBFS();
	printf("%d\n", result);
	return 0;
}
#endif