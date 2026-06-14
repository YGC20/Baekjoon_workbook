#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (100+5)

int M, N, H;
int tomatoMap[MAX_N][MAX_N][MAX_N] = { 0 };	// [높이][세로/행][가로/열]

int dm[6] = { 0,0,1,-1,0,0 };
int dn[6] = { -1,1,0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };

typedef struct _node {
	int m, n, h;
} Node;

int front = 0, rear = 0;
Node que[MAX_N * MAX_N * MAX_N];

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
	(void)scanf("%d %d %d", &M, &N, &H);
	for (int h = 1; h <= H; ++h) {
		for (int n = 1; n <= N; ++n) {
			for (int m = 1; m <= M; ++m) {
				(void)scanf(" %d", &tomatoMap[h][n][m]);
				if (tomatoMap[h][n][m] == 1) {
					enqueue((Node) { m, n, h });
				}
			}
		}
	}
}

void printData(void)
{
	printf("\n");
	for (int h = 1; h <= H; ++h) {
		for (int n = 1; n <= N; ++n) {
			for (int m = 1; m <= M; ++m) {
				printf("%3d", tomatoMap[h][n][m]);
			} printf("\n");
		} printf("\n");
	} printf("\n");
}

int tomatoBFS(void)
{
	while (front < rear) {
		Node curr = dequeue();
		int currM = curr.m, currN = curr.n, currH = curr.h;

		for (int i = 0; i < 6; ++i) {
			int nm = currM + dm[i];
			int nn = currN + dn[i];
			int nh = currH + dh[i];

			if (nm <= 0 || nm > M || nn <= 0 || nn > N || nh <= 0 || nh > H) continue;
			if (tomatoMap[nh][nn][nm] != 0) continue;

			tomatoMap[nh][nn][nm] = tomatoMap[currH][currN][currM] + 1;
			enqueue((Node) { nm, nn, nh });
		}
	}

	int maxDay = 0;
	for (int h = 1; h <= H; ++h) {
		for (int n = 1; n <= N; ++n) {
			for (int m = 1; m <= M; ++m) {
				if (tomatoMap[h][n][m] == 0) return -1;
				if (maxDay < tomatoMap[h][n][m]) maxDay = tomatoMap[h][n][m];
			}
		}
	}
	return maxDay == 0 ? 0 : maxDay - 1;
}

int main(void)
{
	inputData();
	int result = tomatoBFS();
	printf("%d\n", result);
	return 0;
}
#endif