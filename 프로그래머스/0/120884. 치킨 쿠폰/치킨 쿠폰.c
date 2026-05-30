#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int chicken)
{
    int result = 0;
    while(chicken>=10) {
        int tmp = chicken/10;
        result += tmp;
        chicken = tmp + (chicken%10);
    }
    return result;
}