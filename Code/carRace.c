#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647

int dist, node;
int pathLen = 0;
int* gapDist;
int* repairTime;
int* race;
int* prev;
int path[101];

void inputData(void)
{
	(void)scanf("%d", &dist);
	(void)scanf("%d", &node);

	gapDist = (int*)calloc(node + 2, sizeof(int));
	for (int i = 0; i < (node + 1); ++i) {
		(void)scanf(" %d", &gapDist[i]);
	}
	repairTime = (int*)calloc(node + 2, sizeof(int));
	for (int i = 1; i <= node; ++i) {
		(void)scanf(" %d", &repairTime[i]);
	}
}

void printData(void)
{
	printf("%d\n", race[node+1]);
	if (pathLen > 0) {
		printf("%d\n", pathLen);
		for (int i = pathLen - 1; i >= 0; --i) {
			printf("%d ", path[i]);
		} printf("\n");
	}
}

void carRace()
{
	race = (int*)calloc(node + 2, sizeof(int));
	prev = (int*)calloc(node + 2, sizeof(int));

	for (int i = 0; i < (node + 2); ++i) {
		race[i] = MAX;
		prev[i] = -1;
	}
	race[0] = 0;

	for (int i = 1; i <= (node + 1); ++i) {
		for (int j = 0; j < i; ++j) {
			int gd = 0;
			for (int d = j; d < i; ++d) {
				gd += gapDist[d];
			}

			if (gd <= dist) {
				if (race[j] != MAX && race[i] > (repairTime[i] + race[j])) {
					race[i] = repairTime[i] + race[j];
					prev[i] = j;
				}
			}
		}
	}

	
	for (int to = node + 1; to != -1; to = prev[to]) {
		if (to != 0 && to != node + 1) {
			path[pathLen++] = to;
		}
	}
}

int main(void)
{
	inputData();
	carRace();
	printData();

	free(gapDist);
	free(repairTime);
	free(race);
	free(prev);
	return 0;
}
#endif