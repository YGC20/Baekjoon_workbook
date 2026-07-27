/**
* 프로그래머스 : 연속된 수의 합
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(int num, int total)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * num);
    int mid = total / num;
    int midIndex = num / 2;

    printf("%d %d\n", mid, midIndex);
    if ((num % 2) == 0) {
        answer[--midIndex] = mid;
        int n = mid;
        for (int i = midIndex - 1; i >= 0; --i) {
            answer[i] = --n;
        }
        for (int i = midIndex + 1; i < num; ++i) {
            answer[i] = ++mid;
        }
    }
    else {
        answer[midIndex] = mid;
        int n = mid;
        for (int i = midIndex - 1; i >= 0; --i) {
            answer[i] = --n;
        }
        for (int i = midIndex + 1; i < num; ++i) {
            answer[i] = ++mid;
        }
    }
    
    for (int i = 0;i < num;++i) {
        printf("%d", answer[i]);
    }printf("\n");
    return answer;
}

int main(void)
{
    solution(3, 12);
    solution(5, 15);
    solution(4, 14);
    solution(5, 5);
    return 0;
}
#endif