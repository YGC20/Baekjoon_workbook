#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* A, const char* B) {
    int len = strlen(A);
    bool checkFlag = false;
    int push = 0;
    for (int i = 0; i < len; ++i) {
        char* temp = (char*)calloc(len+1,sizeof(char));
        strcat(temp, A + (len - i));
        strncat(temp, A, len - i);
        if (strcmp(temp, B) == 0) {
            checkFlag = true;
            push = i;
            free(temp);
            break;
        }
        free(temp);
    }

    return checkFlag ? push : -1;
}