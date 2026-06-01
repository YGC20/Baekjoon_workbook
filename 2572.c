/**
* 정올
* 회전초밥 (2572)
*/
#if 01
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int N, d, k, c; (void)scanf("%d %d %d %d", &N, &d, &k, &c);

	int* nums = (int*)malloc(sizeof(int) * N);
	bool* visited = (bool*)malloc(sizeof(bool) * d);
	if (nums == NULL || visited == NULL) return -1;

	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", &nums[i]);
	}

	return 0;
}
#endif