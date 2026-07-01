#include <stdio.h>
int K, N;
int nums[9] = {0};

void seq(int n)
{
    if(n>=N) {
        for(int j = 0; j<N; ++j) {
            printf("%d ", nums[j]);
        } printf("\n");
        return;
    }
    for(int i=1; i<=K; ++i) {
        nums[n] = i;
        seq(n+1);
    }
}

int main(void) {
    scanf("%d %d", &K, &N);
    seq(0);
    return 0;
}