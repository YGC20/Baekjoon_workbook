#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p)
{
    int left, right;
    int tlen = strlen(t);
    int plen = strlen(p);
    
    int answer = 0;
    for(left=0; left<=(tlen - plen); ++left) {
        int idx = 0;
        for(int i=left; i<(left + plen); ++i) {
            if(t[i] > p[idx]) { break; }
            else if(t[i] < p[idx]) { answer++; break; }
            else {
                if(i == (left+plen)-1) { answer++; }
                idx++;
            }
        }
    }
    return answer;
}