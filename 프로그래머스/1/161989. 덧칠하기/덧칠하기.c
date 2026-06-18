#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// section_len은 배열 section의 길이입니다.
int solution(int n, int m, int section[], size_t section_len)
{
    int sec = 0, result = 0, cover = 0;
    for(int i=0; i<section_len; ++i) {
        sec = section[i];
        if(sec>cover) {
            result++;
            cover = sec + m - 1;
        }
    }
    return result;
}