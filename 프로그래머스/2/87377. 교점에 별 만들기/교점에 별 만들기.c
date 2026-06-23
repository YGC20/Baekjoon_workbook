#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N 1000000
typedef long long ll;
typedef struct _pos {
    ll x, y;
} Pos;
Pos posXY[MAX_N] = {0};

// line_rows는 2차원 배열 line의 행 길이, line_cols는 2차원 배열 line의 열 길이입니다.
char** solution(int** line, size_t line_rows, size_t line_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.    
    ll x, y, dir;
    ll maxX = LLONG_MIN, maxY = LLONG_MIN, minX = LLONG_MAX, minY = LLONG_MAX;
    int posIdx = 0;
    for(int i=0; i<(line_rows-1); ++i) {
        for(int j=i+1; j<line_rows; ++j) {
            dir = ((ll)line[i][0]*line[j][1])-((ll)line[j][0]*line[i][1]);
            if(dir==0) continue;
            x = ((ll)line[i][1]*line[j][2])-((ll)line[j][1]*line[i][2]);
            y = ((ll)line[i][2]*line[j][0])-((ll)line[j][2]*line[i][0]);
            if(x%dir!=0 || y%dir!=0) continue;
            x/=dir; y/=dir;
            if(maxX<x) maxX = x;
            if(minX>x) minX = x;
            if(maxY<y) maxY = y;
            if(minY>y) minY = y;
            posXY[posIdx++] = (Pos){x,y};
        }
    }
    
    int row = maxX-minX+1;
    int col = maxY-minY+1;
    char** result = (char**)malloc(col*sizeof(char*));
    for(int i=0; i<col; ++i) {
        result[i] = (char*)malloc((row+1)*sizeof(char));
        for(int j=0; j<row; ++j) {
            result[i][j] = '.';
        }
        result[i][row] = '\0';
    }
    
    for(int i=0; i<posIdx; ++i) {
        ll px = posXY[i].x;
        ll py = posXY[i].y;
        ll r = maxY - py;
        ll c = px - minX;
        result[r][c] = '*';
    }
    return result;
}