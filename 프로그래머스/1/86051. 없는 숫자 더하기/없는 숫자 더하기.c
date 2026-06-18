#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len)
{
    int i = 0, result = 0;
    int nums[10] = { 0 };
    for(i=0; i<numbers_len; ++i) {
        nums[numbers[i]] = 1;
    }
    for(i=0; i<10; ++i) {
        if(!nums[i]) result+=i;
    }
    return result;
}