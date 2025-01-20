#include <stdio.h>
int main(void){
    int N, i, sum=0;
    scanf("%d", &N);
    for(i=0;i<N;i++){
        int n;
        scanf("%1d", &n);
        sum+=n;
    }
    printf("%d\n", sum);
    return 0;
}