#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int i, int j, int k)
{
    int num = 0;
    int cnt = 0;
    for(num = i; num<=j; ++num) {
        int n = num;
        while(n>0) {
            if(n%10==k) cnt++;
            n/=10;
        }
    }
    return cnt;
}