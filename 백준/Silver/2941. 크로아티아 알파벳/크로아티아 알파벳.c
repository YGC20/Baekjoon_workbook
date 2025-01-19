#include <stdio.h>
#include <string.h>
int main(void){
    int i=0, count=0;
    char croatian[101] = {0};
    scanf("%s", croatian);
    while(croatian[i]!='\0'){
        if((croatian[i]=='c' && (croatian[i+1]=='=' || croatian[i+1]=='-')) ||
            croatian[i]=='d' && croatian[i+1]=='-' ||
            croatian[i]=='l' && croatian[i+1]=='j' ||
            croatian[i]=='n' && croatian[i+1]=='j' ||
            croatian[i]=='s' && croatian[i+1]=='=' ||
            croatian[i]=='z' && croatian[i+1]=='=') i++;
        else if(croatian[i]=='d' && croatian[i+1]=='z' && croatian[i+2]=='=') i+=2;
        count++;
        i++;
    }
    printf("%d\n", count);
    return 0;
}