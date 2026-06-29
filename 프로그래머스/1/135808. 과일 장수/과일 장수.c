#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len)
{
    int i;
    int numCnt[10] = {0};
    for(i=0; i<score_len; ++i) {
        numCnt[score[i]]++;
    }
    int sl = score_len;
    int cnt = 0;
    for(i=k; i>0; --i) {
        int nm = numCnt[i]/m;
        numCnt[i-1] += numCnt[i] % m;
        cnt += (nm * i * m);
    }
    return cnt;
}