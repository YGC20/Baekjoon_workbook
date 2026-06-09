/**
* 1676 : 색종이 (고)
3
3 7
15 7
5 2
*/
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N; (void)scanf("%d", &N);
	unsigned char whitePapper[101][101] = { 0 };

	int wpx, wpy;
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d %d", &wpx, &wpy);
		for (int x = wpx; x < (wpx + 10); ++x) {
			for (int y = wpy; y < (wpy + 10); ++y) {
				whitePapper[x][y]++;
			}
		}
	}

	int maxX = 0;
	unsigned char lengthMapX[101][101] = { 0 };
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			if (whitePapper[i][j] >= 1) {
				if (i == 0) lengthMapX[i][j] = 1;
				else lengthMapX[i][j] = lengthMapX[i - 1][j] + 1;
			}
			else {
				lengthMapX[i][j] = 0;
			}
			if (lengthMapX[i][j] > maxX) maxX = lengthMapX[i][j];
		}
	}
	int cntY = 0;
	for (int j = 0; j < 101; ++j) {
		for (int i = 0; i < 101; ++i) {
			if (lengthMapX[i][j] == maxX) cntY++;
		}
	}
	int box1 = maxX * cntY;

	int maxY = 0;
	unsigned char lengthMapY[101][101] = { 0 };
	for (int j = 0; j < 101; ++j) {
		for (int i = 0; i < 101; ++i) {
			if (whitePapper[i][j] >= 1) {
				if (i == 0) lengthMapY[i][j] = 1;
				else lengthMapY[i][j] = lengthMapY[i][j - 1] + 1;
			}
			else {
				lengthMapY[i][j] = 0;
			}
			if (lengthMapY[i][j] > maxY) maxY = lengthMapY[i][j];
		}
	}
	int cntX = 0;
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			if (lengthMapY[i][j] == maxY) cntX++;
		}
	}
	int box2 = maxY * cntX;

	printf("%d\n", (box1 > box2) ? box1 : box2);
	return 0;
}
#endif

/*
	for (int x = 0; x < 101; ++x) {
		for (int y = 0; y < 101; ++y) {
			printf("%d", whitePapper[x][y]);
		}printf("\n");
	}printf("\n");
*/