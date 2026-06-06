/**
* 1676 : 색종이 (고)
*/
#if 0
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

	for (int x = 0; x < 101; ++x) {
		for (int y = 0; y < 101; ++y) {
			printf("%d", whitePapper[x][y]);
		}printf("\n");
	}printf("\n");

	return 0;
}
#endif