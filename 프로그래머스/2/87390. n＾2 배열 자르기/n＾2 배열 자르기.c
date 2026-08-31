#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right)
{
    int idx = 0;
    long long row, col;
    int* answer = (int*)malloc((right - left + 1) * sizeof(int));
    for(long long i=left; i<=right; ++i) {
        row = i/n;
        col = i%n;
        answer[idx++] = ((row > col) ? row : col) + 1;
    }
    return answer;
}