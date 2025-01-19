#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int main(void){
    int N, i, array[1000000];
    scanf("%d", &N);
    for(i=0;i<N;i++) scanf("%d", &array[i]);
    qsort(array, N, sizeof(int), compare);
    for(i=0;i<N;i++) printf("%d\n", array[i]);
    return 0;
}