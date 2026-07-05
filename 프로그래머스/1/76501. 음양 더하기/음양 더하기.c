#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len)
{
    int i;
    int sum = 0;
    for(i=0; i<absolutes_len; ++i) {
        if(!signs[i]) {
            absolutes[i]*=-1;
        }
        sum+=absolutes[i];
    }
    return sum;
}