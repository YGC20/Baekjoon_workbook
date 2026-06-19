#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right)
{
    int i, j, count, result = 0;
    for(i=left; i<=right; ++i) {
        count = 0;
        for(j=1; j*j<=i; ++j) {
            if(j*j==i) count+=1;
            else count+=2;
        }
        
        if(count%2==0) result+=i;
        else result-=i;
    }
    return result;
}