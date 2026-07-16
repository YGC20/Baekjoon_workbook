#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;

int solution(int num)
{
    ll n = num;
    int idx = 0;
    int result = 0;
    if(n == 1) {
        return 0;
    }
    
    while(idx < 500) {
        if(n == 1) {
            break;
        }
        
        if(n%2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n++;
        }
        idx++;
    }    
    
    if(n != 1) {
        result = -1;
    }
    else {
        result = idx;
    }
    return result;
}