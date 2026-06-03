#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* bin1, const char* bin2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    long long num1 = strtoll(bin1, NULL, 2);
    long long num2 = strtoll(bin2, NULL, 2);
    long long sum = num1 + num2;
    
    if(sum==0) {
        char* result = (char*)malloc(2);
        strcpy(result, "0");
        return result;
    }
    
    long long temp = sum;
    int len = 0;
    while(temp>0) {
        len++;
        temp/=2;
    }
    
    char* result = (char*)malloc(len+1);
    result[len] = '\0';
    
    temp = sum;
    for(int i = len-1; i>=0; --i) {
        result[i] = (temp%2)+'0';
        temp/=2;
    }
    return result;
}