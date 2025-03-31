#include <stdio.h>
int selfNumberCheck[10000]={0};
int main(void){
    for(int i=1; i<=10000; ++i){
        int num = i;
        int sum = num;
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        if(sum<=10000)
            selfNumberCheck[sum] = 1;
    }
    for(int j=1; j<=10000; ++j)
        if(selfNumberCheck[j]==0)
            printf("%d\n", j);
    return 0;
}