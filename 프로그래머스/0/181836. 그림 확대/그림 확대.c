#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// picture_len은 배열 picture의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* picture[], size_t picture_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int pl = strlen(picture[0]);
    int row = picture_len * k;
    int col  = pl * k;
    
    char** result = (char**)malloc(sizeof(char*)*row);
    int r_idx = 0;
    
    for(int i=0; i<picture_len; i++) {
        char* tmp = (char*)malloc(sizeof(char)*(col+1));
        int c_idx=0;
        
        for(int j=0; j<pl; j++) {
            for(int c=0; c<k; c++) {
                tmp[c_idx++] = picture[i][j];
            }
        }
        tmp[col] = '\0';
        
        for(int r=0; r<k; r++) {
            result[r_idx] = (char*)malloc(sizeof(char)*(col+1));
            strcpy(result[r_idx],tmp);
            r_idx++;
        }
    }
    return result;
}