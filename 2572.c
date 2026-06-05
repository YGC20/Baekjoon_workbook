/**
* 정올
* 회전초밥 (2572)
* 슬라이딩 기법 이용
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, d, k, c; (void)scanf("%d %d %d %d", &N, &d, &k, &c);

	int* nums = (int*)calloc(N * 2, sizeof(int));
	int* visited = (int*)calloc(d+1, sizeof(int));
	if (nums == NULL || visited == NULL) return -1;

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", &nums[i]);
		nums[i + N] = nums[i];
		if (i < k) {
			visited[nums[i]]++;
			if(visited[nums[i]]==1) cnt++;
		}
	}

	int max = cnt;
	for (int i = k;i < (N * 2);++i) {
		visited[nums[i - k]]--;
		if (visited[nums[i - k]] == 0) cnt--;
		
		visited[nums[i]]++;
		if (visited[nums[i]] == 1) cnt++;

		if (max <= cnt) {
			max = cnt;
			if (visited[c] == 0) max++;
		}
	}
	printf("%d\n", max);
	return 0;
}
#endif