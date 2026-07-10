#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len)
{
    int i;
    int result = 0;
    int div = 0;
    
    int cntA = 0, cntB = 0;
    int toppingCntA[10001] = {0};
    int toppingCntB[10001] = {0};
    
    cntA++; toppingCntA[topping[0]]++;
    for(i=1; i<topping_len; ++i) {
        if(toppingCntB[topping[i]] == 0) {
            cntB++;
        }
        toppingCntB[topping[i]]++;
    }
    
    for(i=1; i<topping_len; ++i) {
        if(cntA == cntB) {
            result++;
        }

        if(toppingCntA[topping[i]] == 0) {
            cntA++;
        }
        toppingCntA[topping[i]]++;
        
        toppingCntB[topping[i]]--;
        if(toppingCntB[topping[i]] == 0) {
            cntB--;
        }
    }
    
    return result;
}