#include <stdio.h>
int main(void){
    int n, k, coin[101], change[10001];
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &coin[i]);
    for(int i=1; i<=k; ++i) change[i]=10001;
    for(int i=1; i<=n; ++i){
        for(int j=coin[i]; j<=k; j++){
            if(change[j]>change[j-coin[i]]+1) change[j]=change[j-coin[i]]+1;
        }
    }
    if(change[k]==10001) printf("-1\n");
    else printf("%d\n", change[k]);
    return 0;
}