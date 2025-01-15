#include <stdio.h>
int main(void){
    int N, count=0;
    scanf("%d", &N);
    while(N>=0){
        if(N%5 == 0){
            count+=N/5;
            printf("%d", count);
            return 0;
        }
        N-=3;
        count++;
    }
    printf("-1");
    return 0;
}