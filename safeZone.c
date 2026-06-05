/**
* 안전지대
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N; (void)scanf("%d", &N);
	int** board = (int**)calloc(N, sizeof(int*));
	for (int i = 0;i < N;++i) {
		board[i] = (int*)calloc(N, sizeof(int));
		for (int j = 0;j < N;++j) {
			(void)scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			printf("%d ", board[i][j]);
		}printf("\n");
	}printf("\n");
	return 0;
}
#endif