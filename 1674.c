/**
* 1674 : 색종이 (초)
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
			if (whitePapper[i][j] == 0) cnt++;
		}
	}
	printf("%d\n", (101*101)-cnt);
	return 0;
}
#endif