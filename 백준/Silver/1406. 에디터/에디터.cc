#include <stdio.h>
#include <string.h>
int main(void){
    int M, i, sl1, sl2, sl3;
    char str1[1000000], str2[1000000];
    scanf("%s", str1);
    scanf("%d", &M);
    sl1=strlen(str1),sl2=strlen(str2);
    for(i=0;i<M;i++){
        char ch1, ch2;
        if(scanf(" %c", &ch1)==1)
            if(ch1=='P') scanf(" %c", &ch2);
        if(ch1=='L' && sl1>0){
            str2[sl2++]=str1[--sl1];
            str1[sl1]='\0';
        }
        else if(ch1=='D' && sl2>0){
            str1[sl1++]=str2[--sl2];
            str2[sl2]='\0';
        }
        else if(ch1=='B' && sl1>0){
            str1[--sl1]='\0';
        }
        else if(ch1=='P'){
            str1[sl1++]=ch2;
        }
    }
    sl3=sl2;
    for(i=0;i<sl2;i++)
        str1[sl1+i]=str2[--sl3];
    printf("%s\n",str1);
    return 0;
}