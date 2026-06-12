#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#if 01
#define iMAX (100+2)
#define INF 0x7FFFFFFF
int N;
int topX, topY;
int mount[iMAX][iMAX] = { 0 };
int cost[iMAX][iMAX] = { 0 };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

typedef struct _node {
	int x, y;
}Node;

typedef struct _que {
	int front, rear;
	Node arr[iMAX * iMAX];
}Que;
Que Q;

void initQ(Que* q)
{
	q->front = q->rear = 0;
}

void enqueue(Que* q, Node data)
{
	q->arr[q->rear++] = data;
}

Node dequeue(Que* q)
{
	return q->arr[q->front++];
}

void inputData(void)
{
	(void)scanf("%d", &N);
	(void)scanf("%d %d", &topX, &topY);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf("%d", &mount[i][j]);
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cost[i][j] = INF;
		}
	}
}

void printData(void)
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%d ", mount[i][j]);
		} printf("\n");
	} printf("\n");
}

void mountBFS()
{
	enqueue(&Q, (Node) { topX, topY });
	while (Q.front != Q.rear) {
		Node temp = dequeue(&Q);
		int cx = temp.x, cy = temp.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx > N || ny < 0 || ny > N) continue;
			

			
		}
	}
}

int main(void)
{
	inputData();
	return 0;
}
#endif