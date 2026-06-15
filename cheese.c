#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (1000+5)
typedef unsigned char uc;

int H, W, N;
uc cheeseMap[MAX_N][MAX_N] = { 0 };
int visited[MAX_N][MAX_N] = { 0 };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

typedef struct {
	int x, y, dist;
}Node;

int front = 0, rear = 0;
Node que[MAX_N * MAX_N * 4] = { 0 };

void enqueue(Node node)
{
	que[rear++] = node;
}

Node dequeue(void)
{
	return que[front++];
}

void inputData(void)
{
	(void)scanf("%d %d %d", &H, &W, &N);
	char temp[MAX_N] = { 0 };
	for (int h = 1; h <= H; ++h) {
		(void)scanf("%s", temp + 1);
		for (int w = 1; w <= W; ++w) {
			cheeseMap[h][w] = temp[w];
		}
	}

}

void cheeseBFS(void)
{
}

int main(void)
{
	inputData();
	return 0;
}
#endif