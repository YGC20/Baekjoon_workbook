#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char uc;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

typedef struct {
	int x, y;
}Node;

typedef struct {
	int front;
	int rear;
	Node data[1000005];
}Queue;

void init_queue(Queue *q)
{
	q->front = q->rear = -1;
}

int is_empty(Queue* q)
{
	return q->front == q->rear;
}

void enqueue(Queue* q, Node node)
{
	q->data[++q->rear] = node;
}

Node dequeue(Queue* q)
{
	return q->data[++q->front];
}

void bfs(uc** cm, uc** v, Queue* q, int H, int W, int* hp, int* time)
{
	int t = 0;
	while (!is_empty(&q)) {
		Node temp = dequeue(&q);
		int qx = temp.x;
		int qy = temp.y;
		if ((cm[qx][qy] - '0') <= hp) hp++;
		t++;
		if (time > t) time = t;

		for (int i = 0; i < 4; ++i) {
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
				if (v[nx][ny] == 0 && (cm[nx][ny] - '0') <= hp) {
					enqueue(&q, (Node) { nx, ny });
				}
			}
		}
	}
}

int main(void)
{
	int H, W, N; (void)scanf("%d %d %d", &H, &W, &N);
	int startX = 0, startY = 0;
	uc** cheeseMap = (uc**)calloc(H, sizeof(uc*));
	uc** visited = (uc**)calloc(H, sizeof(uc*));
	for (int x = 0; x < H; ++x) {
		cheeseMap[x] = (uc*)calloc(W, sizeof(uc));
		visited[x] = (uc*)calloc(W, sizeof(uc));
		for (int y = 0; y < W; ++y) {
			(void)scanf("%c", &cheeseMap[x][y]);
			if (cheeseMap[x][y] == 'S') {
				startX = x; startY = y;
				visited[x][y] = 1;
			}
			if (cheeseMap[x][y] == 'X') {
				visited[x][y] = 1;
			}
		}
	}

	int time = 1000005;
	int hp = 1;
	static Queue q;
	init_queue(&q);
	enqueue(&q, (Node){ startX, startY });

	bfs(cheeseMap, visited, &q, H, W, &hp, &time);
	printf("%d\n", time);

	return 0;
}
#endif