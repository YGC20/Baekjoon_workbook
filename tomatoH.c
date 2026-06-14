#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#if 0
#define MAX_N (1000+5)
int M, N;
int boxs[MAX_N][MAX_N] = { 0 };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

typedef struct _node {
	int x, y;
	int day;
} node;

typedef struct _que {
	int front, rear;
	node arr[MAX_N * MAX_N + 5];
} Que;

Que q;

void init(Que* q)
{
	q->front = q->rear = 0;
}

void enqueue(Que* q, node data)
{
	q->arr[q->rear++] = data;
}

node dequeue(Que* q)
{
	return q->arr[q->front++];
}

void inputData(void)
{
	(void)scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			(void)scanf(" %d", &boxs[i][j]);
		}
	}
}

void printData(void)
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			printf("%d ", boxs[i][j]);
		} printf("\n");
	} printf("\n");
}

int tomatoBFS(void)
{
	init(&q);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (boxs[i][j] == 1)
				enqueue(&q, (node) { i, j, 0 });
		}
	}

	int day = 0;
	while (q.front != q.rear) {
		node temp = dequeue(&q);
		int cx = temp.x, cy = temp.y;
		day = temp.day;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
				if (boxs[nx][ny] == 0) {
					boxs[nx][ny] = 1;
					enqueue(&q, (node) { nx, ny, day + 1 });
				}
			}
		}
	}
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (boxs[i][j] == 0)
				return -1;
		}
	}

	return day;
}

int main(void)
{
	inputData();
	int days = tomatoBFS();
	printf("%d\n", days);
	return 0;
}
#endif