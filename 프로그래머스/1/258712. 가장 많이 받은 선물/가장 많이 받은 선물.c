#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// friends_len은 배열 friends의 길이입니다.
// gifts_len은 배열 gifts의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len)
{
    int i, j;
    int** giftCard = (int**)malloc((friends_len+1) * sizeof(int*));
    for(i=0; i<(friends_len+1); ++i) {
        giftCard[i] = (int*)calloc((friends_len+1), sizeof(int));
    }
    
    for(i=0; i<gifts_len; ++i) {
        char temp[100];
        strcpy(temp, gifts[i]);
        char* from = strtok(temp, " ");
        char* to = strtok(NULL, " ");
        
        int fromIndex = -1, toIndex = -1;
        for(j=0; j<friends_len; ++j) {
            if(fromIndex == -1 && strcmp(from, friends[j]) == 0) {
                fromIndex = j + 1;
            }
            if(toIndex == -1 && strcmp(to, friends[j]) == 0) {
                toIndex = j + 1;
            }
        }
        
        giftCard[fromIndex][0]++;
        giftCard[0][toIndex]++;
        giftCard[fromIndex][toIndex]++;
    }
    
    int* nextGift = (int*)calloc(friends_len + 1, sizeof(int));
    for(i=1; i<(friends_len+1); ++i) {
        for(j=i+1; j<(friends_len+1); ++j) {
            if(giftCard[i][j] == giftCard[j][i]) {
                int gcf = giftCard[i][0] - giftCard[0][i];
                int gct = giftCard[j][0] - giftCard[0][j];
                
                if(gcf != gct) {
                    (gcf > gct)?nextGift[i]++:nextGift[j]++;
                }
            }
            else {
                (giftCard[i][j] > giftCard[j][i])?nextGift[i]++:nextGift[j]++;
            }
        }
    }
    
    int maxGift = 0;
    for(i=0; i<(friends_len+1); ++i) {
        if(maxGift < nextGift[i]) {
            maxGift = nextGift[i];
        }
    }
    
    for(i=0; i<(friends_len+1); ++i) {
        free(giftCard[i]);
    }
    free(giftCard);
    free(nextGift);
    return maxGift;
}