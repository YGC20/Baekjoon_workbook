#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* phone_number)
{
    int i;
    int len = strlen(phone_number);
    char* result = (char*)malloc((len + 1)*sizeof(char));
    for(i=0; i<(len-4); ++i) {
        result[i] = '*';
    }
    for(i=(len-4); i<len; ++i) {
        result[i] = phone_number[i];
    }
    result[len] = '\0';
    return result;
}