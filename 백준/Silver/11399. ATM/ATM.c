#include <stdio.h>
int sort(int arr[], int n){
    int i, j, temp;
    for(i=0;i<n-1;++i){
        for(j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return 0;
}
int main(void){
    int N, i;
    scanf("%d", &N);
    int timeScheduling[N];
    for(i=0; i<N; ++i)
        scanf("%d", &timeScheduling[i]);
    sort(timeScheduling,N);
    int sum=0;
    int total=0;
    for(i=0;i<N;++i){
        sum+=timeScheduling[i];
        total+=sum;
    }
    printf("%d\n", total);
    return 0;
}