#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s, const char* skip, int index)
{
    int i, j;
    int slen = strlen(s), sklen = strlen(skip);
    char* answer = (char*)malloc((slen+1)*sizeof(char));
    
    for(i=0; i<slen; ++i) {
        char curr = s[i];
        int move = 0;
        
        while(move<index) {
            curr++;
            if(curr>'z') curr = 'a';
            
            bool is_skip = false;
            for(j=0; j<sklen; ++j) {
                if(curr == skip[j]) {
                    is_skip = true;
                    break;
                }
            }
            if(!is_skip) move++;
        }
        answer[i] = curr;
    }
    answer[slen] = '\0';
    return answer;
}