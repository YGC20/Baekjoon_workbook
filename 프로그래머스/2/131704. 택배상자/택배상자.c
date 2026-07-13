#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// order_len은 배열 order의 길이입니다.
int solution(int order[], size_t order_len)
{
    int i;
    int idx = 0;
    int top = -1;
    int* stack = (int*)malloc(order_len * sizeof(int));
    
    int cnt = 0;
    for(i=1; i<=order_len; ++i) {
        if(i != order[idx]) {
            stack[++top] = i;
        }
        else {
            idx++;
            cnt++;
            while(top != -1 && stack[top] == order[idx]) {
                cnt++;
                idx++;
                top--;
            }
        }
    }
    return cnt;
}