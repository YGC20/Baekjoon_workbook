/**
* 1675 : 색종이 (중)
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	int N; (void)scanf("%d", &N);
	char whitePapper[101][101] = { 0 };

	int sx, sy;
	for (int i = 0;i < N; ++i) {
		(void)scanf("%d %d", &sx, &sy);
		for (int x = sx; x < (sx + 10); ++x) {
			for (int y = sy; y < (sy + 10); ++y) {
				whitePapper[x][y]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 0;i < 101;++i) {
		for (int j = 0;j < 101;++j) {
			if (whitePapper[i][j] >= 1) {
				for (int d = 0;d < 4;++d) {
					int x = i + dx[d];
					int y = j + dy[d];
					if (x < 0 || x >= 101 || y < 0 || y >= 101 || (whitePapper[x][y] == 0)) {
						cnt++;
					}
				}
			}
		}
	}

	for (int i = 0;i < 101;++i) {
		for (int j = 0;j < 101;++j) {
			printf("%d", whitePapper[i][j]);
		}printf("\n");
	}printf("\n");
	printf("%d\n", cnt);
	return 0;
}
#endif