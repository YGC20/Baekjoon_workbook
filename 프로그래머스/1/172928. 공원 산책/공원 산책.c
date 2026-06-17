#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char dir[4] = {'N','S','W','E'};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int x = 0, y = 0;
    int len = strlen(park[0]);
    for(int i=0; i<park_len; ++i) {
        for(int j=0; j<len; ++j) {
            if(park[i][j]=='S') {
                x = i; y = j;
            }
        }
    }
    
    for(int i=0; i<routes_len; ++i) {
        int d;
        for(d=0; d<4; ++d) {
            if(routes[i][0] == dir[d]) break;
        }
        int num = routes[i][2]-'0';
        
        int nx = x;
        int ny = y;
        int move = 1;
        for(int j=1; j<=num; ++j) {
            nx += dx[d];
            ny += dy[d];
            
            if(nx<0 || nx>=park_len || ny<0 || ny>=len || park[nx][ny]=='X') {
                move = 0; break;
            }
        }
        if(move) {
            x = nx; y = ny;
        }
    }
    int* result = (int*)malloc(sizeof(int)*2);
    result[0] = x; result[1] = y;
    return result;
}