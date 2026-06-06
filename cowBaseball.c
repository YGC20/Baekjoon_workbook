/**
소들의 야구 (Cow Baseball)
Farmer John의 소 N마리(3 <= N <= 1000)가 한 줄로 서 있으며, 각각 수직선 위의 서로 다른 위치에 있습니다. 
그들은 이웃 농장의 소들과 벌일 중요한 경기를 준비하기 위해 야구공을 주고받는 연습을 하고 있습니다.
Farmer John이 지켜보는 동안, 그는 세 마리의 소 (X, Y, Z)로 이루어진 그룹이 두 번의 성공적인 던지기를 완료하는 것을 관찰합니다. 
소 X는 자신의 오른쪽에 있는 소 Y에게 공을 던지고, 그 다음 소 Y는 자신의 오른쪽에 있는 소 Z에게 공을 던집니다. 
Farmer John은 두 번째 던지기의 거리가 첫 번째 던지기의 거리 이상이며, 첫 번째 던지기 거리의 두 배를 넘지 않는다는 것을 확인합니다. 
Farmer John이 지켜보았을 가능성이 있는 소 삼중쌍 (X, Y, Z)의 개수를 세어 주세요.

1번째 줄: 소의 수 N
2번째 줄부터 1+N번째 줄까지: 각 줄에는 소 한 마리의 정수 위치가 들어 있습니다 (0 부터 100,000,000 사이의 정수).

1번째 줄: 소 삼중쌍 (X, Y, Z)의 개수. 
여기서 Y는 X의 오른쪽에 있고, Z는 Y의 오른쪽에 있으며, Y에서 Z까지의 거리는 XY 이상 2XY 이하입니다 (양 끝값 포함). 
이때 XY는 X에서 Y까지의 거리를 의미합니다.

5
3
1
10
7
4
*/

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return ((*(int*)a > *(int*)b) - (*(int*)b > *(int*)a));
}

int main(void)
{
	int N; (void)scanf("%d", &N);
	int* pos = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", &pos[i]);
	}
	qsort(pos, N, sizeof(int), compare);

	int cnt = 0;
	for (int i = 0; i < (N - 1); ++i) {
		for (int j = i + 1; j < N; ++j) {
			int dist = pos[j] - pos[i];

			int minDist = dist;
			int maxDist = 2 * dist;

			for (int k = j + 1; k < N; ++k) {
				int secondDist = pos[k] - pos[j];
				if (secondDist >= minDist && secondDist <= maxDist) {
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
#endif
