#include <stdio.h>
int main(void){
    int N, x=1, y=1;
    scanf("%d", &N);
    while(1){
        if(N<=y) break;
        y=y+6*x;
        x++;
    }
    if(N==1) printf("1\n");
    else printf("%d\n", x);
    return 0;
}