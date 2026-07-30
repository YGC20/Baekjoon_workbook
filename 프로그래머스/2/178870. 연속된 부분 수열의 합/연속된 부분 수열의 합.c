#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sequence_len은 배열 sequence의 길이입니다.
int* solution(int sequence[], size_t sequence_len, int k)
{
    int i;
    int minLen = sequence_len + 10;
    int* result = (int*)malloc(2 * sizeof(int));
    
    int sum = sequence[0];
    int left = 0, right = 0;
    while(right < sequence_len) {
        if(sum < k) {
            right++;
            if(right < sequence_len) {
                sum += sequence[right];
            }
        }
        else if(sum >= k) {
            int len = right - left + 1;
            if(minLen > len && sum == k) {
                minLen = len;
                result[0] = left; result[1] = right;   
            }
            sum -= sequence[left++];
        }
    }
    
    return result;
}