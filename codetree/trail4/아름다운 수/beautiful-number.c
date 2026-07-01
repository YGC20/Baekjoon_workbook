#include <stdio.h>

int N, cnt = 0;
int nums[11] = {0};

int isBNum() {
    for(int i=0; i<N; i+=nums[i]) {
        if(i+nums[i]-1 >= N) return 0;
        for(int j=i; j<i+nums[i]; ++j) {
            if(nums[j] != nums[i]) return 0;
        }
    }
    return 1;
}

void bnum(int n)
{
    if(n==N) {
        if(isBNum()) cnt++;
        return;
    }

    for(int i=1; i<=4; ++i) {
        nums[n] = i;
        bnum(n+1);
    }
}

int main() {
    scanf("%d", &N);
    bnum(0);
    printf("%d\n", cnt);
    return 0;
}