#include <stdio.h>
int main(void){
    int N, i;
    int n = 0;
    char text[50][50];
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%s", text[i]);
    char dir_pattern[50];
    while(n<50){
        char temp = text[0][n];
        if(temp=='\0') break;
        for(i=0; i<N; i++)
            if(temp!=text[i][n]) dir_pattern[n] = '?';
        if(dir_pattern[n] != '?') dir_pattern[n] = temp;
        n++;
    }
    dir_pattern[n] = '\0';
    printf("%s\n", dir_pattern);
    return 0;
}