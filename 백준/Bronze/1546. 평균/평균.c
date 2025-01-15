#include <stdio.h>
int main(void){
    int N, i, max = 0;
    double avg, score[1000] = {0};
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%le", &score[i]);
        if(score[i]>max) max = score[i];
    }
    for(i=0; i<N; i++) avg += score[i]/max*100;
    printf("%f", avg/N);
    return 0;
}