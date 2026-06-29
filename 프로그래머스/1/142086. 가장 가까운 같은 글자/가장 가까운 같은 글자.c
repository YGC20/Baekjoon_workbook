#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s)
{
    int i,j;
    int slen = strlen(s);
    int alpha[27] = {0};
    int* answer = (int*)malloc(slen*sizeof(int));
    
    for(i=0; i<slen; ++i) {
        char curr = s[i];
        if(alpha[curr-'a'] != 0) {
            for(j=i-1; j>=0; --j) {
                char front = s[j];
                if(front == curr) break;
            }
            answer[i] = i - j;
        }
        else {
            answer[i] = -1;
        }
        alpha[curr-'a']++;
    }
    return answer;
}