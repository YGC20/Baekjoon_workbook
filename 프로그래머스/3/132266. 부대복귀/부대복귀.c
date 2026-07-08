#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// roads_rows는 2차원 배열 roads의 행 길이, roads_cols는 2차원 배열 roads의 열 길이입니다.
// sources_len은 배열 sources의 길이입니다.
int* solution(int n, int** roads, size_t roads_rows, size_t roads_cols, int sources[], size_t sources_len, int destination)
{
    int i;
    int* result = (int*)malloc(sources_len*sizeof(int));
    
    int* cnt = (int*)calloc((n+1),sizeof(int));
    for(i=0; i<roads_rows; ++i) {
        cnt[roads[i][0]]++;
        cnt[roads[i][1]]++;
    }
    
    int** adj = (int**)malloc((n+1)*sizeof(int*));
    for(i=1; i<=n; ++i) {
        adj[i] = (int*)malloc((cnt[i]+1)*sizeof(int));
        adj[i][0] = 0;
    }
    for(i=0; i<roads_rows; ++i) {
        int from = roads[i][0];
        int to = roads[i][1];
        adj[from][++adj[from][0]] = to;
        adj[to][++adj[to][0]] = from;
    }
    free(cnt);
    
    int* dist = (int*)malloc((n+1)*sizeof(int));
    for(i=0; i<=n; ++i) {
        dist[i] = -1;
    }
    
    int* que = (int*)malloc((n+1)*sizeof(int));
    int front = 0, rear = 0;
    que[rear++] = destination;
    dist[destination] = 0;
    
    while(front<rear) {
        int curr = que[front++];
        int currNC = adj[curr][0];
        for(i=1; i<=currNC; ++i) {
            int next = adj[curr][i];
            if(dist[next]==-1) {
                dist[next] = dist[curr]+1;
                que[rear++] = next;
            }
        }
    }
    
    for(i=0; i<sources_len; ++i) {
        result[i] = dist[sources[i]];
    }
    
    for(i=1; i<=n; ++i) {
        free(adj[i]);
    } free(adj);
    free(que);
    free(dist);
    
    return result;
}