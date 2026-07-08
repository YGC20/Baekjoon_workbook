#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int min = 0;
int num = 0;

void backTrack(int** dungeon, int len, int* visited, int tired, int cnt)
{
    if(num<cnt) {
        num = cnt;
    }
    
    for(int i=0; i<len; ++i) {
        if(!visited[i] && dungeon[i][0] <= tired) {
            visited[i] = 1;
            backTrack(dungeon, len, visited, (tired - dungeon[i][1]), cnt + 1);
            visited[i] = 0;
        }
    }
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols)
{
    num = min = 0;
    int* visited = (int*)calloc(dungeons_rows,sizeof(int));
    for(int i=0; i<dungeons_rows; ++i) {
        if(min>dungeons[i][0]) {
            min = dungeons[i][0];
        }
    }
    backTrack(dungeons, dungeons_rows, visited, k, 0);
    free(visited);
    return num;
}