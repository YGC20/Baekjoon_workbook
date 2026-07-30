#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _node {
    int x; int y;
} Node;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void setMap(const char* maps[], int* rdm[], size_t n, size_t m,
            Node* start, Node* end, Node* lever)
{
    int i, j;
    for(i=0; i<n; ++i) {
        for(j=0; j<m; ++j) {
            char ch = maps[i][j];
            if(ch == 'S') {
                start->x = i; start->y = j;
            }
            else if(ch == 'E') {
                end->x = i; end->y = j;
            }
            else if(ch == 'L') {
                lever->x = i; lever->y = j;
            }
            
            if(ch == 'X') {
                rdm[i][j] = -1;
            }
            else {
                rdm[i][j] = 0;
            }
        }
    }
}

int bfs(int* vMap[], size_t n, size_t m, 
        const Node* start, const Node* end)
{
    int i;
    Node* que = (Node*)malloc(n * m * sizeof(Node));
    int front = 0, rear = 0;
    que[rear++] = *start;
    vMap[start->x][start->y] = 1;
    
    while(front < rear) {
        Node temp = que[front++];
        if(end->x==temp.x && end->y==temp.y) {
            break;
        }
        
        for(i=0; i<4; ++i) {
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vMap[nx][ny]!=0) continue;
            
            vMap[nx][ny] = vMap[temp.x][temp.y] + 1;
            que[rear++] = (Node){nx, ny};
        }
    }
    
    free(que);
    return (vMap[end->x][end->y] - 1);
}

int solution(const char* maps[], size_t maps_len)
{
    int i;
    int SLRoute, LERoute;
    int n = maps_len;
    int m = strlen(maps[0]);
    
    Node start, end, lever;
    int** vMap = (int**)malloc(n * sizeof(int*));
    for(i=0; i<n; ++i) {
        vMap[i] = (int*)malloc(m * sizeof(int));
    }
    setMap(maps, vMap, n, m, &start, &end, &lever);
    SLRoute = bfs(vMap, n, m, &start, &lever);
    
    setMap(maps, vMap, n, m, &start, &end, &lever);
    LERoute = bfs(vMap, n, m, &lever, &end);
    
    for(i=0; i<n; ++i) {
        free(vMap[i]);
    }
    free(vMap);
    
    if(SLRoute != -1 && LERoute != -1) {
        return (SLRoute + LERoute);
    }
    return -1; 
}