#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols)
{
    int start = attacks[0][0];
    int end = attacks[attacks_rows-1][0];
    
    int heal = health;
    int idx = 0, cnt = 0;
    for(int i=start; i<=end; ++i) {
        if(i==attacks[idx][0]) {
            heal -= attacks[idx][1];
            cnt = 0; idx++;
            if(heal<=0) break;
        }
        else {
            if(heal<health) {
                heal += bandage[1];
                if(cnt >= bandage[0]) {
                    heal += bandage[2];
                    cnt = 0;
                }
                if(heal>health) heal = health;
            }
        }
        cnt++;
    }
    if(heal<=0) heal = -1;
    return heal;
}