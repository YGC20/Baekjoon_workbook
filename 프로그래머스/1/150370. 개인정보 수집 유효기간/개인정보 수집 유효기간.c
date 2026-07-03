#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int dayCnt(const char* today)
{
    int y, m, d;
    sscanf(today, "%d.%d.%d", &y, &m, &d);
    return (y*12*28 + m*28 + d);
}

// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len)
{
    char type;
    int i, day;
    int todayDay = dayCnt(today);
    
    int termMap[26] = {0};
    for(i=0; i<terms_len; ++i) {
        sscanf(terms[i], "%c %d", &type, &day);
        termMap[type-'A'] = day*28;
    }
    
    int cnt = 0;
    int* termAns = (int*)malloc(sizeof(int)*privacies_len);
    for(i=0; i<privacies_len; ++i) {
        int y, m, d;
        sscanf(privacies[i], "%d.%d.%d %c", &y, &m, &d, &type);
        day = y*12*28 + m*28 + d + termMap[type-'A'];
        if(todayDay>=day) {
            termAns[cnt++] = i+1;
        }
    }
    
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(cnt*sizeof(int));
    for(i=0; i<cnt; ++i) {
        answer[i] = termAns[i];
    }
    free(termAns);
    return answer;
}