#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// elements_len은 배열 elements의 길이입니다.
int solution(int elements[], size_t elements_len)
{
    int* elm = (int*)calloc(2*elements_len,sizeof(int));
    int llen = 0;
    for(int i=0; i<elements_len; ++i) {
        elm[i] = elm[i+elements_len] = elements[i];
        llen += elements[i]; 
    }
    
    int sum = 0;
    int* nums = (int*)calloc((llen+1),sizeof(int));
    for(int i=0; i<elements_len; ++i) {
        nums[elements[i]] = 1;
    }
    nums[llen] = 1;
    for(int i=1; i<elements_len; ++i) {
        for(int j=0; j<elements_len; ++j) {
            sum = 0;
            for(int k=j; k<(i+j); ++k) {
                sum+=elm[k];
            }
            if(!nums[sum]) {
                nums[sum] = 1;
            }
        }
    }
    
    int cnt = 0;
    for(int i=0; i<=llen; ++i) {
        if(nums[i]) {
            cnt++;
        }
    }
    return cnt;
}