#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* s)
{
    int len = strlen(s);
    char* answer = (char*)malloc((len + 1) * sizeof(char));
    
    int idx = 0;
    for(int i=0; i<len; ++i) {
        if(idx%2 == 0 && s[i] >= 'a' && s[i] <='z') {
            answer[i] = (s[i] - 'a') + 'A';
        }
        else if(idx%2 != 0 && s[i] >= 'A' && s[i] <='Z') {
            answer[i] = (s[i] - 'A') + 'a';
        }
        else {
            answer[i] = s[i];
            if(s[i] == ' ') { idx = 0; continue; }
        }
        idx++;
    }
    answer[len] = '\0';
    return answer;
}