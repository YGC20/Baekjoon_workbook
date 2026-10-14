#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LEN 55*2

int dx[8] = {-1,1,0,0, 1,-1,-1,1};
int dy[8] = {0,0,-1,1, 1,1,-1,-1};

typedef struct node {
    int r, c, dist;
} Node;

int recBFS(int **recMap, int sx, int sy, int ex, int ey)
{
    Node *que = (Node *)malloc(LEN * LEN * sizeof(Node));
    int front = 0, rear = 0;
    que[rear++] = (Node){sx, sy, 0};
    recMap[sx][sy] += 1;

    while(front < rear) {
        int x = que[front].r, y = que[front].c, d = que[front].dist;
        front++;
        if(ex == x && ey == y) { return d; }

        for(int i=0; i<4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 || nx>=LEN || ny<0 || ny>=LEN) { continue; }
            if(recMap[nx][ny] != 2) { continue; }
            recMap[nx][ny] += 1;
            que[rear++] = (Node){nx, ny, d + 1};
        }
    }
}

// rectangle_row_len은 2차원 배열 rectangle의 행(세로) 길이입니다.
// rectangle_col_len은 2차원 배열 rectangle의 열(가로) 길이입니다.
// rectangle[i][j]는 rectangle의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int solution(int **rectangle, size_t rectangle_row_len, size_t rectangle_col_len,
             int characterX, int characterY, int itemX, int itemY) 
{
    int i, x, y;
    int **boxMap = (int **)malloc(LEN * sizeof(int *));
    for(i=0; i<LEN; ++i) { boxMap[i] = (int *)calloc(LEN, sizeof(int)); }
    
    for(i=0; i<rectangle_row_len; ++i) {
        int leftX = rectangle[i][0]*2, leftY = rectangle[i][1]*2;
        int rightX = rectangle[i][2]*2, rightY = rectangle[i][3]*2;
        for(x=leftX; x<=rightX; ++x) for(y=leftY; y<=rightY; ++y)
        {
            boxMap[x][y] = 1;
        }
    }

    for(x=0; x<LEN; ++x) for(y=0; y<LEN; ++y)
    {
        if(boxMap[x][y] != 1) { continue; }
        int isEdge = 0;
        for(i=0; i<8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0 || nx>=LEN || ny<0|| ny>=LEN) { continue; }
            if(boxMap[nx][ny] == 0) { isEdge = 1; }
        }
        if(isEdge) { boxMap[x][y] = 2; }
    }

    int answer = recBFS(boxMap, characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    for(i=0; i<51; ++i) { free(boxMap[i]); }
    free(boxMap);
    return (answer / 2);
}