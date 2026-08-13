#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* s) 
{
    int len = -1, mid = 0;
    char* answer;
    while(s[++len] != '\0') {}
    
    int idx = 0;
    mid = len / 2;
    if(len % 2 == 0) { idx = 2; mid--; }
    else { idx = 1; }
    answer = (char*)malloc(idx*sizeof(char));
    for(int i=0; i<idx; ++i) {
        answer[i] = s[mid + i];
    }
    answer[idx] = '\0';
    return answer;
}