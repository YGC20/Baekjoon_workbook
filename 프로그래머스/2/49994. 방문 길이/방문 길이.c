#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* dirs)
{
    int i, j;
    int result = 0;
    int len = strlen(dirs);
    char* dir = "UDRL";
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    int*** visited = (int***)malloc(11 * sizeof(int**));
    for(i=0; i<11; ++i) {
        visited[i] = (int**)malloc(11 * sizeof(int*));
        for(j=0; j<11; ++j) {
            visited[i][j] = (int*)calloc(4, sizeof(int));
        }
    }
    
    int x, y;
    x = y = 5;
    for(i=0; i<len; ++i) {
        char ch = dirs[i];
        for(j=0; j<4; ++j) {
            if(ch==dir[j]) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(nx<0||nx>=11||ny<0||ny>=11) {
                    continue;
                }
                
                if(!visited[nx][ny][j^1] && !visited[x][y][j]) {
                    visited[nx][ny][j^1] = visited[x][y][j] = 1;
                    result++;
                }
                x = nx; y = ny;
                break;
            }
        }
    }
    return result;
}