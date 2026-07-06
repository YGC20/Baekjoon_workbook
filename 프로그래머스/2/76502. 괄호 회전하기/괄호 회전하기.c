#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int isRBracket(const char* str, int start, int len)
{
    int i;
    int top = 0;
    char* stack = (char*)malloc(len*sizeof(char));
    
    for(i=0; i<len; ++i) {
        char ch = str[start+i];
        if(top!=0 &&\
           ((ch==']' && stack[top-1]=='[') ||\
            (ch=='}' && stack[top-1]=='{') ||\
            (ch==')' && stack[top-1]=='('))) 
        {
            top--;
            continue;
        }
        stack[top++] = ch;
    }
    free(stack);
    return top;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s)
{
    int i;
    int len = strlen(s);
    char* str = (char*)malloc((2*len)*sizeof(char));
    for(i=0; i<len; ++i) {
        str[i] = str[i+len] = s[i];
    }
    
    int cnt = 0;
    for(i=0; i<len; ++i) {
        if(!isRBracket(str, i, len)) {
            cnt++;
        }
    }
    free(str);
    return cnt;
}