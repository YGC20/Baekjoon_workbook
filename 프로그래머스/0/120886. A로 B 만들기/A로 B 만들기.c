#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* before, const char* after)
{
    char alpha[26] = { 0 };
    int blen = strlen(before);
    int alen = strlen(after);
    
    for(int i=0; i<blen; ++i) {
        alpha[before[i]-'a']++;
    }
    for(int i=0; i<alen; ++i) {
        alpha[after[i]-'a']--;
        if(alpha[after[i]-'a']<0) {
            return 0;
        }
    }
    return 1;
}