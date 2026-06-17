#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int lcm(int a, int b)
{
    int x = a, y = b;
    int t = 0;
    while(y!=0){
        t = y; y = x%y; x = t;
    }
    return ((a/x)*b);
}

// signals_rows는 2차원 배열 signals의 행 길이, signals_cols는 2차원 배열 signals의 열 길이입니다.
int solution(int** signals, size_t signals_rows, size_t signals_cols)
{
    int cycle[6] = { 0 };
    for(int i=0; i<signals_rows; ++i) {
        cycle[i]=signals[i][0]+signals[i][1]+signals[i][2];
    }
    int num = cycle[0];
    for(int i=1; i<signals_rows; ++i) {
        num = lcm(num,cycle[i]);
    }
    
    for(int time = 1; time<=num; ++time) {
        int allYellow = 1;
        for(int i=0; i<signals_rows; ++i) {
            int pos = (time-1)%cycle[i]+1;
            if(((pos<signals[i][0]+1)) || (pos>(signals[i][0]+signals[i][1]))) {
                allYellow = 0;
                break;
            }
        }
        if(allYellow) {
            return time;
        }
    }
    return -1;
}