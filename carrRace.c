#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int dist, node;
	(void)scanf("%d", &dist);
	(void)scanf("%d", &node);

	int* nodeDist = (int*)calloc(node + 1, sizeof(int));
	int* nodeTime = (int*)calloc(node, sizeof(int));
	int* nodeDistSum = (int*)calloc(node, sizeof(int));

	for (int i = 0; i < (node + 1); ++i) {
		(void)scanf("%d", &nodeDist[i]);
		if (i == 0) nodeDistSum[i] = nodeDist[i];
		else nodeDistSum[i] = nodeDist[i] + nodeDist[i - 1];
	}
	for (int i = 0; i < node; ++i) {
		(void)scanf("%d", &nodeTime[i]);
	}

	for (int i = 0; i < node; ++i) {
		for (int j = i + 1; j < (node + 1); ++j) {

		}
	}
	return 0;
}
#endif