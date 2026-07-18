#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b)
{
    int i;
    int monthToDay[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* weeks[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    char* answer = (char*)malloc(3 * sizeof(char));
    
    for(i=1; i<a; ++i) {
        b += monthToDay[i];
    }
    
    answer = weeks[b%7];
    return answer;
}