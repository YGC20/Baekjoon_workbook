#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// order_len은 배열 order의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* order[], size_t order_len)
{
    const char* list[3] = { "americano", "cafelatte", "anything"};
    
    int sum = 0;
    for(int i=0; i<order_len; i++) {
        for(int j=0; j<3; j++) {
            char* ptr = strstr(order[i], list[j]);
            if(ptr!=NULL) {
                if(j==1) sum+=5000;
                else sum+=4500;
            }
        }
    }
    return sum;
}