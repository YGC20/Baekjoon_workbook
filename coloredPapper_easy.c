/**
* 색종이 (초)
*/
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N; (void)scanf("%d", &N);
	int whitePapper[51][51] = { 0 };
	
	int sx, sy;
	for (int i = 0;i < N; ++i) {
		(void)scanf("%d %d", &sx, &sy);
		printf("%d, %d\n", sx, sy);
		for (int x = sx; x <= (sx + 10); ++x) {
			for (int y = sy; y <= (sy + 10); ++y) {
				whitePapper[x][y]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 0;i < 51;++i) {
		for (int j = 0;j < 51;++j) {
			if (whitePapper[i][j] == 1) cnt++;
			printf("%d ", whitePapper[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", cnt);
	return 0;
}
#endif