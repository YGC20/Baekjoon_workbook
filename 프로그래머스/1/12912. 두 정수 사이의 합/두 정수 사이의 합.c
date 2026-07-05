#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b)
{
    int start = a, end = b;
    if(a>b) {
        start = b;
        end = a;
    }
    long long answer = 0;
    for(int i=start; i<=end; ++i) {
        answer+=i;
    }
    return answer;
}