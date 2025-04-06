#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int main(void){
    int n, c, w[100001];
    scanf("%d%d", &n, &c);
    for(int i=0; i<n; ++i)
        scanf("%d", &w[i]);
    qsort(w, n, sizeof(int), compare);
    int left=0, right=n-1, volunteer=0;
    while(left<=right){
        if((w[left]+w[right])<=c){
            left++;
            right--;
        }
        else{
            right--;
        }
        volunteer++;
    }
    printf("%d", volunteer);
    return 0;
}