#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num, int total)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * num);
    int mid = total / num;
    int midIndex = num / 2;

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
    return answer;
}