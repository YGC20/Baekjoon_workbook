#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// keymap_len은 배열 keymap의 길이입니다.
// targets_len은 배열 targets의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* keymap[], size_t keymap_len, const char* targets[], size_t targets_len)
{
    int kl, tl, tlen = 0;
    int kcnt[105] = {0};
    int* answer = (int*)malloc(targets_len*sizeof(int));
    
    for(tl=0; tl<targets_len; ++tl) {
        int sum = 0;
        tlen = strlen(targets[tl]);
        for(int t=0; t<tlen; ++t) {
            memset(kcnt,0,sizeof(kcnt));
            int ckp = 1;
            while(ckp) {
                int allckp = 1;
                for(kl=0; kl<keymap_len; ++kl) { 
                    if(keymap[kl][kcnt[kl]] != '\0') {
                        allckp = 0;
                        if(keymap[kl][kcnt[kl]] == targets[tl][t]) {
                            sum += kcnt[kl] + 1;
                            ckp = 0;
                            break;
                        }
                        else kcnt[kl]++;
                    }  
                }
                if(allckp) {
                    sum = -1;
                    break;
                }
            }
            if(sum==-1) break;
        }
        answer[tl] = sum;
    }
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    return answer;
}