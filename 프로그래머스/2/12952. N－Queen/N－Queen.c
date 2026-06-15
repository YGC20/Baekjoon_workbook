#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_N (12+5)

int result = 0;
int col[MAX_N] = { 0 };
int up[MAX_N*MAX_N] = { 0 };
int down[MAX_N*MAX_N] = { 0 };

void nqueenDFS(int row, int N)
{
    if(row>N) { result++; return; }
    for(int i=1; i<=N; ++i) {
        if(col[i] || up[row+i] || down[row-i+N]) continue;
        col[i] = up[row+i] = down[row-i+N] = 1;
        nqueenDFS(row+1, N);
        col[i] = up[row+i] = down[row-i+N] = 0;
    }
}

int solution(int n)
{
    nqueenDFS(1,n);
    return result;
}