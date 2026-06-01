/**
* 정올
* 도약 (2788)
*/
#if 0

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N; (void)scanf("%d", &N);
    int* nums = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        (void)scanf("%d", &nums[i]);
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < (N - i); ++j) {
            if (nums[j] > nums[j + 1]) {
                int tmp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = tmp;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            int dist = nums[j] - nums[i];

            int minDist = nums[j] + dist;
            int maxDist = nums[j] + 2 * dist;

            for (int k = j + 1; k < N; ++k) {
                if (nums[k] >= minDist && nums[k] <= maxDist) {
                    cnt++;
                }
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}
#endif