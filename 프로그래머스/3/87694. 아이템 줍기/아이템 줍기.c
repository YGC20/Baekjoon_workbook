#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_N (55*2)

int recMap[MAX_N][MAX_N] = {0};

int dx[8] = {-1,1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,1,-1,1,-1};

int front, rear;
typedef struct _node {
    int x, y, dist;
} Node;
Node que[MAX_N*MAX_N*MAX_N] = {0};

void enqueue(Node data)
{
    que[rear++]=data;
}
Node dequeue(void)
{
    return que[front++];
}

int recBFS(int cx, int cy, int ix, int iy)
{
    front = rear = 0;
    enqueue((Node){cx,cy,0});
    recMap[cx][cy]+=1;
    
    while(front<rear){
        Node curr = dequeue();
        int ccx = curr.x, ccy = curr.y;
        if(ccx==ix && ccy==iy) return curr.dist;
        for(int i=0; i<4; ++i){
            int nx = ccx+dx[i];
            int ny = ccy+dy[i];
            
            if(nx<0||nx>=MAX_N||ny<0||ny>=MAX_N) continue;
            if(recMap[nx][ny]!=2) continue;
            recMap[nx][ny] = 3;
            enqueue((Node){nx,ny,curr.dist+1});
        }
    }
    return -1;
}
// rectangle_row_len은 2차원 배열 rectangle의 행(세로) 길이입니다.
// rectangle_col_len은 2차원 배열 rectangle의 열(가로) 길이입니다.
// rectangle[i][j]는 rectangle의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int solution(int **rectangle, size_t rectangle_row_len, size_t rectangle_col_len, int characterX, int characterY, int itemX, int itemY) 
{
    memset(recMap, 0, sizeof(recMap));
    // 주어진 사각형을 맵에 그리는 과정
    int rlx, rly, rrx, rry;
    for(int i=0; i<rectangle_row_len; ++i) {
        rlx = rectangle[i][0]*2; rly = rectangle[i][1]*2;
        rrx = rectangle[i][2]*2; rry = rectangle[i][3]*2;
        for(int x=rlx; x<=rrx; ++x) {
            for(int y=rly; y<=rry; ++y) {
                recMap[x][y] = 1;
            }
        }
    }
    
    // 사각형들을 그린 맵의 가장자리를 찾아서 2로 가장자리만 표시
    for(int i=0; i<MAX_N; ++i) {
        for(int j=0; j<MAX_N; ++j) {
            if(recMap[i][j]!=1) continue;
            
            int check = 0;
            for(int k=0; k<8; ++k){
                int ni=i+dx[k];
                int nj=j+dy[k];
                
                if(ni<0||ni>=MAX_N||nj<0||nj>=MAX_N) continue;
                if(recMap[ni][nj]==0) check=1;
            }
            if(check) recMap[i][j] += 1;
        }
    }
    
    int result = recBFS(characterX*2, characterY*2, itemX*2, itemY*2)/2;
    return result;
}