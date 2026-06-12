/**
* 1676 : 색종이 (고)
3
3 7
15 7
5 2
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int main(void)
{
	int N; (void)scanf("%d", &N);
	unsigned char whitePapper[MAX][MAX] = { 0 };

	int wpx, wpy;
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d %d", &wpx, &wpy);
		for (int x = wpx; x < (wpx + 10); ++x) {
			for (int y = wpy; y < (wpy + 10); ++y) {
				whitePapper[x][y]++;
			}
		}
	}

	unsigned char lengthMapX[MAX][MAX] = { 0 };
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			if (whitePapper[i][j] >= 1) {
				if (i == 0) lengthMapX[i][j] = 1;
				else lengthMapX[i][j] = lengthMapX[i - 1][j] + 1;
			}
			else {
				lengthMapX[i][j] = 0;
			}
		}
	}

	int maxBox = 0;
	for (int j = 0; j < MAX; ++j) {
		for (int i = 0; i < MAX; ++i) {
			if (lengthMapX[i][j] >= 1) {
				int width = 1;
				for (int w = j - 1; w >= 0; --w) {
					if (lengthMapX[i][w] < lengthMapX[i][j] || lengthMapX[i][w] == 0) break;
					++width;
				}
				for (int w = j + 1; w < MAX; ++w) {
					if (lengthMapX[i][w] < lengthMapX[i][j] || lengthMapX[i][w] == 0) break;
					++width;
				}
				if (maxBox < (width * lengthMapX[i][j])) {
					maxBox = width * lengthMapX[i][j];
				}
			}
		}
	}
	printf("%d\n", maxBox);
	return 0;
}
#endif

/*
	for (int x = 0; x < MAX; ++x) {
		for (int y = 0; y < MAX; ++y) {
			printf("%d", whitePapper[x][y]);
		}printf("\n");
	}printf("\n");
*/