#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#if 0
#define iMAX (100+2)
#define INF 0x7FFFFFFF
int N;
int topX, topY;
int mount[iMAX][iMAX] = { 0 };
int cost[iMAX][iMAX] = { 0 };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

typedef struct _node {
	int x, y, cost;
}Node;

typedef struct _que {
	int size;
	Node arr[iMAX * iMAX];
}Que;
Que Q;

void swap(Node* a, Node* b) { Node t = *a; *a = *b; *b = t; }

void enqueue(Que* q, Node data)
{
	q->arr[++(q->size)] = data;
	int i = q->size;
	while (i > 1 && q->arr[i].cost < q->arr[i / 2].cost) {
		swap(&q->arr[i], &q->arr[i / 2]);
		i /= 2;
	}
}

Node dequeue(Que* q)
{
	Node temp = q->arr[1];
	q->arr[1] = q->arr[(q->size)--];
	int i = 1;
	while (1) {
		int left = i * 2, right = i * 2 + 1, smallest = i;
		if (left <= q->size && q->arr[left].cost < q->arr[smallest].cost) smallest = left;
		if (right <= q->size && q->arr[right].cost < q->arr[smallest].cost) smallest = right;
		if (smallest == i) break;
		swap(&q->arr[i], &q->arr[smallest]);
		i = smallest;
	}
	return temp;
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

	for (int i = 0; i <= N+1; ++i) {
		for (int j = 0; j <= N+1; ++j) {
			cost[i][j] = INF;
		}
	}
}

void printData(void)
{
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (cost[i][j] == INF) printf("INF ");
			else printf("%3d ", cost[i][j]);
		} printf("\n");
	} printf("\n");
}

int mountBFS()
{
	cost[topX][topY] = 0;
	enqueue(&Q, (Node) { topX, topY, 0 });
	while (Q.size > 0) {
		Node temp = dequeue(&Q);
		int cx = temp.x, cy = temp.y, cc = temp.cost;

		if (cc > cost[cx][cy]) continue;
		if (cx == 0 || cx == N + 1 || cy == 0 || cy == N + 1) return cc;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx > N+1 || ny < 0 || ny > N+1) continue;

			int dist = mount[nx][ny] - mount[cx][cy];
			int nc;

			if (dist == 0) nc = cc;
			else if (dist > 0) nc = cc + dist;
			else nc = cc + dist * dist;

			if (nc < cost[nx][ny]) {
				cost[nx][ny] = nc;
				enqueue(&Q, (Node) { nx, ny, nc });
				printData();
			}

		}
	}
}

int main(void)
{
	inputData();
	int result = mountBFS();
	printf("%d\n", result);
	return 0;
}
#endif