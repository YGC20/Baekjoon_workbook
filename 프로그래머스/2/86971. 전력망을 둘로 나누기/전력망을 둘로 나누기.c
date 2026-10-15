#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols)
{
    int i, j, answer = n;
    int **node = (int**)malloc((n+1) * sizeof(int*));
    for(i=0; i<=n; ++i) { node[i] = (int*)calloc((n+1), sizeof(int)); }
    
    for(i=0; i<wires_rows; ++i) {
        int from = wires[i][0], to = wires[i][1];
        node[from][++node[from][0]] = to;
        node[ to ][++node[ to ][0]] = from;
    }
    
    for(i=0; i<wires_rows; ++i) {
        int from = wires[i][0], to = wires[i][1];
        int visited[105] = {0};
        
        int cnt = 0, top = -1;
        int stk[210] = {}; 
            
        visited[1] = 1;
        stk[++top] = 1;
            
        while(top > -1) {
            int curr = stk[top--]; cnt++;
            for(int w=1; w<=node[curr][0]; ++w) {
                int next = node[curr][w];
                if((from == curr && to == next)
                   || (from == next && to == curr)
                   || visited[next]) { continue; }
                visited[next] = 1;
                stk[++top] = next;
            }
        }

        int diff = ((n-(2*cnt)) > 0) ? (n - (2 * cnt)) : ((2 * cnt) - n);
        if(answer > diff) { answer = diff; }
    }
    return answer;
}