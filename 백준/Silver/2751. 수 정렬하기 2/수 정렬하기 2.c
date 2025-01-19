#include <stdio.h>
#include <stdlib.h>
/*
qsort 함수의 선언
qsort는 <stdlib.h> 헤더 파일에 선언되어 있습니다.

void qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));

매개변수
base:   정렬할 배열의 시작 주소.
num:    배열의 요소 개수.
size:   배열의 각 요소 크기(바이트 단위, sizeof(요소)로 계산).
compar: 두 요소를 비교하는 사용자 정의 함수의 포인터.

비교 함수 (compar)
qsort는 정렬을 위해 사용자 정의 비교 함수를 호출합니다.
이 함수는 두 요소의 주소를 입력으로 받아, 다음 값을 반환해야 합니다:
음수 값:    첫 번째 값이 두 번째 값보다 작음.
0:          두 값이 같음.
양수 값:    첫 번째 값이 두 번째 값보다 큼.
*/
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int main(void){
    int N, i, array[1000000];
    scanf("%d", &N);
    for(i=0;i<N;i++) scanf("%d", &array[i]);
    qsort(array, N, sizeof(int), compare);
    for(i=0;i<N;i++) printf("%d\n", array[i]);
    return 0;
}
