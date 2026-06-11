#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

int main(void)
{
	int N; (void)scanf("%d", &N);
	int** node = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; ++i) {
		node[i] = (int*)calloc(N, sizeof(int));
		for (int j = 0; j < N; ++j) {
			(void)scanf(" %d", &node[i][j]);
			if (i!=j && node[i][j] == 0) node[i][j] = INF;
		}
	}

	for (int m = 0; m < N; ++m) {
		for (int s = 0; s < N; ++s) {
			for (int e = 0; e < N; ++e) {
				if (node[s][e] > (node[s][m] + node[m][e]))
					node[s][e] = node[s][m] + node[m][e];
			}
		}
	}

	int* dp = (int*)calloc((1 << N) * N, sizeof(int));
	for (int i = 0; i < (1 << N) * N; ++i)
		dp[i] = INF;
	dp[1 * N + 0] = 0;

	for (int v = 0; v < (1 << N); ++v) {
		for (int c = 0; c < N; ++c) {
			if (dp[v * N + c] == INF) continue;
			if (!(v >> c & 1)) continue;

			for (int n = 0; n < N; ++n) {
				if (v >> n & 1) continue;
				if (node[c][n] == INF) continue;

				int nv = v | (1 << n);
				if (dp[nv * N + n] > (dp[v * N + c] + node[c][n]))
					dp[nv * N + n] = dp[v * N + c] + node[c][n];
			}
		}
	}

	int dist = INF;
	int a = (1 << N) - 1;
	for (int i = 1; i < N; ++i) {
		if (dp[a * N + 1] != INF && node[i][0] != INF)
			if (dist > dp[a * N + i] + node[i][0])
				dist = dp[a * N + i] + node[i][0];
	}

	printf("%d\n", dist);

	free(dp);
	for (int i = 0; i < N; ++i) {
		free(node[i]);
	} free(node);
	return 0;
}
#endif