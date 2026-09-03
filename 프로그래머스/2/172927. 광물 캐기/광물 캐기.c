#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int diamond, iron, stone;
} Sector;

int compare(const void* a, const void* b)
{
    Sector s1 = *(Sector*)a;
    int ss1 = s1.diamond + s1.iron + s1.stone;
    Sector s2 = *(Sector*)b;
    int ss2 = s2.diamond + s2.iron + s2.stone;
    
    if(s1.diamond != s2.diamond) { return (s1.diamond < s2.diamond) ? 1 : -1; }
    if(s1.iron != s2.iron) { return (s1.iron < s2.iron) ? 1 : -1; }
    if(s1.stone != s2.stone) { return (s1.stone < s2.stone) ? 1 : -1; }
    return 0;
}

int solution(int picks[], size_t picks_len, const char* minerals[], size_t minerals_len)
{
    int i, idx = 0, cnt = 0;
    int allPick = picks[0] + picks[1] + picks[2];
    size_t eml = minerals_len;
    if((size_t)(allPick) * 5 < minerals_len) { eml = (size_t)(allPick) * 5; }
    int len = (eml / 5) + ((eml % 5 != 0) ? 1 : 0);
    if(len == 0) { return 0; }
    
    Sector* sec = (Sector*)malloc(len * sizeof(Sector));
    sec[0].diamond = sec[0].iron = sec[0].stone = 0;
    for(i=0; i<minerals_len; ++i) {
        if(strcmp(minerals[i], "diamond") == 0) { sec[idx].diamond++; }
        else if(strcmp(minerals[i], "iron") == 0) { sec[idx].iron++; }
        else { sec[idx].stone++; }
        
        ++cnt;
        if(cnt == 5) { 
            cnt = 0; ++idx;
            if(idx < len) { sec[idx].diamond = sec[idx].iron = sec[idx].stone = 0; }
        }
    }
    qsort(sec, len, sizeof(Sector), compare);
    
    int power = 0;
    for(i=0; i<len; ++i) {
        if(picks[0] != 0) {
            power += (sec[i].diamond * 1 + sec[i].iron * 1 + sec[i].stone * 1);
            --picks[0];
            continue;
        }
        if(picks[1] != 0) {
            power += (sec[i].diamond * 5 + sec[i].iron * 1 + sec[i].stone * 1);
            --picks[1];
            continue;
        }
        if(picks[2] != 0) {
            power += (sec[i].diamond * 25 + sec[i].iron * 5 + sec[i].stone * 1);
            --picks[2];
        }
    }
    
    free(sec);
    return power;
}