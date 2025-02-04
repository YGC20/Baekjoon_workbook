#include <stdio.h>
#include <math.h>
int main(void){
    int H, W, N, M;
    scanf("%d %d %d %d",&H, &W, &N, &M);
    printf("%d\n", (int)(ceil((double)H/(N+1))*ceil((double)W/(M+1))));
    return 0;
}