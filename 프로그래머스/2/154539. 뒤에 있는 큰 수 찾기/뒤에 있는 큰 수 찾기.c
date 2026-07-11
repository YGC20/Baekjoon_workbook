#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len)
{
    int i;
    int top = -1;
    int* result = (int*)malloc(numbers_len * sizeof(int));
    int* stack = (int*)malloc(numbers_len * sizeof(int));
    for(i=numbers_len-1; i>=0; --i) {
        while(top!=-1 && stack[top]<=numbers[i]) {
            top--;
        }
        
        if(top==-1) {
            result[i] = -1;
        }
        else {
            result[i] = stack[top];
        }
        
        stack[++top] = numbers[i];
    }
    return result;
}