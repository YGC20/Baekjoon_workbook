#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cookie_len은 배열 cookie의 길이입니다.
int solution(int cookie[], size_t cookie_len)
{
    int i, maxCookie = 0;
    int aIdx, bIdx;
    int sonA, sonB;
    for(i=0; i<(cookie_len-1); ++i) {
        aIdx = i;
        bIdx = i+1;
        sonA = cookie[aIdx];
        sonB = cookie[bIdx];
        
        while(true) {
            if(sonA == sonB) {
                if(maxCookie < sonA) {
                    maxCookie = sonA;
                }
                --aIdx;
                if(aIdx < 0) {
                    break;
                }
                sonA += cookie[aIdx];
            }
            else if(aIdx > 0 &&sonA < sonB) {
                sonA += cookie[--aIdx];
            }
            else if(bIdx < (cookie_len-1) && sonA > sonB) {
                sonB += cookie[++bIdx];
            }
            else {
                break;
            }
        }
    }
    return maxCookie;
}